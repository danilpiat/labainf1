#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H


#include <stdexcept>

#include "Sequence.h"


template<typename T>
class ArraySequence : public Sequence<T>
{
    T* arr;

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

protected:
    T* reallocate(T* ptr, int len);
};


template<typename T>
T& ArraySequence<T>::get(int index)
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");

    if (index < 0)
        throw std::out_of_range("out of range");

    if (index >= Sequence<T>::getLength())
        throw std::range_error("range error");


    return arr[index];
}

template<typename T>
T& ArraySequence<T>::getFirst()
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");


    return *arr;
}

template<typename T>
T& ArraySequence<T>::getLast()
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");


    return arr[Sequence<T>::getLength()-1];
}


template<typename T>
Sequence<T>* ArraySequence<T>::getSubsequence(int start, int end)
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");

    if (start < 0 || end < 0 || start > end)
        throw std::logic_error("logic error");

    if (start >= Sequence<T>::getLength() ||
        end >= Sequence<T>::getLength())
    {
        throw std::range_error("range error");
    }


    ArraySequence<T>* sequence = new ArraySequence<T>();

    for(int i = start; i <= end; ++i) {
        sequence->append(get(i));
    }

    return sequence;
}


template<typename T>
void ArraySequence<T>::append(T item)
{
    arr = reallocate(arr, Sequence<T>::getLength()+1);

    arr[Sequence<T>::getLength()] = item;

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void ArraySequence<T>::prepend(T item)
{
    arr = reallocate(arr, Sequence<T>::getLength()+1);

    if (Sequence<T>::getLength() > 0)
        for (int i = Sequence<T>::getLength(); i > 0; --i)
            arr[i] = arr[i-1];

    *arr = item;

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void ArraySequence<T>::insertAt(int index, T item)
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");

    if (index < 0)
        throw std::out_of_range("out of range");

    if (index >= Sequence<T>::getLength())
        throw std::range_error("range error");


    arr = reallocate(arr, Sequence<T>::getLength()+1);

    for (int i = Sequence<T>::getLength(); i > index; --i)
        arr[i] = arr[i-1];

    arr[index] = item;
}


template<typename T>
int ArraySequence<T>::search(T item)
{
    for (int i = 0; i < Sequence<T>::getLength(); ++i) {
        if (i == (Sequence<T>::getLength()-1) && arr[i] != item)
            return -1;
        if (arr[i] == item)
            return i;
    }

    return -1;
}

template<typename T>
void ArraySequence<T>::remove(T item)
{
    int s = search(item);

    if (s != -1) {
        if (s != Sequence<T>::getLength()-1)
            for (int i = s+1; i < Sequence<T>::getLength(); ++i)
                arr[i-1] = arr[i];

        arr = reallocate(arr, Sequence<T>::getLength()-1);

        Sequence<T>::setLength(Sequence<T>::getLength()-1);
    }
}


template<typename T>
T* ArraySequence<T>::reallocate(T *ptr, int len)
{
    if (len == 0)
    {
        delete[] ptr;
        return nullptr;
    }

    T* p = new T[len];

    int realLen = Sequence<T>::getLength();

    for (int i = 0; i < ((len > realLen) ? realLen : len); ++i)
        p[i] = ptr[i];

    delete[] ptr;

    return p;
}


#endif // ARRAYSEQUENCE_H
