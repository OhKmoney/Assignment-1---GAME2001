#pragma once
#include <cassert>

template<class T>

class BaseArray
{
public:
	BaseArray(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{

		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; 
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0 ? growBy : 0));
		}
	}

	~BaseArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	//Insertion handled differently between Ordered and Unordered
	
	//Deletion
	void pop()
	{
		if (m_numElements > 0) m_numElements--;
	}
	void remove(int index)
	{
		if (index >= m_numElements)
		{
			return;
		}
		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	//Search
	int search(T val)
	{
		assert(m_array != nullptr);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	//Overload
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	//Clear
	void clear()
	{
		m_numElements = 0;
	}
	//Getters and Setters
	int getSize() 
	{ 
		return m_numElements; 
	}
	int getMaxSize()
	{ 
		return m_maxSize;
	}
	int getGrowSize() 
	{ 
		return m_growSize; 
	}
	void setGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

protected:
	//Expansion
	bool expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}
		//New array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);
		//Move array contents to new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		//Delete the old array
		delete[] m_array;

		//Clean up variable assignments
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		//CHANGE 1, Simple change to make m_growSize increase exponentially with each call
		m_growSize = m_growSize << 1;
		//Can use print statement below to track m_growSize after each exponential change
		//std::cout << "m_growSize after adjust: " << m_growSize << std::endl;
		return true;
	}

protected:
	//Variables
	T* m_array; //Pointer to beginning of array

	int m_maxSize; //Max array size
	int m_growSize; //Amount the array can grow through expansion
	int m_numElements; //Number of items in array


};;