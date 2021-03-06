#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake, RTPI_ControlPanel *_controlPanel) {
  this->robotIO = _robotIO;
  this->input = _input;
  this->drivetrain = _drivetrain;
  this->intake = _intake;
  this->storage = _storage;
  this->outtake = _outtake;
  this->controlPanel = _controlPanel;
}

//Drivetrain

void RTPI_ManualFunctions::DriveRL() {
  drivetrain->Drive(input->driver->GetRawAxis(3) - input->driver->GetRawAxis(2), input->driver->GetRawAxis(0));
}

void RTPI_ManualFunctions::DriveFPS() {
  drivetrain->Drive(input->driver->GetRawAxis(1), input->driver->GetRawAxis(4));
}

void RTPI_ManualFunctions::ManualDrive() {
  if(robotIO->driveMode == ROCKET_LEAGUE_DRIVE) {
    this->DriveRL();
  }
  else if(robotIO->driveMode == FIRST_PERSON_SHOOTER_DRIVE) {
    this->DriveFPS();
  }
}

void RTPI_ManualFunctions::UpdateDriveMode() {
  if(input->driverPOVLeft->Get()) {
    robotIO->driveMode = ROCKET_LEAGUE_DRIVE;
  }
  else if(input->driverPOVRight->Get())  {
    robotIO->driveMode = FIRST_PERSON_SHOOTER_DRIVE;
  }
}

//Intake:

void RTPI_ManualFunctions::ManualIntake() {
  //Spin Cylinder
  if(input->navigator->GetRawButton(5)) {
    this->intake->SpinIntake(robotIO->intakeSpeed);
  }
  else if (input->navigator->GetRawButton(6)) {
    this->intake->SpinIntake(-robotIO->intakeSpeed);
  }
  else {
    this->intake->SpinIntake(0);
  }
  

  //Move Intake Piston
  //Change State Detection

  robotIO->intakeBState0 = input->navigatorPOVLeft->Get();

  if(robotIO->intakeBState0 != robotIO->lastIntakeBState0) {
    if(robotIO->intakeBState0) {
      if(!robotIO->intakePState0) {
        this->intake->movePiston(DoubleSolenoid::Value::kForward);
        robotIO->intakePState0 = 1;
      }
      else if(robotIO->intakePState0) {
        this->intake->movePiston(DoubleSolenoid::Value::kReverse);
        robotIO->intakePState0 = 0;
      }
    }
    robotIO->lastIntakeBState0 = robotIO->intakeBState0;
  }
}

//Outtake:

void RTPI_ManualFunctions::ManualShooting(){
    if(input->navigator->GetRawButton(6)){
      this->outtake->Load(1);
    }
    else{
      this->outtake->Load(0);
    }
    double shootForward = input->navigator->GetRawAxis(3);
    double shootBackward = input->navigator->GetRawAxis(2);
    double shoot = shootForward - shootBackward;
    this->outtake->Shoot(shoot);
  }

//Storage:

void RTPI_ManualFunctions::ManualRevolver() {
  this->storage->SpinRevolver(input->navigator->GetRawAxis(0));
}
/*
void RTPI_ManualFunctions::ManualLoading() {
  if(input->navigator->GetRawButton(3)){
  this->storage->SpinLoader(input->navigator->GetRawAxis(5));
  }
}
*/

// ControlPanel

void RTPI_ManualFunctions::ManualCP(){
  if(input->navigator->GetRawButton(1)){
  double clockWise = input->navigator->GetRawAxis(3);
  double counterClockWise = input->navigator->GetRawAxis(2);
  double triggerSum = clockWise - counterClockWise;

  this->controlPanel->ColourAndCount(triggerSum);
  }
}
