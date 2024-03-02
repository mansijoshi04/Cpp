//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#include "GasolineVehicle.h"

GasolineVehicle::GasolineVehicle(float maxGasoline, float efficiency)
    : Vehicle(efficiency), currentGasoline(maxGasoline), maximumGasoline(maxGasoline) {}

GasolineVehicle::~GasolineVehicle() {
    std::cout << "In GasolineVehicle Destructor" << std::endl;
}

float GasolineVehicle::calculateRange() {
    return (currentGasoline * 100) / engineEfficiency;
}

float GasolineVehicle::percentEnergyRemaining() {
    return (currentGasoline / maximumGasoline) * 100.0f;
}

void GasolineVehicle::drive(float km) {
    float energyConsumption = (km / 100) * engineEfficiency;
    currentGasoline -= energyConsumption;
    if (currentGasoline < 0)
        std::cout << "Your car is out of energy!" << std::endl;
}
