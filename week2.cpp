
//Name: Mansi Joshi
//Student Number: 041091664
//Lab: Lab 2_303
//Professor: Mohammad Patory

#include<iostream>
using namespace std;

namespace CST8219 {
    class Vehicle 
    {
        private:
        int numWheels;
        int numDoors;

        public:
            Vehicle(int w, int d) : numWheels(w), numDoors(d) {
                cout << "In constructor with 2 parameters" << endl;
            }   
            Vehicle(int w) : Vehicle(w, 4) {
                cout << "In constructor with 1 parameter, wheels = " << w << endl;
            }
            Vehicle() : Vehicle(4) {
                cout << "In constructor with 0 parameters" << endl;
            }
            ~Vehicle() {
                cout << "In destructor" << endl;
            }
    };
}

    int main(int argc, char** argv)
    {

        //CST8219::Vehicle myVehicle(4, 2);
        CST8219::Vehicle veh1; 
        CST8219::Vehicle veh2(4); 
        CST8219::Vehicle veh3(4, 2);
        cout << "Vehicle takes" << sizeof(veh1) << endl;
        cout << "Vehicle takes" << sizeof(veh2) << endl;
        cout << "Vehicle takes" << sizeof(veh3) << endl;


        CST8219::Vehicle* pVehicle = nullptr;
        char choice;

        do {
            int d, w;

            cout << "Enter number of doors: ";
            cin >> d;

            // Validate input for doors
            while (cin.fail() || d <= 0) {
                cout << "Invalid input. Please enter a positive integer for doors: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> d;
            }

            cout << "Enter number of wheels: ";
            cin >> w;

            // Validate input for wheels
            while (cin.fail() || w <= 0) {
                cout << "Invalid input. Please enter a positive integer for wheels: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> w;
            }

            // Delete previous object before creating a new one
            delete pVehicle;

            // Create a new object using new keyword
            pVehicle = new CST8219::Vehicle(w, d);

            cout << "Do you want to create another vehicle? (Enter 'q' to quit): ";
            cin >> choice;

        } while (choice != 'q');

        // Clean up memory before exiting
        delete pVehicle;
     return 0;
    }
