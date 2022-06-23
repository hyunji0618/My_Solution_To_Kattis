#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
vector<int> A(100), B(100);

int solve(){
    int val = 0;
    vector<int> X=A, Y=B;
    for (int i=1, j=100; i<=100 && j>=1;){
        if (X[i] < Y[j]){
            if(X[i]) {
                val = max(val, i+j);
                Y[j] -= X[i];
            }
            i++;
        } 
        else {
            if (Y[j]){
                val  = max(val,i+j);
                X[i] -= Y[j];
            }
            j--;
        }
    }
    return val;
}

int main(){
    cin >> N;
    while(N--){
        int a,b;
        cin >> a;
        cin >> b;
        A[a]++;
        B[b]++;
        cout << solve() << endl;
    }

}