class Integer {
private:
    int *p_int;
public:
    Integer();
    Integer(const int &value);
    int getValue();
    void setValue(const int &value);
    ~Integer();
    // copy constructor
    Integer(const Integer &obj);
};
