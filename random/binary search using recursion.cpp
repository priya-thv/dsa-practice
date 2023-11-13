#include<bits/stdc++.h>
using namespace std;

bool binary(int *arr, int start, int end, int key) {
    if (start > end) {
        return false;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        return true;
    } else if (key > arr[mid]) {
        return binary(arr, mid + 1, end, key);
    } else {
        return binary(arr, start, mid - 1, key);
    }
}

int main() {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int key = 8;
    int size = 8;

    if (binary(arr, 0, size - 1, key)) {
        cout << "Key found in the array." << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
