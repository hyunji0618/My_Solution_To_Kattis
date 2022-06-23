#include <iostream>
#include <stdio.h>
using namespace std;

void Reseto(int *num, int *min, int N) {
    for (int i = *min; i < N+1; i++) {
        if (num[i]) {
            *min = i;
            break;
        }
    }
    return;
}

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    int min = 2;
    int num[N+1];
    num[0] = 0; 
    for (int i = 0; i < N + 1; i++) {
        num[i] = i;
    }
    num[1] = 0;
    int i = 0;
    while (i < K) {
        for (int j = min; j <= N; j += min) {
            if (!num[j]) continue;
            num[j] = 0;
            ans = j;
            i++;
            if (i == K) break;
        }
        if (i < K) {
            Reseto(num, &min, N);
        }
    }
    cout << ans << endl;
}