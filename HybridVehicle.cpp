//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#include "HybridVehicle.h"

HybridVehicle::HybridVehicle(float maxGasoline, float gasolineEfficiency, float maxCharge, float electricEfficiency)
    : GasolineVehicle(maxGasoline, gasolineEfficiency), ElectricVehicle(maxCharge, electricEfficiency) {}

HybridVehicle::~HybridVehicle() {
    std::cout << "In HybridVehicle Destructor" << std::endl;
}

float HybridVehicle::calculateRange() {
    // Calculate range using specific engine efficiencies
    float gasolineRange = GasolineVehicle::calculateRange();
    float electricRange = ElectricVehicle::calculateRange();
    return (gasolineRange + electricRange) / 2.0f;
}

float HybridVehicle::percentEnergyRemaining() {
    // Calculate percentage energy remaining using specific engine efficiencies
    float gasolinePercent = GasolineVehicle::percentEnergyRemaining();
    float electricPercent = ElectricVehicle::percentEnergyRemaining();
    return (gasolinePercent + electricPercent) / 2.0f;
}

void HybridVehicle::drive(float km) {
    // Determine which engine to use based on remaining energy
    if (ElectricVehicle::currentCharge >= (km / 100) * ElectricVehicle::engineEfficiency) {
        ElectricVehicle::drive(km);
    }
    else {
        float remainingKm = (ElectricVehicle::currentCharge / ElectricVehicle::engineEfficiency) * 100;
        GasolineVehicle::drive(km - remainingKm);
    }
}
