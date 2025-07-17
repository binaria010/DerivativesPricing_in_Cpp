// header for the PayOffBride class
#include <memory>
#include <PayOff3.h>
#pragma once

class PayOffBridge {

    public:

        PayOffBridge(const PayOff& innerPayOff); //constructor
        PayOffBridge(const PayOffBridge& original); //copy constructor
        PayOffBridge& operator=(const PayOffBridge& original); // assignment operator
        ~PayOffBridge();  //destructor
        inline double operator()(double Spot) const;  // method to compute the payoff of the option

private:
   
    // raw pointer
    // PayOff* ThePayOffPtr;
    //smart pointer
    std::unique_ptr<PayOff> ThePayOffPtr;

};

// define the operator()

inline double PayOffBridge::operator()(double Spot) const{
    // return (*ThePayOffPtr)(Spot);
    return ThePayOffPtr->operator()(Spot); 
}
