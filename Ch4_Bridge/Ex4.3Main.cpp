/*
requires:
1. PayOffBridge.cpp
2. PayOff3.cpp
3. Vanilla2.cpp
4. Random1.cpp
5. SimpleMC5.cpp
6. Parameters.cpp
7. PieceWiseConstParameters.cpp
*/

#include <SimpleMC5.h>
#include <iostream>

using namespace std;

struct Inputs
{
    double Expiry, Strike, Spot, Vol;
    unsigned long NumberOfPaths;
    vector<double> times;
    vector<double> rate_values;
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
    cin  >> input.Vol;
    cout << "\nEnter number of paths\n";
    cin  >> input.NumberOfPaths;

    cout << "\n\nFor the interest rate enter the times and values of it" << 
    " separated by space. When done type '-1'.\n";
    cout << "\nEnter times:\n";
    double t;
    while (cin >> t && t !=-1)
    {
        input.times.push_back(t);
    }
    cout << "\nEnter values for rates:\n";
    double r;
    while (cin >> r && r !=-1)
    {
        input.rate_values.push_back(r);
    }
}



int main()
{
    
    Inputs input;
    read_inputs(input);

    // instantiate Vol and r classes
    ParametersConstant VolParam(input.Vol);
    ParametersPWConstant rParam(input.times, input.rate_values);
    // instantiate a PayOff class lets say a call and a Put
    PayOffCall call(input.Strike);
    PayOffPut put(input.Strike);
    VanillaOption theOptionCall(call, input.Expiry);
    VanillaOption theOptionPut(put, input.Expiry);

    double price_call = SimpleMonteCarlo4(theOptionCall, input.Spot, VolParam, 
                    rParam, input.NumberOfPaths);
    double price_put = SimpleMonteCarlo4(theOptionPut, input.Spot, VolParam, rParam, input.NumberOfPaths);

    cout << "\nThe price of the call is: " << price_call <<"\n";
    cout << "\nThe price of the put is: " << price_put << "\n";

}

/*
to compile and build we need:
clang++ -std=c++20 -I include/ source/PayOffBridge.cpp source/PayOff3.cpp 
source/Vanilla2.cpp source/Parameters.cpp source/SimpleMC5.cpp  source/Random1.cpp Ch4/VanillaMain3.cpp -o main
*/