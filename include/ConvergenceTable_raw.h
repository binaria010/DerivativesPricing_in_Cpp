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
    StatisticsMC* clone() const override;
    virtual void DumpOneResult(double result) override;  // updates the statistic 
    virtual std::map<std::string, std::vector<double>> GetTableSoFar() const;
    virtual std::map<std::string, double> GetResultsSoFar() const override;

public:
    inline void PrintTable() const;
};


void ConvergenceTable::PrintTable() const {

    for (auto data : TableSoFar){
        std::cout << "for "<< data.first << " the estimated values are: \n";
        const std::vector<double>& vec = data.second;
        for (size_t i =0; i < vec.size() - 1; i+=2)
        {
            std::cout << "at iteration " << vec[i]  << ": " << vec[i+1] << "\n";
        }
        std::cout << std::endl;
    }
}