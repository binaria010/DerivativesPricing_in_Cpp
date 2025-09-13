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

double quantile_fct(std::vector<double> data, double prob){


    double q_value = 0.0;
    if (data.empty())
        return q_value;

    std::vector<double> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());

    if (prob <= 0)
        return sorted_data.front();  //first element
    if (prob >= 1)
        return sorted_data.back();   //las element 

    size_t n = data.size();
    double h = prob*(n-1.0) + 1.0;
    size_t h_floor = static_cast<size_t>(std::floor(h));

    size_t index = h_floor - 1;  // 0-base index 
    q_value = sorted_data[index] + (h - h_floor)*(sorted_data[index +1] -sorted_data[index]);

    return q_value;
}

std::map<std::string, double> StatisticQuantile::GetResultsSoFar() const {
    std::map<std::string, double> res;

    double q_value = quantile_fct(Results, ConfLevel);
    res["quantile_" + std::to_string(ConfLevel)] = q_value;
    return res;
}

