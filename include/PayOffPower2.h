// header for the PayOffPower class using clone copy constructor with smart pointers
#include <PayOff3.h>
#pragma once

// option power call and power put are subclasses of the base class PayOffPower

class PayOffPowerCall: public PayOff {

    public:
        PayOffPowerCall(double Strike_, double Power_); //constructor
        virtual std::unique_ptr<PayOff> clone() const override; //copy constructor
        virtual double operator ()(double Spot) const override;

    private:
        double Strike;
        double Power;

};

class PayOffPowerPut : public PayOff{

    public:
        PayOffPowerPut(double Strike_, double Power_); 
        virtual std::unique_ptr<PayOff> clone() const override;
        virtual double operator()(double Spot) const override;
    
    private:
        double Strike;
        double Power;
};
