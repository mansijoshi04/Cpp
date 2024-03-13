//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 7_303
//Professor: Mohammad Patory

#ifndef HYBRID_VEHICLE_H
#define HYBRID_VEHICLE_H

#include "Vehicle.h"

template<typename T>
class HybridVehicle : public Vehicle<T> {
private:
    T currentGasoline;
    T maxGasoline;
    T engineEfficiency;

    T currentCharge;
    T maxCharge;
    T energyEfficiency;

public:
    HybridVehicle(T currentGasoline, T maxGasoline, T engineEfficiency, T currentCharge, T maxCharge, T energyEfficiency);

    T calculateRange();
    T percentEnergyRemaining();
};

template<typename T>
HybridVehicle<T>::HybridVehicle(T currentGasoline, T maxGasoline, T engineEfficiency, T currentCharge, T maxCharge, T energyEfficiency)
    : currentGasoline(currentGasoline), maxGasoline(maxGasoline), engineEfficiency(engineEfficiency),
    currentCharge(currentCharge), maxCharge(maxCharge), energyEfficiency(energyEfficiency) {}

template<typename T>
T HybridVehicle<T>::calculateRange() {
    // Assuming engineEfficiency is in L/100km and energyEfficiency is in kWh/100km
    T gasolineRange = (currentGasoline / engineEfficiency) * 100; // Calculate gasoline range in km
    T electricRange = (currentCharge / energyEfficiency) * 100; // Calculate electric range in km
    return gasolineRange + electricRange;
}

template<typename T>
T HybridVehicle<T>::percentEnergyRemaining() {
    T gasolinePercent = (currentGasoline / maxGasoline) * 100;
    T electricPercent = (currentCharge / maxCharge) * 100;
    return (gasolinePercent + electricPercent) / 2; // Average percentage remaining
}

#endif 
