#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    unsigned long int x = 0; 
    unsigned long int y = 0;
    unsigned long int aim = 0;
    string direction;
    string magnitude;

    std::ifstream infile("input.txt");
    while (infile >> direction >> magnitude) {
        switch(direction[0]) {
            case 'd':
                //y += stoi(magnitude);
                aim += stoi(magnitude);
                break;
            case 'u':
                //y -= stoi(magnitude);
                aim -= stoi(magnitude);
                break;
            case 'f':
                x += stoi(magnitude);
                y += aim * stoi(magnitude);
                break;
        }
    }

    cout << "x: " << x << " y: " << y << endl;
    cout << x * y << endl;

}