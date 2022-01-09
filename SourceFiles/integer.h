class Integer {
private:
    int *p_int;
public:
    Integer();
    Integer(const int &value);
    int getValue() const;
    void setValue(const int &value);
    ~Integer();
    // copy constructor
    Integer(const Integer &obj);

    // overloading.
    // addition operator(it can be memeber function or global function).
    Integer operator+ (const Integer&) const;
    // Increment operator

    // preincrement
    Integer & operator ++();

    // post increment
    // we can not send same integere as its post increment so it cant be
    // reference
    Integer operator ++(int);

    // comparison operator.
    bool operator== (const Integer& obj) const;

    // assignment operator to avoid shallow copy.
    Integer & operator= (const Integer& obj);

    // move overloading
    Integer (Integer &&obj);
    Integer & operator= (Integer &&obj);
};
