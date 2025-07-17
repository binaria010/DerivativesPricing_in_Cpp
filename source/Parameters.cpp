#include <Parameters.h>
#include <iostream>
#include <cmath>

/*
for PArameters class we need to define: 1. Constructor, 2. copy constructor, 3. Assignment op
*/
Parameters::Parameters(const ParametersInner& innerObject)
{
    InnerObjectPtr = innerObject.clone();
    std::cout << "Parameters constructed.\n";
}

// copy constructor of PArameters
Parameters::Parameters(const Parameters& original)
{
    InnerObjectPtr = std::unique_ptr<ParametersInner>(original.InnerObjectPtr->clone());
}
// assignment
Parameters& Parameters::operator=(const Parameters& other) 
{
    if (this != &other){
        InnerObjectPtr = other.InnerObjectPtr->clone();
    }
    return *this;
}
//destructor
Parameters::~Parameters()
{
    // delete InnerObjectPtr; // for raw pointers
    // default destructor for smart 
    std::cout << "bject destructed.\n";
}
// other non inline methods declared: Mean and RMS
//this Mean method sounds like a wrapper method for Integral
double Parameters::Mean(double time1, double time2) const 
{
    double total = InnerObjectPtr->Integral(time1, time2);
    // Joshi does it: double total = Integral(time1, time2)
    return total/(time2 - time1);
}
double Parameters::RootMeanSquare(double time1, double time2) const
{
    double MS = InnerObjectPtr->IntegralSquare(time1, time2);
    return std::sqrt(MS)/(time2 - time1);
}

// For subclasses of ParametersInner such as ParametersConstant

//constructor
ParametersConstant::ParametersConstant(double constant)
{
    Constant = constant;
    ConstantSquare = constant*constant;
}
// virtual copy 
// ParametersConstant* ParametersConstant::clone() const 
// {
//     // return new ParametersConstant(*this);  //for raw
// }
std::unique_ptr<ParametersInner> ParametersConstant::clone() const
{
    return std::make_unique<ParametersConstant>(*this);

}

// integral method
double ParametersConstant::Integral(double time1, double time2) const
{
    return (time2 - time1)*Constant;
}
double ParametersConstant::IntegralSquare(double time1, double time2) const
{
    return (time2 - time1)*ConstantSquare;
}