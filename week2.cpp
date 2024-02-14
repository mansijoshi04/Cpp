//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 5_303
//Professor: Mohammad Patory

#include<iostream>

#include "Vehicle.h"
using namespace std;

void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {
    v.setWheels(w);
    v.setDoors(d);
}

int main(int argc, char** argv) {
    Vehicle original;
    Vehicle copy(original); // Copy constructor by reference
    std::cout << "Original is: " << original << " copy is: " << copy << std::endl;

    std::cout << "Increment original: " << original++ << std::endl;
    std::cout << "Increment copy: " << ++copy << std::endl;
    std::cout << "Decrement original: " << --original << std::endl;
    std::cout << "Decrement copy: " << copy-- << std::endl;

    // Should be true
    std::cout << "Compare equality 1: " << (original == copy) << std::endl;
    // Should be false
    std::cout << "Compare equality 2: " << (--original == ++copy) << std::endl;
    // Should be true
    std::cout << "Compare inequality: " << (original != copy) << std::endl;
    // This should make original = copy, and then return a Vehicle for output
    std::cout << "Assignment operator: " << (original = copy) << std::endl;

    return 0;
}