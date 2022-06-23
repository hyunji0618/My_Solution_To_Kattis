#include <stdio.h>

int main()
{
    int cur, cor;
    int p, m;
    scanf("%d %d", &cur, &cor);
    if (cur <= cor) {
        p = cor-cur;
        m = 360-cor+cur;
        if (p<=m) {
            printf("%d",p);
        }
        else {
            printf("-%d",m);
        }
    }
    else {
        p = 360-cur+cor;
        m = cur-cor;
        if (p<=m) {
            printf("%d",p);
        }
        else {
            printf("-%d",m);
        }
    }
    return 0;
}