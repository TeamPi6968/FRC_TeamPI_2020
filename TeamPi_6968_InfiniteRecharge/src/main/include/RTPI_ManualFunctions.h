#pragma once

#include "RTPI_Drivetrain.h"
#include "RTPI_ControllerInput.h"

using namespace frc;

class RTPI_ManualFunctions {
 private:
  RTPI_ControllerInput *input;
  RTPI_Drivetrain *drivetrain;

 public:
  RTPI_ManualFunctions(RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF);
  void DriveRL(); //Drive like Rocket League
  void DriveFPS(); //Drive like First Person Shooter
};