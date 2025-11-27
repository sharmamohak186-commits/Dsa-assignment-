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

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> original = {5, 2, 8, 1, 9, 4, 7, 3};
    vector<int> arr;
    arr = original;
    quickSort(arr, 0, arr.size() - 1);
    printVector(arr, "Quick Sort: ");
}