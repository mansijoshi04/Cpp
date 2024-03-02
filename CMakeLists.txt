
cmake_minimum_required(VERSION 2.8.9)

project (week2)

add_executable(week2 week2.cpp  Vehicle.h "ElectricVehicle.cpp" "GasolineVehicle.cpp" "HybridVehicle.cpp"  "HybridVehicle.h" "GasolineVehicle.h" "ElectricVehicle.h" "Vehicle.cpp")