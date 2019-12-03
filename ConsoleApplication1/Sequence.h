#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <iostream>
#include <stdexcept>


template<typename T>
class Sequence
{
    int Length = 0;
    bool Empty = true;

public:
    virtual ~Sequence() = default;

    int getLength() const;
    bool getIsEmpty() const;

    void print() const;
	


protected:
    void setLength(int length);
};


template<typename T>
int Sequence<T>::getLength() const
{
    return Length;
}

template<typename T>
bool Sequence<T>::getIsEmpty() const
{
    return Empty;
}









template<typename T>
void Sequence<T>::setLength(int length)
{
    if (length < 0)
        throw std::length_error("length error");


    Length = length;

    if (length == 0)
        Empty = true;
    else
        Empty = false;
}



#endif // SEQUENCE_H
