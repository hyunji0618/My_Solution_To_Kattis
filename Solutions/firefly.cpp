#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int stalagmite[100000];
int stalactite[100000];

int main( void ) {
    int n, h;
    int min = 1000000000;
    int b = 0;
    int kf;
    cin >> n >> h;
    n /= 2;
    for(int i = 0; i < n; i++){
        cin >> stalagmite[i] >> stalactite[i];
    }
   sort(stalagmite, stalagmite+n);
   sort(stalactite, stalactite+n);

   for(int y = 0; y < h; ++y) {
      kf = n - (int)(lower_bound(stalagmite, stalagmite+n, y+1)-stalagmite) + n - (int)(lower_bound(stalactite, stalactite+n, h-y)-stalactite);
      if( kf  < min ) { min = kf; b = 0; }
      if( kf == min ) ++b;
   }
    cout << min << " " << b << endl;
   return 0;
}
