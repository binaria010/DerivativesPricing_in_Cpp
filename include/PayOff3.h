// header to declare the PayOff2 class
// This file is part of the C++ Options Pricing Library.
#pragma once
#include <memory>

class PayOff
{
    public: 
    PayOff(){};      //constructor
    //virtual methods: copy constructor, destructor, compute the payoff 
    // virtual PayOff* clone() const = 0; //virtual copy constructor
    virtual std::unique_ptr<PayOff> clone() const = 0;
    virtual ~PayOff(){};
    virtual double operator()(double Spot) const = 0;


    private: 
    // in the base class we don't have any data members
};

class PayOffCall : public PayOff{

public:
    //constructor
    PayOffCall(double Strike_);
    //compute the payoff
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffCall(){};
    //virtual copy constructor using raw pointes
    // virtual PayOff* clone() const override;
    std::unique_ptr<PayOff> clone() const override; // virtual copy constructor using smart pointers

private:
    double Strike;

};

class PayOffPut : public PayOff
{
public:
    // consturctor
    PayOffPut(double Strike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffPut(){};
    //copy constructor using raw pointers
    // virtual PayOff* clone() const override;
    std::unique_ptr<PayOff> clone() const override;  //using smart pointers

private:
    double Strike;
};

class PayOffDigital : public PayOff
{
 public:
    // constructor
    PayOffDigital(double Strike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffDigital(){};
    // copy constructor
    // virtual PayOff* clone() const override;      //virtual copy constructor using raw pointes
    std::unique_ptr<PayOff> clone() const override;  // using smart pointers

private:
    double Strike;
};

class PayOffDoubleDigital : public PayOff
{
public:
    // constructor
    PayOffDoubleDigital(double LStrike_, double UStrike_);
    // compute payoff method
    virtual double operator ()(double Spot) const override;
    // destructor
    virtual ~PayOffDoubleDigital(){};
    // copy constructor using raw pointers
    // virtual PayOff* clone() const override;
    std::unique_ptr<PayOff> clone() const override; // using smart pointers

private:
    double LStrike;
    double UStrike;
};



