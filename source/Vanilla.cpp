#include <Vanilla.h>


// constructor
VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_):Expiry(Expiry_){
    // initialize ThePayOff pointer
    ThePayOffPtr = ThePayOff_.clone();
}
//copy constructor
VanillaOption::VanillaOption(const VanillaOption& original){

    Expiry = original.Expiry;
    ThePayOffPtr = original.ThePayOffPtr->clone();
}
//assignment operator:
VanillaOption& VanillaOption::operator =(const VanillaOption& original){

    if (this != &original){
        Expiry = original.Expiry;
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}
// destructor
VanillaOption::~VanillaOption(){
    delete ThePayOffPtr;  // deletes the pointer to PayOff
}
// Get Expiry method
double VanillaOption::GetExpiry() const{
    return Expiry;
}
// compute the payoff:
double VanillaOption::OptionPayOff(double Spot) const {
    return (*ThePayOffPtr)(Spot);
}