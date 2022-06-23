#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int n;
    int first, other;
    int g;
    cin >> n;
    cin >> first;
    while (n > 1) {
        n--;
        cin >> other;
        g = gcd(first, other);
        cout << first/g << '/' << other/g << endl;
    }
    return 0;
}