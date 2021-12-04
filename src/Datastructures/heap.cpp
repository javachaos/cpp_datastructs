#include "heap.h"
#include <iostream>
#include <ostream>
#include <limits>

namespace Datastructures {
//Works
    template <class T> 
    Heap<T>::Heap(int s) :  length(0), size(s) {
        if (size <= 0) {
            throw std::invalid_argument("Heap size must be greater than 0");
        }
        heap = new T[s];
    }
//Works
    template <class T>
    Heap<T>::~Heap() {
        delete[] heap;
    }

    template <class T>
    int Heap<T>::parent(int n) {
        return n >> 1;
    }

    template <class T>
    int Heap<T>::left(int n) {
        return n << 1;
    }

    template <class T>
    int Heap<T>::right(int n) {
        return (n << 1) + 1;
    }

    template <class T>
    void Heap<T>::heap_increase_key(T *heap, int index, T key) {
        if (key < heap[index]) {
            throw std::invalid_argument("New key is smaller than current key");
        }
        heap[index] = key;
        while (index > 1 && heap[parent(index)] < heap[index]) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    template <class T>
    void Heap<T>::heap_sort() {
        for (int i = this->size; i >= 2; i--) {
            swap(1, i);
            this->length--;
            max_heapify(this->heap, 1);
        }
    }

    template <class T>
    void Heap<T>::swap(int i, int j) {
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    template <class T>
    void Heap<T>::max_heapify(T *heap, int i) {
        int l = left(i);
        int r = right(i);
        int largest = 0;
        if (l <= length && this->heap[l] > this->heap[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if ( r <= length && this->heap[r] > this->heap[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(i, largest);
            max_heapify(heap, largest);
        }
    }

    template <class T>
    void Heap<T>::build_heap() {
        for (int i = length / 2; i >= 1; i--) {
            max_heapify(heap, i);
        }
    }

    template <class T>
    T Heap<T>::heap_extract_max() {
        T max = this->heap[1];
        this->heap[1] = this->heap[this->length];
        this->length--;
        max_heapify(heap, 1);
        return max;
    }

    template <class T>
    void Heap<T>::max_heap_insert(T key) {
        this->length++;
        this->heap[this->length] = std::numeric_limits<T>::min();
        heap_increase_key(heap, this->length, key);
    }

//Works
    template <class T>
    void Heap<T>::print() {
        for (int i = 1; i <= this->length; i++) {
            std::cout << this->heap[i] << " ";
        }
        std::cout << std::endl;
    }

}