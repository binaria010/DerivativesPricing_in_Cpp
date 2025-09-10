/*
this main uses files:
1. MCStatitistics.cpp : use smart pointers so no Wrapper needed
2. SimpleMC6.cpp
3. Vanilla2.cpp
4. PayOff3.cpp
5. PayOffBridge.cpp
6. Parameters.cpp
7. PieceWiseConstParameters.cpp
8. Random1.cpp 
9. PayOffPower2.cpp
10. ConvergenceTable_smart.cpp

no Wrapper.cpp file since it is a templetized class it
has its definition in the .h file
*/

#include <PayOffPower2.h>
#include <PieceWiseConstParameters.h>
#include <SimpleMC6_smart.h>
#include <iostream>
#include <string>
// the new classes headers:
#include <ConvergenceTable_smart.h>



using namespace std;


struct Inputs
{
    double Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;
};

void read_inputs(Inputs& input)
{
    cout << "\nEnter expiry\n";
    cin  >> input.Expiry;
    cout << "\nEnter strike\n";
    cin  >> input.Strike;
    cout << "\nEnter spot\n";
    cin  >> input.Spot;
    cout << "\nEnter Vol\n";
    cin >> input.Vol;
    cout << "\nEnter rate\n";
    cin >> input.r;
    cout << "\nEnter number of paths\n";
    cin  >> input.NumberOfPaths;
}




enum class OptionType
{
    call, put, digital, double_digital, power_call, power_put
};

OptionType string_to_option(string_view s)
// this function converts string input to a OptionType enum
{
    if (s =="call") return OptionType::call;
    if (s == "put") return OptionType::put;
    if (s == "digital") return OptionType::digital;
    if (s == "double_digital") return OptionType::double_digital;
    if (s == "power_call") return OptionType::power_call;
    if (s == "power_put") return OptionType::power_put;
    throw runtime_error("Invalid option entered.");
}

// function to create Option returning a pointer:
unique_ptr<PayOff> create_payoff(const Inputs& input, string name)
{

    OptionType option_ = string_to_option(name);
    switch (option_)
    {
    case OptionType::call:
        return make_unique<PayOffCall>(input.Strike);
    case OptionType::put:
        return make_unique<PayOffPut>(input.Strike);
    case OptionType::digital:
        return make_unique<PayOffDigital>(input.Strike);
    case OptionType::double_digital:
    {
        cout << "Enter lower and upper strikes:\n";
        double LStrike, UStrike;
        cin >> LStrike >> UStrike;
        return make_unique<PayOffDoubleDigital>(LStrike,UStrike);
    }
    case OptionType::power_call:
    {
        cout << "Enter power:\n";
        double Power;
        cin >> Power;
        return make_unique<PayOffPowerCall>(input.Strike, Power);
    }
    case OptionType::power_put:
    {
        cout << "Enter power:\n";
        double Power;
        cin >> Power;
        return make_unique<PayOffPowerPut>(input.Strike, Power);
    }
    }
throw invalid_argument("Invalid option entered.\n");
}

void printResults(string name, map<string,double> results)
{
    cout << "For the option " << name<< " results are: "<<endl;
    for (const auto& pair : results)
        cout << pair.first << " : " << pair.second << endl;
}


int main()
{
    try{
    string name;
    cout << "Options to price: call, put, digital, "<<
         "double_digital, power_call,power_put\n";
    cin >> name;
    Inputs input;
    read_inputs(input);
    auto payoffptr = create_payoff(input, name);
    VanillaOption theOption(*payoffptr, input.Expiry);
    ParametersConstant Vol(input.Vol);
    ParametersConstant Rate(input.r);

    // declare both gatherer and convergencetable
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    SimpleMonteCarlo5(theOption, input.Spot, 
                    Vol, Rate, input.NumberOfPaths, gathererTwo);
    
    map<string, double> results = gathererTwo.GetResultsSoFar();
    map<string, vector<double>> table = gathererTwo.GetTableSoFar();
    printResults(name, results);
    cout << "\n\nsize of convergence table is: " << table["mean"].size() << "\n\n";
    gathererTwo.PrintTable();

    }

    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    


}

