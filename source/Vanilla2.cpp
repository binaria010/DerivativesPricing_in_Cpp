#include <Vanilla2.h>

//constructor
VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_): 
                ThePayOff(ThePayOff_), Expiry(Expiry_) {}

// payoff operator
double VanillaOption::OptionPayOff(double Spot) const {
    
    /*ThePayOff is a class of type PayOffBridge which when initialized clones a class of type PayOff
     and this class has the method operator() to compute the option payoff
    */
    return ThePayOff(Spot);  

}

// method to get expiry
double VanillaOption::GetExpiry() const {

    return Expiry;
}
