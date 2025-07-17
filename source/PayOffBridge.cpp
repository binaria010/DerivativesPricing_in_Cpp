#include <iostream>
#include <PayOffBridge.h>

//constructor
PayOffBridge::PayOffBridge(const PayOff& innerPayOff){
    
    // clones the PayOff object
    ThePayOffPtr = innerPayOff.clone();
    std::cout<< "constructor with PayOff\n"; 
}
//copy constructor
PayOffBridge::PayOffBridge(const PayOffBridge& original){

    ThePayOffPtr = original.ThePayOffPtr->clone();
    std::cout<< "copy constructor\n";
}
//assignmente
PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original){
    
    if (this != &original) // if what i am assigning is not the same thing
    {
        // delete ThePayOffPtr; // delete the old pointer for raw pointer
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}
// destructor for raw pointers

PayOffBridge::~PayOffBridge(){
    // delete ThePayOffPtr;   // for raw pointers
    std::cout <<"pointer deleted\n";
}

// default destructor is fine since unique_ptr will delete automatically