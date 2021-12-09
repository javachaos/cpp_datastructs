// #include "heap.h"
// #include "heap.cpp"
// #include "AOC6.cpp"
// #include "Hash.h"
// #include "Hash.cpp"
// #include "MathFun.cpp"
// #include <boost/range/irange.hpp>
// #include <boost/timer/timer.hpp>
// using std::cout;
// using std::endl;
// using namespace Datastructures;

// int main(void) {
//     ofstream myfile;
//     myfile.open("hashtable.txt");
//     unsigned long int j = 0;
//     cout << "Hashtable size: ";
//     cin >> j;
//     cout << "Print output to stdout? (y/n) ";
//     char c;
//     cin >> c;
//     bool print = (c == 'y');
//     HashTable<int, int> ht;
//     std::vector<int> vec;
//     myfile << "-----------------------------------------" << endl;
//     myfile << "j = " << j << endl;
        
//         std::cout << "Inserting " << j << " elements" << endl;
//         for (unsigned long int i = 0; i < j; i++) {
//             int v = i * rand() % 1000000;
//             ht.insert(i, v);
//             vec.push_back(v);
//         //    std::cout << "Inserted: " << v << endl;
//         }
//         myfile << "Collisions: " << ht.getCollisions() << std::endl;
//         myfile << "Load factor: " << (float) ht.getCollisions() / ht.size() << std::endl;
//         myfile << "Size: " << ht.size() << std::endl;
//         myfile << "Number of buckets: " << ht.size() << std::endl;
//         myfile << "-----------------------------------------" << endl;
//         // std::cout << "-----------------------------------------" << endl;
//         // for (auto k : ht.keys()) {
//         //     std::cout << "Key: " << k << endl;
//         // }
//         // for (auto v : ht.values()) {
//         //     std::cout << "Value: " << v << endl;
//         // }
//         //ht.print();
//         if (ht.getCollisions() > 0) {
//             cout << "Failed collision: " << ht.getCollisions() << endl;
//         }
//         if (print) {
//             ht.print();
//         }
//         unsigned long int sum = 0;
//         auto r = boost::irange(0, (int) j);
//         boost::timer::auto_cpu_timer t;
//         for (int t : r) {
//             sum += ht.get(t);
//         }
//         std::cout << "Sum1: " << sum << endl;
//         boost::timer::auto_cpu_timer t2;
//         sum = 0;
//         for (auto t : r) {
//             sum += vec[t];
//         }
//         std::cout << "Sum2: " << sum << endl;

//         std::cout << "Value: " << ht.get(j-1) << endl;
//     ht.~HashTable();
//     myfile.close();
//     return 0;
// }
