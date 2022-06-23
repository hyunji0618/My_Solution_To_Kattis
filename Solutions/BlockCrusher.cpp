#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

void BlockCrusher(int h, int w);
bool testing(int x, int y);

int h, w;
int go = 1 << 30;

int main(void) {
    while(cin >> h >> w) {
        if(h == 0 && w == 0) break;
        BlockCrusher(h, w);
    }
}

void BlockCrusher(int h, int w) {
    char b;
    vector< vector<int> > line( h+2, vector<int> (w, 1 << 30));
    line[0][0] = 0;
    vector< vector<int> > block( h+2, vector<int> (w, 0));
    vector< vector<pair<int,int> > > v(h+2, vector< pair<int,int> >(w, {1 << 30,1 << 30}));
    priority_queue< pair<int, pair<int,int> > > q;
    q.push({0,{0,0}});
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b;
            block[i+1][j] = b - '0';
        }
    }
    while(!q.empty()) {
        int x, y;
        int x_next, y_next;
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                x_next = x + i - 1;
                y_next = y + j - 1;
                if (!testing(x_next, y_next)) continue;
                if(line[x_next][y_next] > line[x][y] + block[x_next][y_next]) {
                    q.push({-(line[x_next][y_next]), {x_next, y_next}});
                    line[x_next][y_next] = line[x][y] + block[x_next][y_next];
                    v[x_next][y_next] = {x, y};
                }
            }
        }
    }

    int x = h + 1;
    int y = w - 1;
    while (x != 1 << 30 && y != 1 << 30) {
        pair<int,int> p = v[x][y];
        block[x][y] = ' ' - '0';
        x = p.first;
        y = p.second;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << char(block[i+1][j] + '0');
        cout << endl;
    }
    cout << endl;
}

bool testing(int x, int y) {
    bool ToN = x >= 0 && y >= 0 && x < h+2 && y < w;
    return ToN;
}
