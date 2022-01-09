class Car {
    int speed;
    int passengers;
    int fuel;
    static int totalcars;
public:
    // Car() = default; // if you want compiler to create default funcs.
    Car();
    ~Car();
    Car(const int &fuel);
    Car(const int &fuel, const int &pass);
    // Car(const Car &) = delete; // to avoid compiler to create default funcs.
    void Dashboard();
    static void showTotalCars();
};