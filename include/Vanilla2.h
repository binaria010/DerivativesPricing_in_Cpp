// header for Vanilla2 class
#include <PayOffBridge.h>
#pragma once

class VanillaOption {
    public:
        VanillaOption(const PayOffBridge& ThePayOff_, double Expiry); //constructor
        // no need for copy constructor or destructor since PayOffBridge already does it for us
        double OptionPayOff(double Spot) const;
        double GetExpiry() const;

    private:
        double Expiry;
        PayOffBridge ThePayOff;
};