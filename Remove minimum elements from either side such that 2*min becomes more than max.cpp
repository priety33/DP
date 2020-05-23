// A O(n*n) solution to find the minimum of elements to 
// be removed 
#include <iostream> 
#include <climits> 
using namespace std; 

// Returns the minimum number of removals from either end 
// in arr[l..h] so that 2*min becomes greater than max. 
int minRemovalsDP(int arr[], int n) 
{ 
	// Initialize starting and ending indexes of the maximum 
	// sized subarray with property 2*min > max 
	int longest_start = -1, longest_end = 0; 

	// Choose different elements as starting point 
	for (int start=0; start<n; start++) 
	{ 
		// Initialize min and max for the current start 
		int min = INT_MAX, max = INT_MIN; 

		// Choose different ending points for current start 
		for (int end = start; end < n; end ++) 
		{ 
			// Update min and max if necessary 
			int val = arr[end]; 
			if (val < min) min = val; 
			if (val > max) max = val; 

			// If the property is violated, then no 
			// point to continue for a bigger array 
			if (2 * min <= max) break; 

			// Update longest_start and longest_end if needed 
			if (end - start > longest_end - longest_start || 
				longest_start == -1) 
			{ 
				longest_start = start; 
				longest_end = end; 
			} 
		} 
	} 

	// If not even a single element follow the property, 
	// then return n 
	if (longest_start == -1) return n; 

	// Return the number of elements to be removed 
	return (n - (longest_end - longest_start + 1)); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << minRemovalsDP(arr, n); 
	return 0; 
}
