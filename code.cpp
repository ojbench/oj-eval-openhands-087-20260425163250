
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int D;
    long long n;
    if (!(cin >> D >> n)) return 0;

    // 1. Find the position of the n-th ball
    long long current_n = n;
    int pos = 1;
    for (int i = 1; i < D; ++i) {
        if (current_n % 2 != 0) {
            pos = 2 * pos;
            current_n = (current_n + 1) / 2;
        } else {
            pos = 2 * pos + 1;
            current_n = current_n / 2;
        }
    }
    cout << pos << endl;

    // 2. Find the states of all leaf nodes
    // Total nodes in the tree is 2^D - 1
    // Leaves are from index 2^(D-1) to 2^D - 1
    int num_nodes = 1 << D;
    vector<long long> count(num_nodes, 0);
    count[1] = n;
    for (int i = 1; i < (1 << (D - 1)); ++i) {
        count[2 * i] = (count[i] + 1) / 2;
        count[2 * i + 1] = count[i] / 2;
    }

    for (int i = (1 << (D - 1)); i < (1 << D); ++i) {
        cout << (count[i] % 2);
        if (i < (1 << D) - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
