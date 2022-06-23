#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class cable_connection {
    vector <int> v;

    public:
    cable_connection(int N) {
        v = vector <int> (N);
        for (int i = 0; i < N; i++) {
            v[i] = i;
        }
    }

    int find(int x) {
        if (v[x] == x) return x;
        v[x] = find(v[x]);
        return v[x];
    }

    bool connected(int a, int b) {
        if (find(a) == find(b)) return true;
        else return false;
    }

    void connect(int a, int b) {
        v[find(a)] = find(b);
    }
};

int main() {
    int N, M;
    bool connected = true;
    cin >> N >> M;
    cable_connection cable(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cable.connect(a - 1, b - 1);
    }
    for (int i = 1; i < N; i++) {
        if (cable.connected(0, i) == false) {
            cout << i + 1 << endl;
            connected = false;
        }
    }
    if (connected == true) {
        cout << "Connected" << endl;
    }
}