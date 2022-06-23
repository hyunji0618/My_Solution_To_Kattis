#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    int N,M;
    int length = 0;
    typedef pair<int,int> p;
    queue< pair<int,int> > q;
    cin >> N >> M;
    char grid[N][M];
    for(int i = 0; i < N; i++){
        cin >> grid[i];
    }

    for(int i = 0; i < N; i++) {
        q.push(p(i,0));
        q.push(p(i,M-1));
    }
    for(int i = 0; i < M; i++) {
        q.push(p(0,i));
        q.push(p(N-1,i));
    }

    while (!q.empty()) {
        if (q.empty()) break;
        p p1 = q.front();
        q.pop();
        if (p1.first < 0 || N <= p1.first || p1.second < 0 || M <= p1.second) continue;
        if (grid[p1.first][p1.second] == '0') {
            q.push(p(p1.first-1,p1.second));
            q.push(p(p1.first+1,p1.second));
            q.push(p(p1.first,p1.second-1));
            q.push(p(p1.first,p1.second+1));
            grid[p1.first][p1.second] = 'N';
        }
        else if (grid[p1.first][p1.second] == '1') length++;
    }
    cout << length << endl;
    return 0;
}
