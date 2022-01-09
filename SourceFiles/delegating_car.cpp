#include <iostream>

#include "delegating_car.h"

using namespace std;

int Car::totalcars = 0;

void Car::showTotalCars() {
    cout << "totalcars: " << totalcars << endl;
}

Car::Car():Car(0) {
    cout << "Car()" << endl;
}

Car::Car(const int &fuel):Car(fuel, 0) {
    cout << "Car(fuel)" << endl;
}

Car::Car(const int &fuel, const int &pass) {
    ++totalcars;
    cout << "Car(fuel, pass)" << endl;
    this->fuel = fuel;
    this->passengers = pass;
    this->speed = 0;
}

void Car::Dashboard() {
    cout << "speed: " << speed << endl;
    cout << "fuel: " << fuel << endl;
    cout << "passengers: " << passengers << endl;
}

Car::~Car() {
    cout << "~Car()" << endl;
}

int main() {
    Car c1;
    c1.Dashboard();
    c1.showTotalCars();
    Car::showTotalCars();
    return 0;
}