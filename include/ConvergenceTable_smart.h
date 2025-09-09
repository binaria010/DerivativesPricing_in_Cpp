/*
header for ConvergenceTable class (Ch5.5) using SMART POINTERS
*/

#pragma once
#include <MCStatistics.h>
// #include <Wrapper.h>  // no need of Wrapper since we have smart pointers


class ConvergenceTable : public StatisticsMC 
{
private:
    // Wrapper<StatisticsMC> Inner;
    std::unique_ptr<StatisticsMC> Inner;
    std::map<std::string, std::vector<double>> TableSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;

public:
    ConvergenceTable(const StatisticsMC& Inner_); //constructor from a gatherer
    virtual std::unique_ptr<StatisticsMC> clone() const;
    virtual void DumpOneResult(double result);  // updates the statistic 
    virtual std::map<std::string, std::vector<double>> GetTableSoFar() const;
    virtual std::map<std::string, double> GetResultsSoFar() const;

};