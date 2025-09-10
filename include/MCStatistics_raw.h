// header file for the StatisticsMC class and subclasses using smart pointers
#pragma once

#include <vector>
#include <string>
#include <map>

class StatisticsMC  //abstract class  (base class for all the gatherers)
{
public:
    virtual void DumpOneResult(double result) = 0;
    virtual std::map<std::string, double> GetResultsSoFar() const = 0;

public:
    StatisticsMC(){}  //constructor
    virtual StatisticsMC* clone() const = 0;  // virtual copy constructor (clone)
    virtual ~StatisticsMC(){}

private:

};

//-----------------------
// subclases:

class StatisticsMean : public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result) override; // this method modifies result
    virtual std::map<std::string,double> GetResultsSoFar() const override;
public:
    virtual StatisticsMC* clone() const override;

private:
    double RunningSum;
    unsigned long PathsDone;
};