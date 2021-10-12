#pragma once
#include "BaseArray.h"
using namespace std;
template<class T>
class OrderedArray : public BaseArray<T>
{
public:
	OrderedArray(int size, int growBy) : BaseArray<T>(size, growBy) {}

	virtual void push(T val)
	{
		assert(this->m_array != nullptr);

		if (this->search(val) == -1)
		{
			cout << "The number is already in the array" << endl;
		}
		else if (this->m_numElements >= this->m_maxSize)
		{

			this->expand();
		}
		int i, k;
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] >= val)
			{
				break;
			}
		}
		for (k = this->m_numElements; k > i; k--)
		{
			this->m_array[k] = this->m_array[k - 1];
		}
		this->m_array[i] = val;
		this->m_numElements++;
	}
private:

};