// Priority Queue implementation using array
// Program to showcase enqueue and dequeue operations on a priority queue
// 04.09.2024

#include <iostream>

const int MAX_SIZE = 20;

class PriorityQueue {
public:
    struct Element {
        int value;
        int priority;
    };

    Element arr[MAX_SIZE];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void enqueue(int value, int priority) {
        if (size == MAX_SIZE) {
            std::cout << "Queue is full. Cannot enqueue more elements." << std::endl;
            return;
        }

        Element newElement;
        newElement.value = value;
        newElement.priority = priority;

        int i = size - 1;
        arr[i + 1] = newElement;
        size++;
    }

    void sort() {
        for (int i = 1; i < size; i++) {
            Element key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j].priority > key.priority) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    int dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty. Cannot dequeue any elements." << std::endl;
            return -1; 
        }

        int dequeuedValue = arr[0].value;

        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }

        size--;

        return dequeuedValue;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue('A', 35);
    pq.enqueue('B', 42);
    pq.enqueue('C', 60);
    pq.enqueue('D', 82);
    pq.enqueue('E', 20);

    std::cout << "Elements before sorting: ";
    for (int i = 0; i < pq.size; i++) {
        std::cout << (char)pq.arr[i].value << " ";
    }
    std::cout << std::endl;

    pq.sort();

    std::cout << "Elements after sorting: ";
    for (int i = 0; i < pq.size; i++) {
        std::cout << (char)pq.arr[i].value << " ";
    }
    std::cout << std::endl;

    std::cout << "Dequeued element: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << (char)pq.dequeue() << " ";
    }
    return 0;
}
