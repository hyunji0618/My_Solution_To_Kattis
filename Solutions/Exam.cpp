#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#define MAXN 1000
using namespace std;

char me[MAXN];
char fr[MAXN];

int main() {
   int k;
   cin >> k;
   cin >> me;
   cin >> fr;
   int compare = 0;
   int length = strlen(me);
   for (int i = 0; i < length; i++){
      if (me[i] == fr[i]) compare++;
   }
   int ans = min(compare, k) + min(length-compare, length-k);
   cout << ans << endl;
}
