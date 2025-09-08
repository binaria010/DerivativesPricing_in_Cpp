/*
This is the header for the Wrapper class declaration and definion
like Wrapper.h but using SMART POINTERS!
*/
#pragma once
#include <memory>

template <typename T>
class Wrapper
{
private:
    std::unique_ptr<T> DataPtr;
public:
    Wrapper()= default; // default constructor is setting pointer to null
  
    Wrapper(const T& inner)
    // typename (or class) T inner must have a clone method!
    {
        DataPtr = inner.clone();
    }
    ~Wrapper() = default;  //default
 
    Wrapper(const Wrapper<T>& original)
    //copy constructor
    {
        // check tht original.DataPtr is notnull otherwise by trying to clone the program will crash
        DataPtr = (original.DataPtr !=nullptr) ? 
            original.DataPtr->clone() : nullptr;

        // if we do not control class T then we need to do a unique_ptr cast to original.DataPtr->clone()
    
    }
    Wrapper<T>& operator=(const Wrapper<T>& other) // assignment
    {
        if (this != other)
        {
            DataPtr = (other.DataPtr != nullptr) ? 
                    other.DataPtr->clone() : nullptr;
            // if we do not control class T then we need to do a unique_ptr cast to other.DataPtr->clone()

        }
        return *this;    
    }

    T& operator*() //dereference operator returning a reference of type T
    // returns a reference of the object Wrapper "points at"
    {
        return *DataPtr
    }
    const T& operator*() const// same as before but a constant reference
    {
        return *DataPtr;
    }
    T* operator->()
    // this returns the pointer data member which is of type T 
    /* Wrapper<Foo> wf;
        wf->bar();  // calls Foo::bar()
    */
    {
        return DataPtr;
    }
    const T* operator->() const 
    // same as above but of type const
    {
        return DataPtr; 
    }
};
