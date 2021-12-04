
#ifndef BST_H
#define BST_H
#include <vector>

namespace Datastructures {
    template<class K, class V>
    class Node {
    public:
        Node(K key, V value, int size) : key(key), value(value), size(size) {};
    private:
        K key;
        V value;
        int size;
        Node* left;
        Node* right;
    };

    template<class K, class V>
    class BST {
    public:
        BST();
        ~BST();
        void put(K key, V value);
        V get(K key);
        V min();
        V max();
        int height();
        void print();
        int size();
        bool contains(K key);
        bool isEmpty();
        void deleteMin();
        void deleteMax();
        void deleteKey(K key);
        K floor(K key);
        K floor2(K key);
        K ceiling(K key);
        K select(int rank);
        int rank(K key);
        vector<K> keys();
        vector<K> keys(K lo, K hi);
        vector<V> values();
        vector<V> values(K lo, K hi);
        int size(K lo, K hi);
    private:
        Node<K, V>* root;
        void put(Node<K, V>* node, K key, V value);
        void remove(Node<K, V>* node, K key);
        Node<K, V>* get(Node<K, V>* node, K key);
        Node<K, V>* deleteMin(Node<K, V>* node);
        Node<K, V>* deleteMax(Node<K, V>* node);
        Node<K, V>* deleteKey(Node<K, V>* node, K key);
        int size(Node<K, V>* node);
        int height(Node<K, V>* node);
        void print(Node<K, V>* node);
        void clear(Node<K, V>* node);
        Node<K, V>* min(Node<K, V>* node);
        Node<K, V>* max(Node<K, V>* node);
    };
}

#endif