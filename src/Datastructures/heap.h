#ifndef HEAP_H
#define HEAP_H
#include <vector>

namespace Datastructures {
    template<class T>
    class Heap {
    public:
        Heap(int size);
        ~Heap();
        T heap_extract_max();
        void max_heap_insert(T key);
        void print();
        void heap_sort();
        void clear();
        void build_heap();
        int length;
        T *heap;
    private:
        int size;
        int parent(int n);
        int left(int n);
        int right(int n);
        void swap(int i, int j);
        void max_heapify(T *heap, int index);
        void heap_increase_key(T *heap, int index, T key);
    };
}

#endif