#include <Random1.h>

// define the functions to produce random variables approximately normal

double GetOneGaussianBySummation(){
    double result = 0;
    static std::mt19937 rng(std::random_device{}());  //random generator engine
    static std::uniform_real_distribution<double> dist(0.0, 1.0);  // declare the distribution

    for (unsigned long j = 0; j < 12; j++)    
    {
        // sum 12 uniform U(0,1) random variables
        result += dist(rng); // dist(rng) is an instance of a random uniform number    
    }
    // substract the media of the sum which is 6 since each U(0,1) has media 1/2
    return result - 6.0;
}

double GetOneGaussianByBoxMuller()
{
    double result, sizeSquared;
    double x, y;
    static std::mt19937 rng(std::random_device{}());  //random generator engine
    static std::uniform_real_distribution<double> dist(0.0, 1.0);  // declare the distribution
    do
    {
        x = 2.0*dist(rng) - 1;
        y = 2.0*dist(rng) - 1;
        sizeSquared = x*x + y*y;
    } while (sizeSquared >= 1);
    
    result = x*sqrt(-2*log(sizeSquared)/sizeSquared);
    return result;
    
}