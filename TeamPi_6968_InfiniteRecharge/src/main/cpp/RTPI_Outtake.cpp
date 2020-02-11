#include "RTPI_Outtake.h"

RTPI_Outtake::RTPI_Outtake(RTPI_SparkMax *sparkOut1_, RTPI_SparkMax *sparkOut2_){
    sparkOut1 = sparkOut1_;
    sparkOut2 = sparkOut2_;

    this->sparkOut2->GetSparkMax()->Follow(*sparkOut1->GetSparkMax());
}

void RTPI_Outtake::Shoot(double speed){
    this->sparkOut1->GetSparkMax()->Set(speed);
}