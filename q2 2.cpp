#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& arr, const string& title) {
    cout << title << " [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

void dualSelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min_val = arr[i];
        int max_val = arr[i];
        int min_idx = i;
        int max_idx = i;

        for (int k = i; k <= j; k++) {
            if (arr[k] < min_val) {
                min_val = arr[k];
                min_idx = k;
            }
            if (arr[k] > max_val) {
                max_val = arr[k];
                max_idx = k;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
        if (max_idx == i) {
            max_idx = min_idx; 
        }
        if (max_idx != j) {
            swap(arr[j], arr[max_idx]);
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    printVector(arr, "Original Array: ");
    dualSelectionSort(arr);
    printVector(arr, "Sorted Array:   ");
}