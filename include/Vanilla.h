// declare the VanillaOption class
#pragma once
#include <PayOff3.h>
#include <PayOffPower2.h>

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
        // PayOff* ThePayOffPtr; //raw pointer to ThePayOff 

        // smart pointer:
        std::unique_ptr<PayOff> ThePayOffPtr;
};