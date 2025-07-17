#include <iostream>
#include <SimpleMC2.h>
#include <PayOffPower.h>

using namespace std;

/*
It requires the following source (utils) files:
1. SimpleMC2.cpp
2. PayOff2.cpp
3. Random1.cpp

IT also requires the following headers (include) files:
1. SimpleMC2.h
*/
// this is lke SimpleMCMAin3-4-5 altogether

int main(){

    double Expiry, Strike, LStrike, UStrike, Power, Spot, Vol, r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry\n";
    cin >> Expiry;
    cout << "\nEnter Strike\n";
    cin >> Strike;
    cout << "\nEnter lower strike\n";
    cin >> LStrike;
    cout << "\nEnter upper strike\n";
    cin >> UStrike;
    cout << "\nEnter power\n";
    cin >> Power;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter volatility\n";
    cin >> Vol;
    cout << "\nEnter risk-free rate\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;

    // // Create instances of the payoff objects
    // PayOffCall thePayOffCall(Strike);
    // PayOffPut thePayOffPut(Strike);
    // PayOffDigital thePayOffDigital(Strike);
    // PayOffDoubleDigital thePayOffDoubleDigital(LStrike, UStrike);
    // PayOffPowerCall thePayOffPowerCall(Strike, Power);
    // PayOffPowerPut thePayOffPowerPut(Strike, Power);
    // // Call the SimpleMonteCarlo2 function for each payoff object    
    // // compute the prices:

    // double res_call = SimpleMonteCarlo2(thePayOffCall,
    //                                     Expiry,
    //                                     Spot,
    //                                     Vol,
    //                                     r,
    //                                     NumberOfPaths);
    // double res_put = SimpleMonteCarlo2(thePayOffPut, 
    //                                     Expiry,
    //                                     Spot,
    //                                     Vol,
    //                                     r,
    //                                     NumberOfPaths);

    // double res_digital = SimpleMonteCarlo2(thePayOffDigital,
    //                                         Expiry,
    //                                         Spot,
    //                                         Vol,
    //                                         r,
    //                                         NumberOfPaths);

    // double res_doubledigital = SimpleMonteCarlo2(thePayOffDoubleDigital,
    //                                             Expiry,
    //                                             Spot,
    //                                             Vol,
    //                                             r,
    //                                             NumberOfPaths);

    // double res_powercall = SimpleMonteCarlo2(thePayOffPowerCall,
    //                                             Expiry,
    //                                             Spot,
    //                                             Vol,
    //                                             r,
    //                                             NumberOfPaths);
    // double res_powerput = SimpleMonteCarlo2(thePayOffPowerPut,
    //                                             Expiry,
    //                                             Spot,
    //                                             Vol,
    //                                             r,
    //                                             NumberOfPaths);

    // // Print the results
    // cout << "\nCall Price: " << res_call;
    // cout << "\nPut Price: " << res_put;
    // cout << "\nDigital Price: " << res_digital;
    // cout << "\nDouble Digital Price: " << res_doubledigital;
    // cout << "\nPower Call Price: " << res_powercall;
    // cout << "\nPower Put Price: " << res_powerput;
    // cout << "\n\n";

    vector<pair<string, unique_ptr<PayOff>>> payoffs;
    payoffs.emplace_back("Call", std::make_unique<PayOffCall>(Strike));
    payoffs.emplace_back("Put", std::make_unique<PayOffPut>(Strike));
    payoffs.emplace_back("Digital", std::make_unique<PayOffDigital>(Strike));
    payoffs.emplace_back("Double Digital", std::make_unique<PayOffDoubleDigital>(LStrike, UStrike));
    payoffs.emplace_back("Power Call", std::make_unique<PayOffPowerCall>(Strike, Power));
    payoffs.emplace_back("Power Put", std::make_unique<PayOffPowerPut>(Strike, Power));

    for (const auto& payoff_pair : payoffs) {
        double result = SimpleMonteCarlo2(
            *payoff_pair.second,
            Expiry,
            Spot,
            Vol,
            r,
            NumberOfPaths
        );
        std::cout << "\n" << payoff_pair.first << " Price: " << result;
    }
    std::cout << "\n\n";



    return 0;

}

