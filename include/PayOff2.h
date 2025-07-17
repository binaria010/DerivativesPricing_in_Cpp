// header to declare the PayOff2 class
// This file is part of the C++ Options Pricing Library.
#pragma once

class PayOff
{
    public: 
    //constructor
    PayOff(){};
    //virtual methods: compute the payoff and destructor
    virtual double operator()(double Spot) const = 0; // =0 means it is a pure virtual function
    // so, every subclass has to implement this method operator.
    // if a subclass lacks the implementation of this method we won't be able to instantiate it
    virtual ~PayOff(){};

    private: 
    // in the base class we don't have any data members
};

class PayOffCall : public PayOff{

    public:
    //constructor
    PayOffCall(double Strike_);
    //compute the payoff
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffCall(){};
    
    private:
    
    double Strike;
};

class PayOffPut : public PayOff
{
    public:
    // consturctor
    PayOffPut(double Strike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffPut(){};

    private:
    double Strike;
};

class PayOffDigital : public PayOff
{
    public:
    // constructor
    PayOffDigital(double Strike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffDigital(){};

    private:
    double Strike;
};

class PayOffDoubleDigital : public PayOff
{
    public:
    // constructor
    PayOffDoubleDigital(double LStrike_, double UStrike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffDoubleDigital(){};

    private:
    double LStrike;
    double UStrike;
};



