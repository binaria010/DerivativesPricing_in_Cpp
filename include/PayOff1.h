// #pragma once
// declare the class PayOff:

class PayOff{
    public:
        enum OptionType {call, put};
        PayOff(double Strike_, OptionType TheOptionsType_); //constructor
        double operator()(double Spot) const;
    private:
        double Strike;
        OptionType TheOptionsType;
};