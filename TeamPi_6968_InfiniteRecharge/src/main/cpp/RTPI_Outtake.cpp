#include "RTPI_Outtake.h"
#include <math.h>

RTPI_Outtake::RTPI_Outtake(RTPI_SparkMax *sparkOut1_, RTPI_SparkMax *sparkOut2_, RTPI_SparkMax *_sparkLoader){
    sparkOut1 = sparkOut1_;
    sparkOut2 = sparkOut2_;
    sparkLoader = _sparkLoader;

    //this->sparkOut2->GetSparkMax()->Follow(*sparkOut1->GetSparkMax());
}


void RTPI_Outtake::Load(){
    double loadingSpeed = 0;
    this->sparkLoader->GetSparkMax()->Set(loadingSpeed);
}

void RTPI_Outtake::Shoot(double shootingspeed){
  this->sparkOutUW->GetSparkMax()->Set(shootingspeed);
  this->sparkOutDW->GetSparkMax()->Set(shootingspeed);
}

void RTPI_Outtake::AutoShoot(double shootingspeed){
  this->sparkOutUW->GetSparkMax()->Set(shootingspeed);
}

void RTPI_Outtake::DiffSpeedShoot(double uwSpeed, double dwSpeed) {
  this->sparkOutUW->GetSparkMax()->Set(uwSpeed);
  this->sparkOutDW->GetSparkMax()->Set(dwSpeed);
}
