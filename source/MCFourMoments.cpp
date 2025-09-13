// this cpp is the implementation of StatisticFourMoments class

#include <MCFourMoments.h>

StatisticFourMoments::StatisticFourMoments(): RunningSum(0.0), RunningSqSum(0.0),
                                RunningCbSum(0.0), RunningFthSum(0.0),
                                PathsDone(0UL) {}

std::unique_ptr<StatisticsMC> StatisticFourMoments::clone() const{
    return std::make_unique<StatisticFourMoments>(*this);
}

std::map<std::string, double> StatisticFourMoments::GetResultsSoFar() const{
    std::map<std::string, double> Results;
    if (PathsDone >0){
        Results["first moment"] = RunningSum / PathsDone;
        Results["second moment"] = RunningSqSum / PathsDone;
        Results["third moment"] = RunningCbSum / PathsDone;
        Results["fourth moment"] = RunningFthSum / PathsDone;
    }
    else{
        Results["first moment"] = 0.0;
        Results["second moment"] = 0.0;
        Results["third moment"] = 0.0;
        Results["fourth moment"] = 0.0;
    }


    return Results;
}

void StatisticFourMoments::DumpOneResult(double result) {
    PathsDone ++;
    RunningSum +=result;
    RunningSqSum += result*result;
    RunningCbSum +=  result*result*result;
    RunningFthSum += result*result*result*result;
}