#include "RTPI_AutoFunctions.h"

RTPI_AutoFunctions::RTPI_AutoFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake) {
  robotIO = _robotIO;
  input = _input;
  drivetrain = _drivetrain;
  intake = _intake;
  storage = _storage;
  outtake = _outtake;

  this->autoShootingTimer = new Timer();
}

bool RTPI_AutoFunctions::stopAutoFunction() {
  if(input->navigator->GetRawButton(7) || input->driver->GetRawButton(7)) {
    return true;
  }
  else {
    return false;
  }
}

//STORAGE:

void RTPI_AutoFunctions::moveStorageFifth() {
  robotIO->storageRevolverBState0 = input->navigatorPOVUp->Get();

  if(robotIO->storageRevolverBState0 != robotIO->lastStorageRevolverBState0) {
    if(robotIO->storageRevolverBState0) {
      this->storage->moveFifth(1);
    }
    robotIO->lastStorageRevolverBState0 = robotIO->storageRevolverBState0;
  }

  robotIO->storageRevolverBState1 = input->navigatorPOVDown->Get();

  if(robotIO->storageRevolverBState1 != robotIO->lastStorageRevolverBState1) {
    if(robotIO->storageRevolverBState1) {
      this->storage->moveFifth(-1);
    }
    robotIO->lastStorageRevolverBState1 = robotIO->storageRevolverBState1;
  }
}

//OUTTAKE:

void RTPI_AutoFunctions::shootAutomatic() {
  if(input->navigator->GetRawButton(2)) {
    if(robotIO->autoShootingActivated == 0) {
      robotIO->autoShootingActivated = 1;
      autoShootingTimer->Start();
    }
    if(robotIO->autoShootingActivated == 1) {
      if(autoShootingTimer->Get() > 0) {
        outtake->Shoot(0.8);
      }
      if(autoShootingTimer->Get() > 1) {
        storage->SpinLoader(-0.8);
      }
      if(autoShootingTimer->Get() > 2) {
        storage->SpinRevolver(-0.8);
      }
    }
  }
  else {
    if(autoShootingTimer->Get() != 0) {
      autoShootingTimer->Reset();
      autoShootingTimer->Stop();
    }
    robotIO->autoShootingActivated = 0;
  }
}

/*void RTPI_AutoFunctions::AutomaticShooting(){
    float distance = GetSensor();  ELOBOU SENSOR
    double v0 = 0;
    v0 = sqrt((0.525+distance * tan(35) - 9.81 * distance * distance) * (cos(35) * cos(35)) / 2.49);
}
*/
