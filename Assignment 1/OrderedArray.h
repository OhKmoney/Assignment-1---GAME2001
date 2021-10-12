#pragma once
#include "BaseArray.h"
using namespace std;
template<class T>
class OrderedArray : public BaseArray<T>
{
public:
	//CHANGE 2, Ordered Array constructor gets a new parameter, boolean allowDuplicate is given to let the user choose if duplicate data is allowed into the array. More comments ahead to explain process
	OrderedArray(int size, int growBy, bool allowDuplicateData) : BaseArray<T>(size, growBy) 
	{	
		m_allowDuplicateData = allowDuplicateData;
	}

	virtual void push(T val)
	{
		assert(this->m_array != nullptr);

		int i, k; // i - Index to be inserted. k - Used for shifting purposes
		bool duplicateFound = false;

		if (!m_allowDuplicateData)
		{
			//Check is run only if the user applies 'false' for allowDuplicateData.
			for (i = 0; i < this->m_numElements; i++)
			{
				if (this->m_array[i] == val)
				{
					duplicateFound = true;
					std::cout << "Duplicate data is not allowed in this array. Value " << val << " matches element in array at index " << i << std::endl;
					break;
				}
			}
		}
		//If duplicate is found, the boolean duplicateFound is flagged as true (defaults to false), preventing the code for push to ever be run.
		if (!duplicateFound)
		{
			if (this->m_numElements >= this->m_maxSize)
			{

				this->expand();
			}

			for (i = 0; i < this->m_numElements; i++)
			{
				if (this->m_array[i] > val)
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
	}
private:
	bool m_allowDuplicateData = true;
};