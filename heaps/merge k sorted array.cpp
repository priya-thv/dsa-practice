#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Struct to represent elements in the arrays with their indices
struct ArrayElement {
    int val; // Value of the element
    int arrayIdx; // Index of the array containing this element
    int idx; // Index within the array

    // Constructor to initialize the struct
    ArrayElement(int v, int a, int i) : val(v), arrayIdx(a), idx(i) {}

    // Overloaded '>' operator to compare ArrayElements
    bool operator>(const ArrayElement& other) const {
        return val > other.val;
    }
};

// Function to merge k sorted arrays using min heap
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> result; // To store the merged array
    // Min heap to store ArrayElements (minimum element from each array)
    priority_queue<ArrayElement, vector<ArrayElement>, greater<ArrayElement>> minHeap;

    // Push the first element of each array into the min heap along with their array indices
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(ArrayElement(arrays[i][0], i, 0)); // Create ArrayElement and push to heap
        }
    }

    // Merge the arrays until the min heap is empty
    while (!minHeap.empty()) {
        ArrayElement minElement = minHeap.top(); // Get the minimum element from the heap
        minHeap.pop(); // Remove the minimum element from the heap
        result.push_back(minElement.val); // Add the minimum element to the result array

        // Check if there's another element in the same array, push it to the heap
        if (minElement.idx + 1 < arrays[minElement.arrayIdx].size()) {
            minHeap.push(ArrayElement(arrays[minElement.arrayIdx][minElement.idx + 1],
                                      minElement.arrayIdx, minElement.idx + 1));
        }
    }

    return result; // Return the merged array
}

// Main function
int main() {
    int k;
    cout << "Enter the number of sorted arrays: ";
    cin >> k; // Input the number of arrays

    vector<vector<int>> k_sorted_arrays; // Vector to store the arrays
    for (int i = 0; i < k; ++i) {
        int size;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> size; // Input size of the current array

        vector<int> arr(size); // Create a vector of the given size
        cout << "Enter elements of array " << i + 1 << ": ";
        for (int j = 0; j < size; ++j) {
            cin >> arr[j]; // Input elements of the array
        }
        k_sorted_arrays.push_back(arr); // Add the array to the vector of arrays
    }

    // Merge the sorted arrays
    vector<int> merged_array = mergeKSortedArrays(k_sorted_arrays);

    // Display the merged array
    cout << "Merged Array: ";
    for (int num : merged_array) {
        cout << num << " "; // Print each element of the merged array
    }
    cout << endl;

    return 0; // Return 0 to indicate successful execution
}
