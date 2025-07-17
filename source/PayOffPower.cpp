#include <PayOffPower.h>
#include <cmath>
#include <algorithm>

using namespace std;


// PayOffPowerCall:
PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_): Strike(Strike_), Power(Power_){} // inherit constructor from PayOffPower
    // compute the payoff method
    double PayOffPowerCall::operator()(double Spot) const
    {
        return max(pow(Spot, Power) - Strike, 0.0);
    }




// PayOffPowerPut:


PayOffPowerPut::PayOffPowerPut(double Strike_, double Power_):Strike(Strike_), Power(Power_){} // inherit constructor from PayOffPower
    // compute the payoff method
    double PayOffPowerPut::operator()(double Spot) const
    {
        return max(Strike - pow(Spot, Power), 0.0);
    }
    