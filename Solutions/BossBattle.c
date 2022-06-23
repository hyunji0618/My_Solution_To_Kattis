#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);
    if (N-3 <= 0) {
        printf("1");
    }
    else{
        printf("%d", N-3+1);
    }
}