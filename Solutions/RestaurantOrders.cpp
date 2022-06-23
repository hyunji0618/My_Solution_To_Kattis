#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m,s;
    vector<int> v(30000,-1);
    v[0] = 0;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i){
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + c[i] < 30000; j++) {
            if (v[j] >= 0) {
                if (v[j+c[i]] == -1) v[j+c[i]] = i;
                else if (v[j+c[i]] >= 0) v[j+c[i]] = -2;
            } 
            else if (v[j] == -2) {
                v[j+c[i]] = -2;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (v[s] == -1) {
            cout << "Impossible" << endl;
        } 
        else if (v[s] == -2) {
            cout << "Ambiguous" << endl;
        } 
        else {
            vector<int> r;
            while (s) {
                r.push_back(v[s]);
                s = s-c[v[s]];
            }
            for (int i = r.size()-1; i > 0; i--){
                cout << r[i]+1 << " ";
            }
            cout << r[0]+1 << endl;
        }
    }
}
