#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H


#include <forward_list>
#include <iterator>
#include <stdexcept>

#include "Sequence.h"


template<typename T>
class ListSequence : public Sequence<T>
{
    std::forward_list<T> list;

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
T& ListSequence<T>::get(int index)
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");

    if (index < 0)
        throw std::out_of_range("out of range");

    if (index >= Sequence<T>::getLength())
        throw std::range_error("range error");


    auto it = list.begin();
    auto nx = std::next(it, index);

    return *nx;
}

template<typename T>
T& ListSequence<T>::getFirst()
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");


    return *(list.begin());
}

template<typename T>
T& ListSequence<T>::getLast()
{
    if (Sequence<T>::getIsEmpty())
        throw std::runtime_error("runtime error");


    auto it = list.begin();
    auto nx = std::next(it, Sequence<T>::getLength()-1);
    return *nx;
}


template<typename T>
Sequence<T>* ListSequence<T>::getSubsequence(int start, int end)
{
    if (start < 0 || end < 0)
        throw std::out_of_range("out of range");

    if (start > end)
        throw std::logic_error("logic error");

    if (start >= Sequence<T>::getLength() ||
        end >= Sequence<T>::getLength())
    {
        throw std::range_error("range error");
    }


    ListSequence<T>* sequence = new ListSequence<T>();

    for(int i = start; i <= end; ++i) {
        sequence->append(get(i));
    }

    return sequence;
}


template<typename T>
void ListSequence<T>::append(T item)
{
    if (Sequence<T>::getIsEmpty())
        list.push_front(item);
    else {
        auto it = list.begin();
        auto nx = std::next(it, Sequence<T>::getLength()-1);

        list.insert_after(nx, item);
    }

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void ListSequence<T>::prepend(T item)
{
    list.push_front(item);

    Sequence<T>::setLength(Sequence<T>::getLength()+1);
}

template<typename T>
void ListSequence<T>::insertAt(int index, T item)
{
    if (index < 0)
        throw std::out_of_range("out of range");

    if (index >= Sequence<T>::getLength())
        throw std::range_error("range error");


    if (index == 0)
        prepend(item);
    else {
        auto it = list.begin();
        auto nx = std::next(it, index-1);

        list.insert_after(nx, item);

        Sequence<T>::setLength(Sequence<T>::getLength()+1);
    }
}


template<typename T>
int ListSequence<T>::search(T item)
{
    int i = 0;

    for (T& it : list) {
        if (i == (Sequence<T>::getLength()-1) && it != item)
            return -1;
        if (it == item)
            return i;

        ++i;
    }

    return -1;
}

template<typename T>
void ListSequence<T>::remove(T item)
{
    int s = search(item);

    if (s != -1) {
        if (s == 0)
            list.pop_front();
        else {
            auto it = list.begin();
            auto nx = std::next(it, s-1);

            list.erase_after(nx);
        }

        Sequence<T>::setLength(Sequence<T>::getLength()-1);
    }
}


#endif // LISTSEQUENCE_H
