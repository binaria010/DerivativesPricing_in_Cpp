// header for the PayOffBride class (we have both raw and smart pointer versions)
#pragma once
#include <memory>
#include <PayOff3.h>

class PayOffBridge {

public:
    PayOffBridge(const PayOff& innerPayOff); //constructor
    PayOffBridge(const PayOffBridge& original); //copy constructor
    PayOffBridge& operator=(const PayOffBridge& original); // assignment operator
    ~PayOffBridge();  //destructor
    inline double operator()(double Spot) const;  // method to compute the payoff of the option

private:
   
    // raw pointer version:
    // PayOff* ThePayOffPtr;

    //smart pointer version:
    std::unique_ptr<PayOff> ThePayOffPtr;

};

// define the operator()

inline double PayOffBridge::operator()(double Spot) const{
    // return (*ThePayOffPtr)(Spot);
    return ThePayOffPtr->operator()(Spot); 
}
