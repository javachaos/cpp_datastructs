#include "Hash.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#define LARGE_PRIME 1610612741
#define LARGE_PRIME_2 2147483647
#define LARGE_PRIME_3 1073741823
#define LARGE_PRIME_4 536870909
using namespace std;
namespace Datastructures {
    
    template <class K, class V>
    HashTable<K, V>::HashTable() : size_(2), table(2), collisions(0) {
        if (size_ < 1) {
            throw invalid_argument("HashTable size must be greater than 0");
        }
    } 

    template <class K, class V>
    HashTable<K, V>::HashTable(int size) : size_(size * 2), table(size_), collisions(0) {
        if (size_ < 1) {
            throw invalid_argument("HashTable size must be greater than 0");
        }
    } 

    template <class K, class V>
    std::set<K> HashTable<K, V>::keys() {
        std::set<K> keys;
        for (unsigned long int i = 0; i < size_; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                keys.insert(it->first);
            }
        }
        return keys;
    }

    template <class K, class V>
    std::vector<V> HashTable<K, V>::values() {
        vector<V> values;
        for (unsigned long int i = 0; i < size_; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                values.push_back(it->second);
            }
        }
        return values;
    }

    template <class K, class V>
    HashTable<K, V>::~HashTable() {
        this->table.clear();
        this->table.shrink_to_fit();
    }

    template <class K, class V>
    void HashTable<K,V>::savetofile(std::vector<std::set<std::pair<K, V>>> table, std::string filename) {
        ofstream myfile;
        if (filename.empty() || filename == "") {
            myfile.open("hashtable.txt");
        } else {
            myfile.open(filename);
        }
        for (unsigned long int i = 0; i < size_; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                myfile << it->first << " " << it->second << endl;
            }
        }
        myfile.close();
    }

    template <class K, class V>
    void HashTable<K,V>::doubleSize() {
        vector<set<pair<K, V>>> oldTable = this->table;
        table.clear();
        size_ = size_ * 2;
        table.resize(size_);
        #pragma omp parallel for
        for (unsigned long int i = 0; i < this->size_ / 2; i++) {
            auto bucket = oldTable[i];
            for (auto it = bucket.begin(); it != bucket.end(); it++) {
                this->insert(it->first, it->second);
            }
        }
        oldTable.clear();
        oldTable.shrink_to_fit();
    }

    template <class K, class V>
    unsigned long int HashTable<K,V>::hash(int key) {
        return ((LARGE_PRIME_2 * key + LARGE_PRIME_3) % LARGE_PRIME_2) % this->size_;
    }

    template <class K, class V>
    void HashTable<K, V>::insert(K key, V value) {
        int index = this->hash(key);
        std::set<std::pair<K, V>> bucket = this->table[index];
        for (auto p : bucket) {
            if (p.first == key) {
                p.second = value;
                this->table[index] = bucket;
                return;
            }
        }
        auto p = std::make_pair(key, value);
        if (bucket.size() == 0) {
            bucket.insert(p);
            this->table[index] = bucket;
            return;
        }
        if (bucket.size() == 1) {
            collisions++;
            bucket.clear();
            doubleSize();
            bucket.insert(p);
            this->table[index] = bucket;
            return;
        }
    }

    template <class K, class V>
    V HashTable<K, V>::get(K key) {
        int index = this->hash(key);
        std::set<std::pair<K, V>> bucket = this->table[index];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return (V) 0;
    }

    template <class K, class V>
    void HashTable<K, V>::remove(K key) {
        int index = this->hash(key);
        auto bucket = this->table[index];
         for (auto it = bucket.begin(); it != bucket.end(); it++) {
             if (it->first == key) {
                 bucket.erase(it);
                 this->table[index] = bucket;
                 return;
             }
        }
    }

    template <class K, class V>
    void HashTable<K, V>::print() {
        int collisions = 0;
        for (unsigned long int i = 0; i < this->size_; i++) {
            auto bucket = this->table[i];
            std::cout << "Bucket " << i << ": size(" << bucket.size() << ") ";
            for (auto it = bucket.begin(); it != bucket.end(); it++) {
                std::cout << it->first << " " << it->second << " ";
            }
            if (bucket.size() > 1) {
                collisions++;
            }
            std::cout << std::endl;
        }
        std::cout << "Collisions: " << collisions << std::endl;
        std::cout << "Load factor: " << (float) collisions / this->size_ << std::endl;
        std::cout << "Size: " << this->size_ << std::endl;
        std::cout << "Number of buckets: " << this->table.size() << std::endl;
    }

    template <class K, class V>
    int HashTable<K, V>::getCollisions() {
        return collisions;
    }

    template <class K, class V>
    int HashTable<K, V>::size() {
        return this->size_;
    }

    template <class K, class V>
    void HashTable<K, V>::print_stats() {
        std::cout << "Collisions: " << getCollisions() << std::endl;
        std::cout << "Load factor: " << (float) collisions / this->size_ << std::endl;
        std::cout << "Size: " << this->size_ << std::endl;
        std::cout << "Number of buckets: " << this->table.size() << std::endl;
    }

}