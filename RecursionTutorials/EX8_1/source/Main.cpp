/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {
	// FIXME: Implement recursive binary search
	if (first > last)
	{
		return -1;
	} else {
		int middleNumber = ( (first+last) / 2); //defining middleNumber variable
		if (target == items[middleNumber])
		{
			return middleNumber; //if statement ends if middleNumber equals desired number searched
		}
		//Calls function to search for the middleNumber in the lower half via recursion until middleNumber is found or not found
		if (target < items[middleNumber])
		{
			return binary_search(items, first, middleNumber - 1, target);
		} else {
			return binary_serach(items, middleNumber + 1, last, target);
		}
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size()-1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
		haystack.push_back(rand());

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		} else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}