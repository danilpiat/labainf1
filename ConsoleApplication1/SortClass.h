#pragma once
#include "Sequence.h"
#include "NodeSequence.h"

class SortClass 
{
public:
	SortClass();
	~SortClass();
	template<typename TElement, template <typename ...> class Container,class F>
	void bubbleSort(Container<TElement> *array, F compare);
	template<typename TElement, template <typename ...> class Container>
	void shellSort(Container<TElement>& vector, int len);


	
};

template<typename TElement, template <typename ...> class Container,class F>
void bubbleSort(Container<TElement>* array, F compare)
{
	TElement tmp;
	int size = array->getLength();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (compare(array[i], array[j]))
			{
				tmp = array[i];//array.swap что то такое
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
};


template<typename TElement, template <typename ...> class Container>
void SortClass::shellSort(Container<TElement>& vector, int len)
{
	int step = len / 2;
	while (step > 0)
	{
		int i, j;
		for (i = step; i < len; i++)
		{
			TElement value = vector[i];
			for (j = i - step; (j >= 0) && (vector[j] > value); j -= step)
				vector[j + step] = vector[j];
			vector[j + step] = value;
		}
		step /= 2;
	}
}

