#include <PayOff2.h>
#include <algorithm>
using namespace std;


// define the constructor and other methods for the classes declared in payoff2.h

// Call
// constructor
PayOffCall::PayOffCall(double Strike_): Strike(Strike_){}
// compute the payoff method
double PayOffCall::operator ()(double Spot) const{
    return std::max(Spot - Strike, 0.0);
}

// Put:
// constructor
PayOffPut:: PayOffPut(double Strike_): Strike(Strike_){}
// compute the payoff method
double PayOffPut::operator ()(double Spot) const{
    return std::max(Strike - Spot, 0.0);
}


/*
IF originally: we defined only the subclasses PayOffCall and PayOffPut we can add
new subclasses payoffs without modifying the file PayOff2.cpp simply by creating 
a header file for the new class and implementing the methods in a new source file 
let's say DoubleDigital.cpp. and Digital.cpp.
Then we can add the new classes to the main file SimpleMCMain3.cpp and compile it.
This is the main advantage of using inheritance and polymorphism.
We can add new subclasses of PayOff without modifying the existing code.
*/

// Digital and Double Digital:

//Digital:
//constructor
PayOffDigital::PayOffDigital(double Strike_): Strike(Strike_){}
// compute the payoff method
double PayOffDigital:: operator ()(double Spot) const
{
    return (Spot >= Strike)*1.0;    
}


// Double Digital:
// constructor
PayOffDoubleDigital:: PayOffDoubleDigital(double LStrike_,
     double UStrike_):LStrike(LStrike_), UStrike(UStrike_){}
// compute method
double PayOffDoubleDigital::operator ()(double Spot) const
{
    return (LStrike <= Spot && UStrike >= Spot)*1.0;
}


