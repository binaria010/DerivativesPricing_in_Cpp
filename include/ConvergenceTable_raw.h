/*
header for ConvergenceTable class (Ch5.5) using Wrapper as a Smart Pointer
*/

#pragma once
#include <MCStatistics_raw.h>
#include <Wrapper.h>


class ConvergenceTable : public StatisticsMC 
{
private:
    Wrapper<StatisticsMC> Inner;
    std::map<std::string, std::vector<double>> TableSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;

public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_); //constructor from a gatherer
    StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);  // updates the statistic 
    virtual std::map<std::string, std::vector<double>> GetTableSoFar() const;
    virtual std::map<std::string, double> GetResultsSoFar() const;

};