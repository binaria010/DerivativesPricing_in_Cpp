/*
requires to run:
1. PayOff3.cpp
2. Vanilla.cpp
3. SimpleMC3.cpp
4. Random1.cpp
*/

#include <Vanilla.h> //inside Vanilla.h there is an include to PayOff3.h
#include <SimpleMC3.h>
#include <iostream>
using namespace std;

int main(){

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

    //call
    PayOffCall call(Strike); //construct a PayOffCall called "call"
    VanillaOption theOption_call(call, Expiry);

    double price_call = SimpleMonteCarlo3(theOption_call, Spot, Vol, r, NumberOfPaths);
    cout << "\nThe price of the call option is " << price_call << "\n";

    //put
    PayOffPut put(Strike);
    VanillaOption theOption_put(put, Expiry);
    double price_put = SimpleMonteCarlo3(theOption_put, Spot, Vol, r, NumberOfPaths);
    cout << "The price of the put is " << price_put << "\n";

    return 0;
}

/* 
to compile and build: clang++ -std=c++20 -I include/ source/PayOff3.cpp  source/Vanilla.cpp source/SimpleMC3.cpp source/Random1.cpp Ch4_Vanilla/VanillaMain.cpp -o main
*/