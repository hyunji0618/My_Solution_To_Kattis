#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> L1 = {1,2,2,1,-1,-2,-2,-1};
vector<int> L2 = {-2,-1,1,2,2,1,-1,-2};
string fav = "ICPCASIASG";

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool knight(vector <vector<char> >& L, string& S, int x, int y, int lo) {
    if (lo == S.size()) {
        return true;
    }
    for (int i = 0; i <=  7; i++) {
        int x_next = x + L1[i];
        int y_next = y + L2[i];
        if (!inside(x_next, y_next)) continue;
        if (L[x_next][y_next] == S[lo]) {
            if (knight(L, S, x_next, y_next, (lo+1)) == true) return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    vector <vector<char> > L(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> L[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (knight(L, fav, i, j, 0) == true) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}