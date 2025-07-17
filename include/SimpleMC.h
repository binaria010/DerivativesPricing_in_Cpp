// this is the header for the cpp fle with the MonteCarlo routine
// declare the MonteCarlo function


//we need to include the header PayOff1.h since it has declared the class PayOff in it
#include <PayOff1.h>
// #pragma once
double SimpleMonteCarlo2(const PayOff& thePayOff,
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths);