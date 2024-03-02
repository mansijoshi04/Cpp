//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#pragma once
#include <iostream>

class Vehicle {
public:
    virtual ~Vehicle();
    virtual float calculateRange() = 0;
    virtual float percentEnergyRemaining() = 0;
    virtual void drive(float km) = 0;

protected:
    float engineEfficiency;

    Vehicle(float efficiency);
};
