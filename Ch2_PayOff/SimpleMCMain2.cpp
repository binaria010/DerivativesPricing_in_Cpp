#include <SimpleMC.h>
#include <iostream>

using namespace std;

int main(){

    double Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nEnter rate r\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;
    
    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double priceCall = SimpleMonteCarlo2(callPayOff, 
                                        Expiry, Spot, 
                                        Vol, r, NumberOfPaths);
    
    double pricePut = SimpleMonteCarlo2(putPayOff, 
                                        Expiry, Spot,
                                        Vol, r, NumberOfPaths);

    cout << "\nThe price of the call is: " << priceCall << "\n";
    cout << "\nThe price of the put is: " << pricePut << "\n";

    double tmp;
    cout << "Press any key to exit\n";
    cin >> tmp;

    return 0;

}