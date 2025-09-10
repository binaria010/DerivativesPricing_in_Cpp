#include <SimpleMC6_smart.h>
#include <Random1.h>

// this function is called in the main StatsMAin1.cpp

void SimpleMonteCarlo5(const VanillaOption& TheOption,
            double Spot, const Parameters& Vol, 
            const Parameters& r,
            unsigned long NumberOfPaths,
            StatisticsMC& gatherer)
{
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0, Expiry));

    for (unsigned long i =0; i < NumberOfPaths; ++i)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();  //W
        thisSpot = movedSpot*exp(rootVariance*thisGaussian); // S(T)
        double thisPayOff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);   //updates the mean or other results
    }

    return;
}


