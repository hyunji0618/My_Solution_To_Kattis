#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases, n, m;
    cin >> cases;
    vector <vector<int> > lock(31, vector<int>(31, 1));
    for (int i = 2; i < 31; i++) {
        for (int j = 2; j < i + 1; j++) {
            lock[i][j] = lock[i-1][j-1] + lock[i-1][j];
        }
    }
    for (int i = 0; i < cases; i++) {
        cin >> n >> m;
        cout << lock[n][m] << endl;
    }
    return 0;
}