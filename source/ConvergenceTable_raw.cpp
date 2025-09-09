#include <ConvergenceTable_raw.h>



ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_):
                            Inner{Inner_}, StoppingPoint{2},
                            PathsDone{0} {}

// std::unique_ptr<StatisticsMC> ConvergenceTable::clone() const{
//     return std::make_unique<ConvergenceTable>(*this);  // this invokes a copy constructor
// }
StatisticsMC* ConvergenceTable::clone() const{
    return new ConvergenceTable(*this);  // invokes a copy constructor on this
}

void ConvergenceTable::DumpOneResult(double result) {
    Inner->DumpOneResult(result);
    ++PathsDone;
    // now save in ResultSoFar the result if it is at StoppingPoint
    if (PathsDone == StoppingPoint)
    {
        StoppingPoint *=2;
        std::map<std::string, double> thisResult(Inner->GetResultsSoFar());

        for (const auto& data: thisResult){
            TableSoFar[data.first].push_back(PathsDone);
            TableSoFar[data.first].push_back(data.second);
        }

    }
    return;
}

std::map<std::string, std::vector<double>> ConvergenceTable::GetTableSoFar() const
{
    auto tmp(TableSoFar);  // creates a copy of TableSoFar
    // if not saved in table add it to the copy of table
    if (PathsDone*2 != StoppingPoint){
        auto thisResult(Inner->GetResultsSoFar()); // copy of the map of doubles of recent result
        
        for (const auto& data : thisResult)
        {
            tmp[data.first].push_back(PathsDone);
            tmp[data.first].push_back(data.second);
        }
    }
    return tmp;
}

// the next member function is defined only because the abastract
// base class has it defined and all virtual methods must be override

std::map<std::string, double> ConvergenceTable::GetResultsSoFar() const
{
    return Inner->GetResultsSoFar();
}
