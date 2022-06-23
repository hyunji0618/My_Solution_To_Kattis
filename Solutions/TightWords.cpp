#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    int k,n;
    double pos[101][10];
    double ret;
    while (cin >> k >> n){
        ret = 0;
        for (int i = 0; i <= 9; i++) {
            pos[1][i] = (1.0)/(k+1);
        }
        for (int j = 2; j <= n; j++){
            for (int l = 0; l <= k; l++){
                pos[j][l] = pos[j-1][l];
                if (l > 0) {
                    pos[j][l] = pos[j][l] + pos[j-1][l-1];
                }
                if (l < k) {
                    pos[j][l] = pos[j][l] + pos[j-1][l+1];
                }
                pos[j][l] = pos[j][l] / (k+1);
            }
        }
        for (int l = 0; l <= k; l++) {
            ret = ret + pos[n][l];
        }
        cout << fixed;
        cout.precision(7);
        cout << (100.0) * ret << endl;
  }


  return 0;
}