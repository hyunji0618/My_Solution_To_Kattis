#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000
#define ever (;;)
#define MIN(a,b) ((a) < (b) ? (a) : (b))

bool sell[MAX];
int share[MAX];
int price[MAX];

int best_i(bool s, int n) {
	int i, y = -1;
	for(i = 0; i <= n; i++)
		if(sell[i] == s && share[i] > 0 && ((s && price[y] > price[i]) || (!s && price[y] < price[i])|| y == -1 ))
			y = i;
	return y;
}

void test_case() {
	int i, n, selli, buyi, am, last = -1;
	char type[10];
	scanf("%d\n", &n);
	for(i = 0; i < n; i++) {
		scanf("%s %d shares at %d\n", type, &share[i], &price[i]);
		sell[i] = (type[0] == 's');
		for ever {
			selli = best_i(true, i);
			if(selli == -1) break;
			buyi = best_i(false, i);
			if(buyi == -1) break;
			if(price[buyi] < price[selli]) break;
			am = MIN(share[buyi], share[selli]);
			share[buyi] -= am;
			share[selli] -= am;
			last = price[selli];
		}
		selli = best_i(true, i);
        
        if(selli == -1) printf("- ");
		else printf("%d ", price[selli]);
		buyi = best_i(false, i);
        
		if(buyi == -1) printf("- ");
		else printf("%d ", price[buyi]);
        
		if(last == -1) printf("-\n");
		else printf("%d\n", last);
	}
}

int main() {
	int x;
	scanf("%d\n", &x);
	while(x--) test_case();
	return 0;
}
