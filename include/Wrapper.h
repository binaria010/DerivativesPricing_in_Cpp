#pragma once

template <typename T>
class Wrapper
{
private:
    T* DataPtr;
public:
    Wrapper() //constructor
    {
        DataPtr = 0;  //null pointer by default
    }
    Wrapper(const T& inner)
    // typename (or class) T inner must have a clone method!
    {
        DataPtr = inner.clone();
    }
    ~Wrapper()
    {
        if (DataPtr != 0)
            delete DataPtr;
    }
    Wrapper(const Wrapper<T>& original)
    //copy constructor
    {
        if (this != &original) //if not equal then copy clone
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = 0;
    }
    Wrapper& operator=(const Wrapper<T>& other) // assignment
    {
        if (this != other)
        {
            if (DataPtr =! 0) //check if poitns to something
                delete DataPtr;  //the deletes
            DataPtr = (other.DataPtr != 0) ? 
                    other.DataPtr->clone() : 0;

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
    {
        return DataPtr;
    }
    const T* operator->() const 
    // same as above but of type const
    {
        return DataPtr; 
    }

};