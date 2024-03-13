//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 7_303
//Professor: Mohammad Patory

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

template<class T>
class Vehicle {
protected:
    T engineEfficiency;
    T currentGasoline;
    T maxGasoline;
    T currentCharge;
    T maxCharge;
public:
    Vehicle() {};
    Vehicle(T engineEfficiency, T currentGasoline, T maxGasoline, T currentCharge, T maxCharge);
    ~Vehicle();

    void fillGasoline(T amount);
    void charge(T amount);
    void drive(T km);

    T calculateRange();
    T percentEnergyRemaining();
};

template<class T>
Vehicle<T>::Vehicle(T engineEfficiency, T currentGasoline, T maxGasoline, T currentCharge, T maxCharge) :
    engineEfficiency(engineEfficiency),
    currentGasoline(currentGasoline),
    maxGasoline(maxGasoline),
    currentCharge(currentCharge),
    maxCharge(maxCharge) {}

template<class T>
Vehicle<T>::~Vehicle() {}

template<class T>
void Vehicle<T>::fillGasoline(T amount) {
    if ((currentGasoline + amount) <= maxGasoline)
        currentGasoline += amount;
}

template<class T>
void Vehicle<T>::charge(T amount) {
    if ((currentCharge + amount) <= maxCharge)
        currentCharge += amount;
}

template<class T>
void Vehicle<T>::drive(T km) {
    T consumedGasoline = km / engineEfficiency;
    if (consumedGasoline <= currentGasoline)
        currentGasoline -= consumedGasoline;
}

template<class T>
T Vehicle<T>::calculateRange() {
    return (currentGasoline / engineEfficiency) + (currentCharge / engineEfficiency);
}

template<class T>
T Vehicle<T>::percentEnergyRemaining() {
    return ((currentGasoline + currentCharge) / (maxGasoline + maxCharge)) * 100;
}

#endif
