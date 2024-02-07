#include "Vehicle.h"
#include <iostream>

Vehicle::~Vehicle() {
    std::cout << "In Destructor" << std::endl;
}

Vehicle::Vehicle() : numWheels(0), numDoors(0) {
    std::cout << "Copy constructor by with zero reference called." << std::endl;
}

Vehicle::Vehicle(const Vehicle& copy) : numWheels(copy.numWheels), numDoors(copy.numDoors) {
    std::cout << "Copy constructor by reference called." << std::endl;
}

// Copy constructor by pointer
Vehicle::Vehicle(Vehicle* copy) : Vehicle(*copy) {
    std::cout << "Copy constructor by pointer called." << std::endl;
}

// Member function to print vehicle details
void Vehicle::printVehicle() const {
    std::cout << "Vehicle has " << numWheels << " wheels and " << numDoors << " doors." << std::endl;
}


int Vehicle::getWheels() const {
    return numWheels;
}

void Vehicle::setWheels(int wheels) {
    this->numWheels = wheels;
}

int Vehicle::getDoors() const {
    return numDoors;
}

void Vehicle::setDoors(int doors) {
    this->numDoors = doors;
}
