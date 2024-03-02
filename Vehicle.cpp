//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 6_303
//Professor: Mohammad Patory

#include "Vehicle.h"

Vehicle::Vehicle(float efficiency) : engineEfficiency(efficiency) {}

Vehicle::~Vehicle() {
    std::cout << "In Vehicle Destructor" << std::endl;
}
