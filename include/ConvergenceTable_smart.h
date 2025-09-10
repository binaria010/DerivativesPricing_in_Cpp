/*
header for ConvergenceTable class (Ch5.5) using SMART POINTERS
*/

#pragma once
#include <MCStatistics.h>
#include <iostream>
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
    // make my own copy constructor (deep copy constructor) for clone method:
    ConvergenceTable(const ConvergenceTable& other);
    virtual std::unique_ptr<StatisticsMC> clone() const;
    virtual void DumpOneResult(double result);  // updates the statistic 
    virtual std::map<std::string, std::vector<double>> GetTableSoFar() const;
    virtual std::map<std::string, double> GetResultsSoFar() const;

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