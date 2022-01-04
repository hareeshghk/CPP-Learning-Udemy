class Car {
private:
    float fuel;
    float speed;
    int passengers;
public:
    Car();
    Car(float ltrs);
    ~Car();
    void FillFuel(const int &ltrs);
    void Accelerate();
    void Break();
    void AddPassengers(const int &count);
    void Dashboard() const;
};