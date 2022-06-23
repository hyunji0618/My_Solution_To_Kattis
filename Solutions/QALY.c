#include <stdio.h>

int main() 
{
    int N, i;
    float q, y;
    float QALY = 0.0;
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        q = 1;
        y = 1;
        scanf("%f %f", &q, &y);
        QALY = QALY + (q*y);
    }
    printf("%.3f", QALY);

}