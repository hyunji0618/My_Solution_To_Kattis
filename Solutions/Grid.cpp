#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
 
int h, w;
string str;
int x[] = {1, -1, 0 , 0};
int y[] = {0, 0, 1, -1};
int grid[500][500] = {0, };
int counting[500][500] = {0, };
 
void find_min() {
    queue< pair<int, int> > q;
    q.push(pair<int, int>(1, 1));
    counting[1][1] = 0;
 
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop(); 
        for (int i = 0; i <= 3; i++) {
            int p_x = a + x[i] * grid[a][b];
            int p_y = b + y[i] * grid[a][b];
            if (1 <= p_x && 1 <= p_y && p_x <= h && p_y <= w) { 
               if (counting[p_x][p_y] > counting[a][b] + 1) { 
                   counting[p_x][p_y] = counting[a][b] + 1;
                   q.push(pair<int, int>(p_x, p_y));
               }
            }
        }
    }
}
 
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> str;
        for (int j = 0; j < w; j++) {
            grid[i+1][j+1] = str[j] - '0';
            counting[i+1][j+1] = 10000000;
        }
    }
 
    find_min();
 
    if (counting[h][w] == 10000000) {
        cout << -1;
    }
    else {
        cout << counting[h][w];
    }
    return 0;
}