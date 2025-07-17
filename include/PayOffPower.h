// we need to include the header file for the base class PayOff
#include <PayOff2.h>

class PayOffPower : public PayOff
{
    public:
    PayOffPower(double Strike_, double Power_);
    virtual double operator() (double Spot) const=0;
    virtual ~PayOffPower(){};
    
    protected:
    double Strike;
    double Power;
};

// PayOffPowerCall and PayOffPowerPut are subclasses of PayOffPower
// and they inherit the constructor from PayOffPower
class PayOffPowerCall : public PayOff
{
    public:
    PayOffPowerCall(double Strike_, double Power_);
    virtual double operator() (double Spot) const;
    virtual ~PayOffPowerCall(){};
    
    private:
    double Strike;
    double Power;
};

class PayOffPowerPut : public PayOff
{
    public:
    PayOffPowerPut(double Strike_, double Power_);
    virtual double operator() (double Spot) const;
    virtual ~PayOffPowerPut(){};
    
    private:
    double Strike;
    double Power;
};
