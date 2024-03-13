//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 7_303
//Professor: Mohammad Patory

#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

#include "Vehicle.h"

template<typename T>
class ElectricVehicle : public Vehicle<T> {
private:
    T currentCharge;
    T maxCharge;
    T energyEfficiency;

public:
    ElectricVehicle(T currentCharge, T maxCharge, T energyEfficiency);

    T calculateRange();
    T percentEnergyRemaining();
};

template<typename T>
ElectricVehicle<T>::ElectricVehicle(T currentCharge, T maxCharge, T energyEfficiency)
    : currentCharge(currentCharge), maxCharge(maxCharge), energyEfficiency(energyEfficiency) {}

template<typename T>
T ElectricVehicle<T>::calculateRange() {
    // Assuming energyEfficiency is in kWh/100km
    return (maxCharge / energyEfficiency) * 100; // Calculate range in km
}

template<typename T>
T ElectricVehicle<T>::percentEnergyRemaining() {
    return (currentCharge / maxCharge) * 100;
}

#endif 
