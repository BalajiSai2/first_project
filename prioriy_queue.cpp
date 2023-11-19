#include <iostream>
#include <vector>

using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex]) {
            largestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex]) {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != index) {
            swap(heap[index], heap[largestIndex]);
            heapifyDown(largestIndex);
        }
    }

public:
    MaxPriorityQueue() {}

    bool empty() {
        return heap.empty();
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (empty()) {
            cerr << "Priority queue is empty." << endl;
            return -1; // or some appropriate value indicating an error
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    int getMax() {
        if (empty()) {
            cerr << "Priority queue is empty." << endl;
            return -1; // or some appropriate value indicating an error
        }

        return heap[0];
    }

    void heapIncreaseKey(int index, int newValue) {
        if (index < 0 || index >= heap.size() || newValue <= heap[index]) {
            cerr << "Invalid index or new value." << endl;
            return;
        }

        heap[index] = newValue;
        heapifyUp(index);
    }

    void heapInsertKey(int value) {
        heap.push_back(value);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.insert(5);
    pq.insert(2);
    pq.insert(9);
    pq.insert(12);
    pq.insert(1);

    cout << "Max: " << pq.getMax() << endl;
    pq.heapIncreaseKey(2, 15);
    cout << "Max after increase key: " << pq.getMax() << endl;
    
    pq.heapInsertKey(20);
    cout << "Max after insert key: " << pq.getMax() << endl;

    while (!pq.empty()) {
        cout << "Extracted Max: " << pq.extractMax() << endl;
    }

    return 0;
}