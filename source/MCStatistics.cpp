#include <MCStatistics.h>


// definition of methods for subclasses:

//-----------------------
// statisticsMean class:

StatisticsMean::StatisticsMean(): RunningSum(0.0), PathsDone(0UL){}

std::unique_ptr<StatisticsMC> StatisticsMean::clone() const 
{
    return std::make_unique<StatisticsMean>(*this);
}

void StatisticsMean::DumpOneResult(double result) 
// this methid modifies the data members of the class
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
