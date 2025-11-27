#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
public:
    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0, n = heap.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    int top() {
        return heap.empty() ? -1 : heap[0];
    }
};

int main() {
    PriorityQueue pq;
    pq.push(5);
    pq.push(10);
    pq.push(1);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}
