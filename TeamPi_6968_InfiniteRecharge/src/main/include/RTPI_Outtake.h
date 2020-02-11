/*
-   Created By: Duncan Kikkert
-   Date: 11/02/2020
-   Time: 12:10
-   Class: RTPI_Outtake
*/

#pragma once

#include "RTPI_SparkMax.h"

class RTPI_Outtake {
    private:
        RTPI_SparkMax *sparkOut1;
        RTPI_SparkMax *sparkOut2;

    public:
    RTPI_Outtake(RTPI_SparkMax *sparkOut1_, RTPI_SparkMax *sparkOut2_);
    void Shoot(double speed);
};