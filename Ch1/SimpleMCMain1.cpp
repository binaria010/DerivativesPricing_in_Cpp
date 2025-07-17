#include <Random1.h>

double SimpleMontecarlo1(int payoff, 
                        double Strike,
                        double LowerBarrier,
                        double UpperBarrier,
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r, 
                        unsigned long NumberOfPaths
                    )
{

    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r*Expiry + itoCorrection);
    double thisSpot;  //declare this variable
    double runningSum = 0; //declare and starts at 0
    double thisPayoff = 0;
    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        // call
        if (payoff == 0){
            thisPayoff = std::max(thisSpot - Strike, 0.0);
        }
        // put
        else if (payoff == 1){ 
            thisPayoff = std::max(Strike - thisSpot, 0.0);
        }
        // double digitals
        else if (payoff == 2){
            thisPayoff = (thisSpot > LowerBarrier && thisSpot < UpperBarrier)*1;
        }

        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;

    return exp(-r*Expiry)*mean;
}

int main()
{
    int Payoff;
    double LowerBarrier, UpperBarrier, Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;

    std::cout << "\nIndicate payoff\n0: Call\n1: Put\n2: Double digital\n ";
    std::cin >> Payoff;
    if (Payoff == 0 || Payoff == 1){
        std::cout << "\nEnter strike\n";
        std::cin >> Strike;
    }
    else if(Payoff == 2) {
        std::cout << "\nEnter lower barrier\n";
        std::cin >> LowerBarrier;
        std::cout << "\nEnter upper barrier\n";
        std::cin >> UpperBarrier;  
    }
    std::cout << "\nEnter expiry\n";
    std::cin >> Expiry;
    std::cout << "\nEnter spot\n";
    std::cin >> Spot;
    std::cout << "\nEnter vol\n";
    std::cin >> Vol;
    std::cout << "\nEnter rate r\n";
    std::cin >> r;
    std::cout << "\nEnter number if paths\n";
    std::cin >> NumberOfPaths;

    double result = SimpleMontecarlo1(Payoff, Strike, LowerBarrier, UpperBarrier, Expiry, Spot, Vol, r, NumberOfPaths);
    std::cout << "the price is " << result << "\n";

    double tmp;
    std::cin >> tmp;

    return 0;

}