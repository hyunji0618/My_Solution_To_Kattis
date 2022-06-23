#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 1 << 20;

int N;

set <int> S[MAXN];
int find (int idx, int v) {
  set<int>::iterator x = S[v].lower_bound(idx);
  if (x == S[v].end()) return -1;
  return *x;
}

int v[MAXN];

int main (void){
    cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
    S[v[i]].insert(i);
  }

  int ar = 0;
  for (int i = 0; i < N; ++i) {
   if (S[v[i]].count(i) == 0) continue;
   int idx = i;
   ++ar;
   while (idx >= 0) {
      S[v[idx]].erase(idx);
       idx = find(idx, v[idx] - 1);
   }
  }

    cout << ar << endl;

  return 0;
}
