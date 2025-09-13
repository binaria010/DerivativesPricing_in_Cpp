/*
Exercise 5.1 Write a statistics gathering class that computes the 
first four moments of a sample.
*/

#include <MCStatistics.h>


class StatisticFourMoments : public StatisticsMC{

private:
    double RunningSum;
    double RunningSqSum;
    double RunningCbSum;
    double RunningFthSum;
    unsigned long PathsDone;

public:
    StatisticFourMoments();  //default constructor
    virtual void DumpOneResult(double result) override; // for updating by one result
    virtual std::map<std::string, double> GetResultsSoFar() const override;
    virtual std::unique_ptr<StatisticsMC> clone() const override;

};