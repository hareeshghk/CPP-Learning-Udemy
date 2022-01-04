#include <iostream>
#include "car_class.h"

int Car::totalCars = 0;
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

// using this object can be sent from a class.
// void SecondDashboard(Car &car) {
//     car.Accelerate();
//     car.Dashboard();
// }

void Car::Break() {
    speed = 0;
    // SecondDashboard(*this);
}

void Car::Dashboard() {
    using namespace std;
    cout << "===========" << endl;
    cout << "passengers: " << this->passengers << endl;
    cout << "speed: " << this->speed << endl;
    cout << "fuel: " << this->fuel << endl;
    cout << "total cars: " << totalCars << endl;
    cout << "===========" << endl;
}

Car::Car() {
    using namespace std;
    cout << "Car()" << endl;
    totalCars++;
    fuel = 0.0;
    speed = 0.0;
    passengers = 0;
}

Car::Car(float ltrs) {
    using namespace std;
    totalCars++;
    cout << "Car(ltrs)" << endl;
    fuel = ltrs;
    speed = 0.0;
    passengers = 0;
}

Car::~Car() {
    using namespace std;
    --totalCars;
    cout << "~Car()" << endl;
}

void Car::showCount() {
    std::cout << "total cars: " << totalCars << std::endl;
}

int main() {
    // Car car1;
    Car car1(10);
    car1.FillFuel(10);
    car1.AddPassengers(5);
    car1.Accelerate();
    car1.Accelerate();
    car1.Accelerate();
    car1.Accelerate();
    car1.Dashboard();
    car1.Break();
    car1.Dashboard();

    Car c1, c2;
    // c1.Dashboard();
    // c2.Dashboard();

    Car::showCount();
    return 0;
}