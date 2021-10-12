#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

int main()
{
	OrderedArray<int> orderedArray(3, 1, false);
	UnorderedArray<int> unorderedArray(4, 1);

	orderedArray.push(3);
	orderedArray.push(53);
	orderedArray.push(83);

	orderedArray.push(23);
	orderedArray.push(83); 
	orderedArray.push(47);
	orderedArray.push(527);

	orderedArray[2] = 112;


	unorderedArray.push(29);
	unorderedArray.push(256);
	unorderedArray.push(13);
	unorderedArray.push(76);
	unorderedArray.push(40);



	orderedArray.pop();
	orderedArray.remove(2);

	cout << "Ordered array contents: ";

	for (int i = 0; i < orderedArray.getSize(); i++)
	{
		cout << orderedArray[i] << " ";
	}

	cout << endl;

	cout << "Search for 29 was found at index: ";
	cout << unorderedArray.search(29);

	cout << endl << endl;

	return 0;
}