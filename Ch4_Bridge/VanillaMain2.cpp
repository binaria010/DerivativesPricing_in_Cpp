/*
Requires:
1. PayOffBridge.cpp
2. PayOff3.cpp
3. Vanilla2.cpp
4. SimpleMC4.cpp
5. Random1.cpp
*/

#include <SimpleMC4.h>
#include <Vanilla2.h>
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
    VanillaOption theOption_call(call, Expiry); // below the explanation of why we can pass call directly and not a PayOffBridge!

    cout << "computing price...\n";
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
    Although the VanillaOption (see Vanilla2.cpp) constructor expects an argument of type
    "PayOffBridge", it happily accepts the argument of type "PayOffCall". The reason is that
    there is a constructor for PayOffBridge which takes in an object of type PayOff&. The compiler
    automatically accepts the inherited class object as a substitute for the base class object and
    then silently converts it for us into the PayOffBridge object which is then passed to the 
    VanillaOption constructor.
    */
/* 
to compile and build: clang++ -std=c++20 -I include/ source/PayOff3.cpp source/PayOffBridge.cpp source/Vanilla2.cpp source/SimpleMC3.cpp source/Random1.cpp Ch4/VanillaMain2.cpp -o main
*/