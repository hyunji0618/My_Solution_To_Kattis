#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector< pair<int, int> > v[100000];
int trail1[100000];
int trail2[100000];

void finding_direction(int T[], int start, int finish) {
    int a, b, c;
    static int tmp[100000];
    queue<int> q;
    T[start] = 0;
    q.push(start);
    while (!q.empty()) {
        a = q.front();
        q.pop();
        tmp[a] = 0;
        for (int i = 0; i < v[a].size() ; i++) {
            b = v[a][i].first, c = v[a][i].second;
            if (T[b] > T[a] + c) {
                T[b] = T[a] + c;
                if (!tmp[b]){
                    tmp[b] = 1;
                    q.push(b);
                }
            }
        }
    }
}
int main() {
    int P, T;
    int p1, p2, l;
    while (cin >> P >> T) {
       int ans = 0;
        for (int i = 0; i < P; i++){
            v[i].clear();
        }
        for (int i = 0; i < T; i++) {
            cin >> p1 >> p2 >> l;
            v[p1].push_back(make_pair(p2, l));
            v[p2].push_back(make_pair(p1, l));
        }
        
        for (int i = 0; i < P; i++){
            trail1[i] = trail2[i] = 10000000000;
        }
        finding_direction(trail1, 0, P-1);
        finding_direction(trail2, P-1, 0);
    
        int x = trail1[P - 1];
        for (int i = 0; i < P; i++) {
            p1 = i;
            for (int j = 0; j < v[i].size(); j++) {
                p2 = v[i][j].first;
                l = v[i][j].second;
                if (trail1[p1] + trail2[p2] + l == x)
                    ans += l;
            }
        }
        cout << 2*ans << endl;
    }
}