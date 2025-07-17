/*
requires:
1. PayOffBridge.cpp
2. PayOff3.cpp
3. Vanilla2.cpp
4. Random1.cpp
5. SimpleMC5.cpp
*/

#include <SimpleMC5.h>
#include <iostream>

using namespace std;

int main()
{

    double Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin  >> Expiry;
    cout << "\nEnter strike\n";
    cin  >> Strike;
    cout << "\nEnter spot\n";
    cin  >> Spot;
    cout << "\nEnter Vol\n";
    cin  >> Vol;
    cout << "\nEnter rate r\n";
    cin  >> r;
    cout << "\nEnter number of paths\n";
    cin  >> NumberOfPaths;

    // instantiate Vol and r classes
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    // instantiate a PayOff class lets say a call and a Put
    PayOffCall call(Strike);
    PayOffPut put(Strike);
    VanillaOption theOptionCall(call, Expiry);
    VanillaOption theOptionPut(put, Expiry);

    double price_call = SimpleMonteCarlo4(theOptionCall, Spot, VolParam, rParam, NumberOfPaths);
    double price_put = SimpleMonteCarlo4(theOptionPut, Spot, VolParam, rParam, NumberOfPaths);

    cout << "\nThe price of the call is: " << price_call <<"\n";
    cout << "\nThe price of the put is: " << price_put << "\n";

}

/*
to compile and build we need:
clang++ -std=c++20 -I include/ source/PayOffBridge.cpp source/PayOff3.cpp 
source/Vanilla2.cpp source/Parameters.cpp source/SimpleMC5.cpp  source/Random1.cpp Ch4/VanillaMain3.cpp -o main
*/