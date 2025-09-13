#include <MCQuantile.h>
#include <stdexcept>

StatisticQuantile::StatisticQuantile(double conf){
    if (conf >=0 && conf <=1)
        ConfLevel = conf;
    else
        throw std::invalid_argument("confidence level must be in [0,1]\n");
}

std::unique_ptr<StatisticsMC> StatisticQuantile::clone() const {
    return std::make_unique<StatisticQuantile>(*this);
}

void StatisticQuantile::DumpOneResult(double result){
    Results.push_back(result);
}

std::map<std::string, double> StatisticQuantile::GetResultsSoFar() const {
    std::map<std::string, double> res;
    if (Results.empty()){
        res["quantile_" + std::to_string(ConfLevel)] = 0.0;
        return res;
    }
    std::vector<double> sorted_Results = Results;
    std::sort(sorted_Results.begin(), sorted_Results.end());

    size_t index = static_cast<size_t>(ConfLevel*(Results.size()-1));
    if (index >= Results.size())
        index = Results.size() - 1;
        
    double q_value = sorted_Results[index];
    res["quantile_" + std::to_string(ConfLevel)] = q_value;
    return res;
}