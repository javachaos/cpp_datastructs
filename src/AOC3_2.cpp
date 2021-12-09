#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;
    vector<string> input;
    while (getline(file, line)) {
        input.push_back(line);
    }
    
    return 0;
}