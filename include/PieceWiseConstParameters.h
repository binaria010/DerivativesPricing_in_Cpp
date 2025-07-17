/*
header file for the class PieceWiseConstPArameters
*/

#include <Parameters.h>
#include <vector>
#pragma once


// struct Integrals
// {
//     double integral=0.0;
//     double integral_sqr =0.0;
// };

class ParametersPWConstant : public ParametersInner
{
public:
    ParametersPWConstant(double expiry, double vol);
    ParametersPWConstant(std::vector<double> times_, std::vector<double> values_); // constructor
    virtual std::unique_ptr<ParametersInner> clone() const override;  
    
public:
    virtual double Integral(double time1, double time2) const override;
    virtual double IntegralSquare(double time1, double time2) const override;
    std::vector<double> get_Times() const;
    std::vector<double> get_Values() const;
    std::vector<double> get_ValuesSquare() const;


private:
    std::vector<double> Times;
    std::vector<double> Values;
    std::vector<double> valuesSquare;    
};