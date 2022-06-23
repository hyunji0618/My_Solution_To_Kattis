#include <iostream>
using namespace std;

char map[51][51];

int num_of_gold(int h, int w) {
  int ret;
  if (map[h][w] == '#') return 0; 
  if (map[h][w] == 'C') return 0; 
  if (map[h][w] == 'T') return 0; 
  ret = map[h][w] == 'G'; 
  map[h][w] = 'C'; 
  if (map[h-1][w] == 'T' || map[h+1][w] == 'T' || map[h][w-1] == 'T' || map[h][w+1] == 'T') {
    return ret;
  }
  ret = ret + num_of_gold(h-1, w) + num_of_gold(h, w-1) + num_of_gold(h+1, w) + num_of_gold(h, w+1);
  return ret;
}

int main() {
  int W, H; 
  int ans;
  cin >> W >> H;
  for (int i = 0; i < H; i++) {
    cin >> map[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] == 'P') {
        ans = num_of_gold(i, j);
      }
    }
  }
  cout << ans << endl;
}
