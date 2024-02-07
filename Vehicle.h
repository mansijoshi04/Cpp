#pragma once

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

private:
    int numWheels;
    int numDoors;
};
