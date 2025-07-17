#include <PayOff1.h>
#include <algorithm>

// define the method constructor
PayOff::PayOff(double Strike_, OptionType TheOptionsType_):
        Strike(Strike_), TheOptionsType(TheOptionsType_)
        {
        }

// define the method operator
double PayOff::operator()(double Spot) const{
    switch (TheOptionsType)
    {
    case call:
        return std::max(Spot-Strike, 0.0);
        
    case put:
        return std::max(Strike - Spot, 0.0);
    default:
        throw("Unknown type foud. ");
    }
}