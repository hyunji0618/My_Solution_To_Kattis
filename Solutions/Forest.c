#include <stdio.h>

int main(){
   int P,T;
   int i,j = 0,k;
   int op = 0;
   int tree[100][100];
   int a[100];

   scanf("%d %d",&P,&T);

   while (scanf("%d %d",&i,&j) == 2) {
      tree[i][j] = 1;
   }

   for (i = 1;i <= P;i++) {
      if (a[i]) continue;
      op++;
      for (j = i;j <= P;j++) {
         for (k = 1; k <= T && tree[i][k] == tree[j][k]; k++);
         if (k > T) a[j] = 1;
      }
   }

   printf("%d\n",op);
}