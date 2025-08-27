#include <PayOffPower2.h>
#include <cmath>
#include <algorithm>
using namespace std;


// PayOff power call:

PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_): 
            Strike(Strike_), Power(Power_){

}
double PayOffPowerCall::operator () (double Spot) const {
    return max(pow(Spot, Power) - Strike, 0.0);
}

unique_ptr<PayOff> PayOffPowerCall::clone() const{
    return make_unique<PayOffPowerCall>(*this);
}


// PayOffPower put:

PayOffPowerPut::PayOffPowerPut(double Strike_, double Power_): Strike(Strike_), Power(Power_){

}

double PayOffPowerPut::operator () (double Spot) const {

    // You likely want to implement the put payoff as follows:
    return max(Strike - pow(Spot, Power), 0.0);
}
std::unique_ptr<PayOff> PayOffPowerPut::clone() const{

    return std::make_unique<PayOffPowerPut>(*this);
} 