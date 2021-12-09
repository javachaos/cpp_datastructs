#include <gmpxx.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

mpz_class submarine(vector<int> input, int num_steps) {
    mpz_class fish[9];
    // fish[0] = 0;
    // fish[1] = 0;
    // fish[2] = 0;
    // fish[3] = 0;
    // fish[4] = 0;
    // fish[5] = 0;
    // fish[6] = 0;
    // fish[7] = 0;
    // fish[8] = 0;

    for (unsigned long int i = 0; i < input.size(); i++) {
        fish[input[i]]++;
    }
    
    int j = 0;
    mpz_class tmp;
    for (int g = 0; g < num_steps; g++) {
        tmp = fish[0];
        fish[0] = fish[1];
        fish[1] = fish[2];
        fish[2] = fish[3];
        fish[3] = fish[4];
        fish[4] = fish[5];
        fish[5] = fish[6];
        fish[6] = tmp + fish[7];
        fish[7] = fish[8];
        fish[8] = tmp;
    }
    mpz_class total;
    for (unsigned long int k = 0; k < 9; k++) {
        total += fish[k];
    }
    return total;
}

// int main(int argc, char *argv[]) {
//     vector<int> v = { 3,1,4,2,1,1,1,1,1,1,1,4,1,4,1,2,1,1,2,1,3,4,5,1,1,4,1,3,3,1,1,1,1,3,3,1,3,3,1,5,5,1,1,3,1,1,2,1,1,1,3,1,4,3,2,1,4,3,3,1,1,1,1,5,1,4,1,1,1,4,1,4,4,1,5,1,1,4,5,1,1,2,1,1,1,4,1,2,1,1,1,1,1,1,5,1,3,1,1,4,4,1,1,5,1,2,1,1,1,1,5,1,3,1,1,1,2,2,1,4,1,3,1,4,1,2,1,1,1,1,1,3,2,5,4,4,1,3,2,1,4,1,3,1,1,1,2,1,1,5,1,2,1,1,1,2,1,4,3,1,1,1,4,1,1,1,1,1,2,2,1,1,5,1,1,3,1,2,5,5,1,4,1,1,1,1,1,2,1,1,1,1,4,5,1,1,1,1,1,1,1,1,1,3,4,4,1,1,4,1,3,4,1,5,4,2,5,1,2,1,1,1,1,1,1,4,3,2,1,1,3,2,5,2,5,5,1,3,1,2,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,4,1,4,2,1,3,4,1,1,1,2,3,1,1,1,4,1,2,5,1,2,1,5,1,1,2,1,2,1,1,1,1,4,3,4,1,5,5,4,1,1,5,2,1,3 };
//     //vector<unsigned long int> v = {3,4,3,1,2};
//     //cout << "Pick a number of days to simulate: ";
//     unsigned long int n = atoi(argv[1]);
//     //cin >> n;
//     cout << "Num days: ";
//     cout << n << " " << endl << submarine(v, n) << endl;
//     cout << "Done." << endl;
// }