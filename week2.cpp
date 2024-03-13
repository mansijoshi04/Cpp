//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 7_303
//Professor: Mohammad Patory

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"
#include "HybridVehicle.h"

// Templated testVehicle function
template<class T>
T* testVehicle(T* pVehicle, const char* vehicleName) {
    std::cout << vehicleName << "'s range is: " << pVehicle->calculateRange() << std::endl;
    pVehicle->drive(150); //drive 150 km
    std::cout << vehicleName << "'s energy left is: " << pVehicle->percentEnergyRemaining() << std::endl;
    std::cout << vehicleName << "'s range is now: " << pVehicle->calculateRange() << std::endl;
    return pVehicle;
}

// Templated min function
template<typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

// Templated max function
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Namespace for helper functions
namespace Helper {
    template<typename T>
    T min(T a, T b) {
        return (a < b) ? a : b;
    }

    template<typename T>
    T max(T a, T b) {
        return (a > b) ? a : b;
    }
}

// Function to test template library
void testTemplateLibrary() {
    std::vector<int> vec;
    srand(static_cast<unsigned int>(time(nullptr)));

    // Inserting random integers into the vector
    for (int i = 0; i < 10; ++i) {
        vec.push_back(rand() % 100); // Assuming random integers from 0 to 99
    }

    // Printing the elements of the vector
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test vehicles
    std::cout << "Creating and testing vehicles:" << std::endl;
    // Correct instantiation examples
    delete testVehicle(new GasolineVehicle<float>(50, 100, 7.1), "Corolla");
    delete testVehicle(new ElectricVehicle<int>(75, 100, 16), "Tesla 3");
    delete testVehicle(new HybridVehicle<double>(42, 100, 4.3, 8.8, 100, 22.0), "Prius");


    // Testing min and max functions
    std::cout << "Testing min and max functions:" << std::endl;
    std::cout << "min of 5 and 7 is: " << Helper::min(5, 7) << std::endl;
    std::cout << "max of 5 and 7 is: " << Helper::max(5, 7) << std::endl;
    std::cout << "min of A and B is: " << Helper::min('A', 'B') << std::endl;
    std::cout << "max of A and B is: " << Helper::max('A', 'B') << std::endl;
    std::cout << "min of string(Hello) and string(world) is: " << Helper::min(std::string("Hello"), std::string("World")) << std::endl;
    std::cout << "max of string(Hello) and string(world) is: " << Helper::max(std::string("Hello"), std::string("World")) << std::endl;

    // Testing template library function
    std::cout << "Testing template library function:" << std::endl;
    testTemplateLibrary();

    return 0;
}
