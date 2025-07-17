// declare the VanillaOption class
#include <PayOff3.h>
#include <PayOffPower2.h>
#pragma once

class VanillaOption{

    public:
        VanillaOption(const PayOff& ThePayOff_, double Expiry_); //constructor
        VanillaOption(const VanillaOption& original);  //copy constructor
        ~VanillaOption(); //destructor
        VanillaOption& operator =(const VanillaOption& original); // assignment operator

        double GetExpiry() const;
        double OptionPayOff(double Spot) const;
    private:
        double Expiry;
        PayOff* ThePayOffPtr; //pointer to ThePayOff

};