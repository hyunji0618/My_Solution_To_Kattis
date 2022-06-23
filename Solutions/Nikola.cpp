#include <algorithm>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;

int N;
int entry_fee[1000];
int S[1000][1000];

int smallest_total_cost(int x, int y) {
   if(x == N-1) {
      return entry_fee[x];
   }
   else if(x < 0 || x >= N) return 10000000;
   else if(S[x][y] != -1) {
      return S[x][y];
   }
   else{
      S[x][y] = min(smallest_total_cost(x+y+1, y+1), smallest_total_cost(x-y, y)) + entry_fee[x];
      return S[x][y];
   }
}

int main() {
   memset(S, -1, sizeof(S));
   cin >> N;
   for(int i = 0; i < N; i++) {
      cin >> entry_fee[i];
   }
   cout << smallest_total_cost(1, 1) << endl;
   return 0;
}
