/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//Pre-Written libraries
#include <string>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

//Selfmade libraries
#include "RobotIO.h"
#include "RTPI_SparkMax.h"
#include "RTPI_VictorSPX.h"
#include "RTPI_Pneumatics.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Intake.h"
#include "RTPI_Storage.h"
#include "RTPI_ManualFunctions.h"
#include "RTPI_PIDControl.h"
#include "RTPI_Outtake.h"

using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  void MotorControllerSetup();
  void PneumaticSetup();
  void ModuleSetup();

 private:
  //Drivetrain Motorcontrollers:
    RTPI_SparkMax *sparkDrivetrainLF;
    RTPI_SparkMax *sparkDrivetrainLB;
    RTPI_SparkMax *sparkDrivetrainRB;
    RTPI_SparkMax *sparkDrivetrainRF;

  //Intake Motorcontroller:
    RTPI_VictorSPX *victorIntakeCylinder;
  
  //Storage Motorcontrollers:
    RTPI_SparkMax *sparkStorageRevolver;
    RTPI_SparkMax *sparkStorageLoader;

  //Outtake Motorcontrollers:
    RTPI_SparkMax *sparkOuttakeUW;
    RTPI_SparkMax *sparkOuttakeDW;

  //Control Panel Motorcontroller:
    RTPI_SparkMax *sparkCPWheels;

  //Pneumatics:
    //Compressor
      RTPI_Pneumatics *compressor;
    //Pistons with 'Double Solenoids'
      RTPI_Pneumatics *intakeLPiston;
      RTPI_Pneumatics *intakeRPiston;
      RTPI_Pneumatics *cpPiston;

  //RobotIO:
    RobotIO *robotIO;

  //ControllerInput:
    RTPI_ControllerInput *input;

  //Drivetrain
    RTPI_Drivetrain *drivetrain;

  //Intake
    RTPI_Intake *intake;
    
  //Outtake
    RTPI_Outtake *outtake;

  //Storage
    RTPI_Storage *storage;

  //ManualDrive
    RTPI_ManualFunctions *mFunctions;

  //PIDControl
    RTPI_PIDControl *PID;
};
