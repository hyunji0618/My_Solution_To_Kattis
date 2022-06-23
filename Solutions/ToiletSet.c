#include <stdio.h>
#define SIZE 1000

int main()
{
    char string[SIZE];
    int a=0, b=0, c=0;
    int N = 0;

    gets(string);

    if (string[0] == 'U' && string[1] == 'U'){
        b++;
    }
    else if (string[0] == 'U' && string[1] == 'D'){
        a=a+2;
        b++;
        c++;
    }
    else if (string[0] == 'D' && string[1] == 'U'){
        a++;
        b=b+2;
        c++;
    }
    else if (string[0] == 'D' && string[1] == 'D'){
        a++;
    }

    for (N=2; string[N]; N++){
        if (string[N-1] == 'U' && string[N] == 'U'){
            b=b+2;
        }
        else if (string[N-1] == 'U' && string[N] == 'D'){
            a=a+2;
            c++;
        }
        else if (string[N-1] == 'D' && string[N] == 'U'){
            b=b+2;
            c++;
        }
        else if (string[N-1] == 'D' && string[N] == 'D'){
            a=a+2;
        }
    }

    printf("%d\n%d\n%d\n",a,b,c);
}