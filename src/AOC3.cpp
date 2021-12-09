#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    std::ifstream infile;
    std::string line;
    constexpr int size = 12;
    int ones = 0;
    int zeros = 0;
    string gamma = "";
    string epsilon = "";
    int j = 0;
    #pragma GCC unroll 0
    for (int i = 0; i < size; i++) {
        infile.open("input.txt");
        while (std::getline(infile, line)) {
            if (line[i] == '1') {
                ones++;
            }
            if (line[i] == '0') {
                zeros++;
            }
            cout << "Row " << j++ << ": [" << line[i] << "]" << endl;
        }
        infile.close();
        cout << "Column " << i << ": " << ones << " ones, " << zeros << " zeros" << endl;
        if (ones > zeros) {
            gamma += '1';
            epsilon += '0';
        } else {
            gamma += '0';
            epsilon += '1';
        }
        ones = 0;
        zeros = 0;
    }
    int g = std::stoi(gamma, nullptr, 2);
    int e = std::stoi(epsilon, nullptr, 2);
    cout << "Gamma: " << gamma << " Epsilon: " << epsilon << endl;
    cout << "Gamma: " << g << " Epsilon: " << e <<  endl;
    cout << "Total: " << g * e << endl;

}
