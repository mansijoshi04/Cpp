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

Vehicle::Vehicle(Vehicle* copy) : Vehicle(*copy) {
    std::cout << "Copy constructor by pointer called." << std::endl;
}

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

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        numWheels = other.numWheels;
        numDoors = other.numDoors;
    }
    return *this;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return (numWheels == other.numWheels && numDoors == other.numDoors);
}

bool Vehicle::operator!=(const Vehicle& other) const {
    return !(*this == other);
}

Vehicle& Vehicle::operator++() {
    ++numWheels;
    ++numDoors;
    return *this;
}

Vehicle Vehicle::operator++(int) {
    Vehicle temp(*this);
    ++(*this);
    return temp;
}

Vehicle& Vehicle::operator--() {
    --numWheels;
    --numDoors;
    return *this;
}

Vehicle Vehicle::operator--(int) {
    Vehicle temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << "Vehicle has " << v.numWheels << " wheels and " << v.numDoors << " doors.";
    return os;
}

