#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int p;
    while (cin >> p) {
        int sum = 1;
        for (int i = 2; i < ((int)sqrt(p) + 1); i++) {
            if (p % i == 0) {
                if (i != (p / i)) {
                    sum = sum + (p / i);
                }
                sum += i;
            }
        }
        if (sum == p) {
            cout << p << " perfect" << endl;
        }
        else if (abs(p - sum) < 3) {
            cout << p << " almost perfect" << endl;
        }
        else {
            cout << p << " not perfect" << endl;
        }
    }
    return 0;
}