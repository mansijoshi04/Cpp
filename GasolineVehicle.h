//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 7_303
//Professor: Mohammad Patory

#ifndef GASOLINE_VEHICLE_H
#define GASOLINE_VEHICLE_H

#include "Vehicle.h"

template<typename T>
class GasolineVehicle : public Vehicle<T> {
private:
    T currentGasoline;
    T maxGasoline;
    T engineEfficiency;

public:
    GasolineVehicle(T currentGasoline, T maxGasoline, T engineEfficiency);

    T calculateRange();
    T percentEnergyRemaining();
};

template<typename T>
GasolineVehicle<T>::GasolineVehicle(T currentGasoline, T maxGasoline, T engineEfficiency)
    : currentGasoline(currentGasoline), maxGasoline(maxGasoline), engineEfficiency(engineEfficiency) {}

template<typename T>
T GasolineVehicle<T>::calculateRange() {
    // Assuming engineEfficiency is in L/100km
    return (maxGasoline / engineEfficiency) * 100; // Calculate range in km
}

template<typename T>
T GasolineVehicle<T>::percentEnergyRemaining() {
    return (currentGasoline / maxGasoline) * 100;
}

#endif
