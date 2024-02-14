#pragma once
#include <iostream>

class Vehicle {
public:
    ~Vehicle();
    Vehicle(); // Empty constructor
    Vehicle(const Vehicle& copy); // Copy constructor by reference
    Vehicle(Vehicle* copy); // Copy constructor by pointer

    void printVehicle() const; // Function to print vehicle details

    // Getters and setters for number of wheels and doors
    int getWheels() const;
    void setWheels(int wheels);
    int getDoors() const;
    void setDoors(int doors);

    // Assignment operator
    Vehicle& operator=(const Vehicle& other);

    // Comparison operators
    bool operator==(const Vehicle& other) const;
    bool operator!=(const Vehicle& other) const;

    // Increment and decrement operators
    Vehicle& operator++();    // Prefix increment
    Vehicle operator++(int);  // Postfix increment
    Vehicle& operator--();    // Prefix decrement
    Vehicle operator--(int);  // Postfix decrement

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

private:
    int numWheels;
    int numDoors;
};
