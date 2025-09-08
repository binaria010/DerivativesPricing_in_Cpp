#pragma once

template <typename T>
class Wrapper
{
private:
    T* DataPtr;
public:
    Wrapper() //constructor
    {
        DataPtr = nullptr;  //null pointer by default
    }
    Wrapper(const T& inner)
    // typename (or class) T inner must have a clone method!
    {
        DataPtr = inner.clone();
    }
    ~Wrapper()
    {
        if (DataPtr)  // if not null
            delete DataPtr;
    }
    Wrapper(const Wrapper<T>& original)
    //copy constructor
    {
        if (original.DataPtr) //if not null then copy clone
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = nullptr;
    }
    Wrapper& operator=(const Wrapper<T>& other) // assignment
    {
        if (this != other)
        {
            if (DataPtr) // if not null check if points to something
                delete DataPtr;  //then deletes
            DataPtr = (other.DataPtr != nullptr) ? 
                    other.DataPtr->clone() : nullptr;

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