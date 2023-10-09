#include <iostream>
#include <queue>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    // Time Complexity: O(logn)
    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // Time Complexity: O(logn)
    void deletefromheap() {
        if (size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }

        // put last element into the first index
        arr[1] = arr[size];

        // remove last element
        size--;

        // take the root node to its correct position
        int i = 1;
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void maxheapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxheapify(arr, n, largest);
    }
}

void minheapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        minheapify(arr, n, smallest);
    }
}

// Time Complexity: O(logn)
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        maxheapify(arr, n, i);
    }

    // Heap sort
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromheap();
    h.print();

    int arr[6] = {54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
    cout << "printing the max heap array now " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = n / 2 - 1; i >= 0; i--) {
        minheapify(arr, n, i);
    }
    cout << "printing the min heap array now " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "printing the sorted array now " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "using the Priority Queue here" << endl;

    //maxheap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at Top using max heap priority queue " << pq.top() << endl;
    pq.pop();

    cout<< "element at Top using max heap priority queue " << pq.top() << endl;
    cout<< "using max heap priority queue Size is " << pq.size() << endl;

    if(pq.empty())
    {
        cout << "Empty Priority Queue using max heap " << endl;
    }
    else
    {
        cout << "Priorty Queue is not Empty using max heap " << endl;
    }

    //minheap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "element at Top using min heap priority queue " << minheap.top() << endl;
    minheap.pop();

    cout<< "element at Top using min heap priority queue " << minheap.top() << endl;
    cout<< "using min heap priority queue Size is " << minheap.size() << endl;

    if(minheap.empty())
    {
        cout << "Empty Priority Queue using min heap " << endl;
    }
    else
    {
        cout << "Priorty Queue is not Empty using min heap " << endl;
    }
    return 0;
}
