#include <iostream>
#include <SimpleMC2.h>
#include <PayOffPower.h>

using namespace std;

/*
It requires the following source (utils) files:
1. SimpleMC2.cpp
2. PayOff2.cpp
3. Random1.cpp
4. PayOffPower.cpp

IT also requires the following headers (include) files:
1. SimpleMC2.h
2. PayOffPower.h
*/

/*
to compile and build we need:
clang++ -std=c++20 -I include/ source/PayOff2.cpp 
source/Random1.cpp source/SimpleMC2.cpp Ch3_Inheritance/ex3.2.cpp -o main
*/

// interface function:

enum class PayOffType
{
    call, put, digital,double_digital, power_call, power_put
};

PayOffType string_to_payoff(string_view s)
{
    if (s =="call") return PayOffType::call;
    if (s == "put") return PayOffType::put;
    if (s == "digital") return PayOffType::digital;
    if (s == "double_digital") return PayOffType::double_digital;
    if (s == "power_call") return PayOffType::power_call;
    if (s == "power_put") return PayOffType::power_put;
    throw runtime_error("Invalid option entered.");
}

unique_ptr<PayOff> create_payoff()
{
    string name;
    cout << "Options to price: call, put, digital,double_digital, power_call,power_put\n";
    cin >> name;

    PayOffType payoff_ = string_to_payoff(name);
    switch (payoff_)
    {
    case PayOffType::call:
    {
        double Strike;
        cout << "Enter strike:\n";
        cin >> Strike;
        return make_unique<PayOffCall>(Strike); // no need of break becuase of the return
    }
    case PayOffType::put:{
        double Strike;
        cout << "Enter strike:\n";
        cin >> Strike;
        return make_unique<PayOffPut>(Strike);
    }
    case PayOffType::digital:{
        double Strike;
        cout << "Enter strike:\n";
        cin >> Strike;
        return make_unique<PayOffDigital>(Strike);
    }
    case PayOffType::double_digital:{
        double LStrike, UStrike;
        cout << "Enter Lower and upper strikes:\n";
        cin >> LStrike >> UStrike;
        return make_unique<PayOffDoubleDigital>(LStrike, UStrike);   
    }   
    case PayOffType::power_call:{
        cout << "Enter Strike and Power:\n";
        double Strike, Power;
        cin >> Strike >> Power;
        return make_unique<PayOffPowerCall>(Strike, Power);
    }
    case PayOffType::power_put:{
        cout << "Enter Strike and Power:\n";
        double Strike, Power;
        cin >> Strike >> Power;
        return make_unique<PayOffPowerPut>(Strike, Power);
    }    
}
throw runtime_error("Invalid option entered.");
}

struct Parameters{
    double Expiry = 0.0;
    double Spot = 0.0;
    double Vol = 0.0;
    double r = 0.0;
    unsigned long NumberOfPaths = 0;
};

void read_parameters(Parameters& parameters)
{
    double Expiry, Spot, Vol, r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry:\n";
    cin >> Expiry;
    cout << "\nEnter spot:\n";
    cin >> Spot;
    cout << "\nEnter volatility:\n";
    cin >> Vol;
    cout << "\nEnter risk-free rate:\n";
    cin >> r;
    cout << "\nEnter number of paths:\n";
    cin >> NumberOfPaths;

    parameters.Expiry = Expiry;
    parameters.Spot = Spot;
    parameters.Vol = Vol;
    parameters.r = r;
    parameters.NumberOfPaths = NumberOfPaths;

}


int main(){


    try {
    auto payoffptr = create_payoff();  // a pointer to the option object    

    Parameters parameters;
    read_parameters(parameters);
    
    double result = SimpleMonteCarlo2(
            *payoffptr,
            parameters.Expiry,
            parameters.Spot,
            parameters.Vol,
            parameters.r,
            parameters.NumberOfPaths
        );
        std::cout << "\nPrice is: " << result << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;

}

