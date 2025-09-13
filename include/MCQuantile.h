/*
Ex 5.2; Write a statistics gathering class that computes the 
value at risk of a sample.

we are going to wirte a class that computes a Quantile of a sample
instead.
*/

#include <MCStatistics.h>

class StatisticQuantile : public StatisticsMC{

private:
    std::vector<double> Results;
    double ConfLevel;

public:
    StatisticQuantile(double conf);
    virtual std::unique_ptr<StatisticsMC> clone() const override;
    virtual void DumpOneResult(double result) override;
    virtual std::map<std::string, double> GetResultsSoFar() const override;
};