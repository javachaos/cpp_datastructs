#ifndef HASH_H
#define HASH_H
#include <vector>
#include <set>
#include <string>

namespace Datastructures {
    template<class K, class V>
    class HashTable {
        public:
            HashTable();
            HashTable(int size);
            ~HashTable();
            void insert(K key, V value);
            V get(K key);
            void remove(K key);
            int size();
            void print();
            void print_stats();
            std::set<K> keys();
            std::vector<V> values();
            int getCollisions();
        private:
            void doubleSize();
            unsigned long int hash(int key);
            unsigned long int size_;
            void savetofile(std::vector<std::set<std::pair<K, V>>> vec, std::string filename);
            std::vector<std::set<std::pair<K, V>>> table;
            int collisions;
    };
    
} // Datastructures
#endif