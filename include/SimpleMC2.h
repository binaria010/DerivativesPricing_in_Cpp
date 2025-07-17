// header to declare the MC function with input the class PayOff2
#include <PayOff2.h>
#include <Random1.h>


double SimpleMonteCarlo2(
    const PayOff& thePayOff,
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths);
