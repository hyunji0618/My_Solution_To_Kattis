#include <stdio.h>

int main() 
{
    int X, N, M, i, p;
    scanf("%d", &X);
    scanf("%d", &N);
    M = X;
    for (i=1;  i<=N; i++) {
        p = 1;
        scanf("%d", &p);
        M = M-p;
        M = M+X;
    }
    printf("%d", M);

}