#include <MCStatistics.h>
#include <iostream>


// definition of methods for subclasses:

//-----------------------
// statisticsMean class:

StatisticsMean::StatisticsMean(): RunningSum{0.0}, PathsDone{0UL} {
    std::cout << "StatisticMean constructed!\n";
}

std::unique_ptr<StatisticsMC> StatisticsMean::clone() const 
{
    return std::make_unique<StatisticsMean>(*this);
}

void StatisticsMean::DumpOneResult(double result) 
// this methid modifies the data members of the class: 
// updates by one the paths done and the result of RunningSum after this path
// the efficiency of updating "in place" is because is being called at each iteration
{
    PathsDone++;
    RunningSum += result;
}

std::map<std::string, double> StatisticsMean::GetResultsSoFar() const
{
    std::map<std::string, double> Results;
    Results["mean"] = RunningSum / PathsDone;
    return Results;
}
