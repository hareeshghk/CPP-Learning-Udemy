class Car {
private:
    float fuel;
    float speed;
    int passengers;
    static int totalCars;
public:
    Car();
    Car(float ltrs);
    ~Car();
    void FillFuel(const int &ltrs);
    void Accelerate();
    void Break();
    void AddPassengers(const int &count);
    void Dashboard();

    static void showCount();
};