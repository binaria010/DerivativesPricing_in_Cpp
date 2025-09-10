#include <ConvergenceTable_smart.h>



ConvergenceTable::ConvergenceTable(const StatisticsMC& Inner_):
                            Inner{Inner_.clone()}, StoppingPoint{2},
                            PathsDone{0} {}

// deep copy constructor:
ConvergenceTable::ConvergenceTable(const ConvergenceTable& other):
                Inner(other.Inner->clone()), TableSoFar(other.TableSoFar),
                StoppingPoint(other.StoppingPoint), PathsDone(other.PathsDone)
                {}


std::unique_ptr<StatisticsMC> ConvergenceTable::clone() const {
    return std::make_unique<ConvergenceTable>(*this);  // this invokes a copy constructor
}

void ConvergenceTable::DumpOneResult(double result) {
    Inner->DumpOneResult(result);
    ++PathsDone;
    // now save in TableSoFar the result if it is at StoppingPoint
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
