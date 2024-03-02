//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#pragma once
#include "Vehicle.h"

class GasolineVehicle : public Vehicle {
public:
    GasolineVehicle(float maxGasoline, float efficiency);
    ~GasolineVehicle() override;
    float calculateRange() override;
    float percentEnergyRemaining() override;
    void drive(float km) override;

private:
    float currentGasoline;
    float maximumGasoline;
};
