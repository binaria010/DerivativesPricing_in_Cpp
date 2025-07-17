#include <PieceWiseConstParameters.h>

// ------------------
//helper function
double compute_integrals(double time1, double time2,
                        std::vector<double> Times, 
                        std::vector<double> Values) 
{
    double integral =0.0;
     
    auto t1 = std::lower_bound(Times.begin(), Times.end(), time1);  //finds the element in times that is >= time1
    auto t2 = std::lower_bound(Times.begin(), Times.end(), time2);
    
    std::size_t start_idx = t1 - Times.begin(); // computes the starting index for the "for loop"
    std::size_t end_idx = t2 -  Times.begin(); //- static_cast<int>(start_idx); // computes the end index
    

    // handle left part:
    if (start_idx >0 && start_idx < Times.size())
    {
        double left = time1;
        double right = std::min(time2, Times[start_idx]);
        integral += (right-left)*Values[start_idx];
        // integrals.integral_sqr += (right-left)*valuesSquare[start_idx];
    }

    // full segments
    for (size_t i = start_idx; i < end_idx; i++)
    {
        integral += (Times[i+1] - Times[i])*Values[i];
        // integrals.integral_sqr += (Times[i] - Times[i-1])*valuesSquare[i];
    }
    //handle right part:
    if (time2 < Times.back()) // times.back() gives last element in vector
    {
        double right = time2;
        double left = std::max(time1, Times[end_idx-1]);
        integral += (right-left)*Values[end_idx]; 
        // integrals.integral_sqr += (right-left)*valuesSquare[end_idx];
    }
    return integral;

}
// ---------------------

ParametersPWConstant::ParametersPWConstant(double expiry, double vol)
{
    Times.push_back(0);
    Times.push_back(expiry);
    Values.push_back(vol);
    valuesSquare.push_back(vol*vol);
}

ParametersPWConstant::ParametersPWConstant(std::vector<double> times_, 
                        std::vector<double> values_)
{

    auto D = times_.size();
    for (std::size_t i = 1; i<D; ++i)
        {
            if (times_[i-1] >= times_[i])
                throw std::invalid_argument("times must be strictly increasing.\n");
        }
    if ( D == values_.size() + 1)
    {   
        
        Times = times_;
        Values = values_;
         
        for (double v : Values)
            valuesSquare.emplace_back(v*v);

    }
    else 
        throw std::invalid_argument("constructor: number of times has to be one more than number of values.\n");
}

std::unique_ptr<ParametersInner> ParametersPWConstant::clone() const
{
    return std::make_unique<ParametersPWConstant>(*this);
}

std::vector<double> ParametersPWConstant::get_Times() const
{
    return Times;
}

std::vector<double> ParametersPWConstant::get_Values() const
{
    return Values;
}

std::vector<double> ParametersPWConstant::get_ValuesSquare() const
{
    return valuesSquare;
}

double ParametersPWConstant::Integral(double time1, double time2) const
{
    std::vector<double> times = get_Times();
    std::vector<double> values = get_Values();
    return compute_integrals(time1, time2, times, values);
}

double ParametersPWConstant::IntegralSquare(double time1, double time2) const
{
    std::vector<double> times = get_Times();
    std::vector<double> values = get_ValuesSquare();
    return compute_integrals(time1, time2, times, values);
}