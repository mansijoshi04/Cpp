//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#pragma once
#include "ElectricVehicle.h"
#include "GasolineVehicle.h"

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
public:
    HybridVehicle(float maxGasoline, float gasolineEfficiency, float maxCharge, float electricEfficiency);
    ~HybridVehicle() override;
    float calculateRange() override;
    float percentEnergyRemaining() override;
    void drive(float km) override;
};
