//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(float maxCharge, float efficiency)
    : Vehicle(efficiency), currentCharge(maxCharge), maximumCharge(maxCharge) {}

ElectricVehicle::~ElectricVehicle() {
    std::cout << "In ElectricVehicle Destructor" << std::endl;
}

float ElectricVehicle::calculateRange() {
    return (currentCharge * 100) / engineEfficiency;
}

float ElectricVehicle::percentEnergyRemaining() {
    return (currentCharge / maximumCharge) * 100.0f;
}

void ElectricVehicle::drive(float km) {
    float energyConsumption = (km / 100) * engineEfficiency;
    currentCharge -= energyConsumption;
    if (currentCharge < 0)
        std::cout << "Your car is out of energy!" << std::endl;
}
