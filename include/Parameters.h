/* header for the classes:
1. PArameters (the bridge class)
2. PArametersInner (base class for several types of parameters: constant r and sigma, polynomials, exponentials..etc)
3. ParametersConstant
4 ..other types 
*/

#include <memory>
#pragma once


// base class for al the types of parameters we want to define such as r, Vol...

class ParametersInner 
{
    public:
        ParametersInner(){} //constructor
        // virtual ParametersInner* clone() const = 0;  //virtual copy constructor raw pointers
        virtual std::unique_ptr<ParametersInner> clone() const =0;
        virtual ~ParametersInner(){};
        virtual double Integral(double time1, double time2) const =0 ;
        virtual double IntegralSquare(double time1, double time2) const =0 ;
    private:       
};

// the bridge class PArameters dealing with all the copying and deleting..
// (analogous to PayOffBridge) also handles the interaction with the outside world
class Parameters 
{
    
public:
    Parameters(const ParametersInner& innerObject); //constructor
    Parameters(const Parameters& original); //copy constructor
    Parameters& operator=(const Parameters& other); //assginment
    virtual ~Parameters();

public:
    //now methods for computation
    inline double Integral(double time1, double time2) const;
    inline double IntegralSquare(double time1, double time2) const;

    // others we can define
    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;
    
private:
    // raw pointers
    // ParametersInner* InnerObjectPtr;
    std::unique_ptr<ParametersInner> InnerObjectPtr;  //smart pointers no need to manually delete
};

/* since we declared inline methods we now define them in the same header file
*/
//inline methods for Parameters
inline double Parameters::Integral(double time1, double time2) const
{
    // take the pointer to InnerObject and apply the mehtod Integral it has implemented in the subclasses
    return InnerObjectPtr->Integral(time1, time2);
}
inline double Parameters::IntegralSquare(double time1, double time2) const 
{
    return InnerObjectPtr->IntegralSquare(time1, time2);
}

// Now declare subclasses of PArametersInner: PArametersConstant and other types

class ParametersConstant : public ParametersInner
{
    public:
        ParametersConstant(double constant);//constructor(a way of initialize it is with the constant value)
        // virtual ParametersConstant* clone() const; // raw
        virtual std::unique_ptr<ParametersInner> clone() const override;   //smart
        virtual double Integral(double time1, double time2) const override;
        virtual double IntegralSquare(double time1, double time2) const override;
    private:
        double Constant; 
        double ConstantSquare;
};

// now in the source file Parameters.cpp we define all the members defined here except for the inline methods

