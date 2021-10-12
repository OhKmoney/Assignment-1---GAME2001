#pragma once
#include "BaseArray.h"

template <class T>
class UnorderedArray : public BaseArray<T>
{
public:
	UnorderedArray(int size, int growBy) : BaseArray<T>(size, growBy) {}
	virtual void push(T value)
	{
		if (this->m_numElements >= this->m_maxSize)
		{

			this->expand();
		}
		this->m_array[this->m_numElements] = value;
		this->m_numElements++;
	}

private:

};