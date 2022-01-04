#include <iostream>
#include "car_class_const.h"


void Car::FillFuel(const int &ltrs) {
    fuel += ltrs;
}

void Car::AddPassengers(const int &count) {
    passengers += count;
}

void Car::Accelerate() {
    speed++;
    fuel -= 0.1;
}

void Car::Break() {
    speed = 0;
}

void Car::Dashboard() const {
    using namespace std;
    // can't modify values in const funcs.
    // speed++;
    cout << "===========" << endl;
    cout << "passengers: " << this->passengers << endl;
    cout << "speed: " << this->speed << endl;
    cout << "fuel: " << this->fuel << endl;
    cout << "===========" << endl;
}

Car::Car() {
    using namespace std;
    cout << "Car()" << endl;
    fuel = 0.0;
    speed = 0.0;
    passengers = 0;
}

Car::Car(float ltrs) {
    using namespace std;
    cout << "Car(ltrs)" << endl;
    fuel = ltrs;
    speed = 0.0;
    passengers = 0;
}

Car::~Car() {
    using namespace std;
    cout << "~Car()" << endl;
}

int main() {
    // since Car is const it can access only const qualified  funcs.
    const Car car1(10);
    // car1.FillFuel(10);
    // car1.AddPassengers(5);
    // car1.Accelerate();
    // car1.Accelerate();
    // car1.Accelerate();
    // car1.Accelerate();
    car1.Dashboard();
    // car1.Break();
    car1.Dashboard();
    return 0;
}