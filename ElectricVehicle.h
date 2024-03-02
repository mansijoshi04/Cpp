//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#pragma once
#include "Vehicle.h"

class ElectricVehicle : public Vehicle {
public:
    ElectricVehicle(float maxCharge, float efficiency);
    ~ElectricVehicle() override;
    float calculateRange() override;
    float percentEnergyRemaining() override;
    void drive(float km) override;

protected:
    float currentCharge; // Change from private to protected
    float maximumCharge;
};
