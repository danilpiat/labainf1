#ifndef VECTORSEQUENCE_H
#define VECTORSEQUENCE_H


#include <stdexcept>
#include <vector>

#include "Sequence.h"


template<typename T>
class VectorSequence : public Sequence<T>
{
    std::vector<T> vec;

public:
    T& get(int index);
    T& getFirst();
    T& getLast();

    Sequence<T>* getSubsequence(int start, int end);

    void append(T item);
    void prepend(T item);
    void insertAt(int index, T item);

    int search(T item);
    void remove(T item);
};


template<typename T>
T& VectorSequence<T>::get(int index)
{
    return vec.at(index);
}

template<typename T>
T& VectorSequence<T>::getFirst()
{
    if (Sequence<T>::isEmpty())
        throw std::runtime_error("runtime error");


    return vec.front();
}

template<typename T>
T& VectorSequence<T>::getLast()
{
    if (Sequence<T>::isEmpty())
        throw std::runtime_error("runtime error");


    return vec.back();
}


template<typename T>
Sequence<T>* VectorSequence<T>::getSubsequence(int start, int end)
{
    if (start < 0 || end < 0 || start > end)
        throw std::logic_error("logic error");

    if (start >= Sequence<T>::getLength() ||
        end >= Sequence<T>::getLength())
    {
        throw std::range_error("range error");
    }


    VectorSequence<T>* sequence = new VectorSequence<T>();

    for(int i = start; i <= end; ++i) {
        sequence->append(get(i));
    }

    return sequence;
}


template<typename T>
void VectorSequence<T>::append(T item)
{
    vec.push_back(item);

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void VectorSequence<T>::prepend(T item)
{
    vec.insert(vec.begin(), item);

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void VectorSequence<T>::insertAt(int index, T item)
{
    if (index < 0)
        throw std::out_of_range("out of range");

    if (index >= Sequence<T>::getLength())
        throw std::range_error("range error");


    vec.insert(vec.begin() + index, item);

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}


template<typename T>
int VectorSequence<T>::search(T item)
{
    int i = 0;

    for (T& it : vec) {
        if (i == (Sequence<T>::getLength()-1) && it != item)
            return -1;
        if (it == item)
            return i;

        ++i;
    }

    return -1;
}

template<typename T>
void VectorSequence<T>::remove(T item)
{
    int s = search(item);

    if (s != -1) {
        vec.erase(vec.begin()+s);

        Sequence<T>::setLength(Sequence<T>::getLength()-1);
    }
}


#endif // VECTORSEQUENCE_H
