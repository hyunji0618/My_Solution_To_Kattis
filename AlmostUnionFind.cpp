#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m;
int f[100000],sum[100000],ct[100000],ide[100000];
int k;

void in()
{
	for(int i=1; i<=n; i++)
	{
		f[i] = i;
		sum[i] = i;
        ct[i] = 1;
		ide[i] = i;
	}	
}

int search(int n)
{
	if(f[n] == n)
		return f[n];
	else
		return f[n] = search(f[n]);
}

void op(int x)
{
	int y;
	y = search(ide[x]);
    sum[y]-=x;
    ct[y]--;
	ide[x] =++k;
	f[k] = k;
	ct[k] = 1;
	sum[k] = x;
}

void com(int x,int y)
{
	int v,z;
	v = search(x);
	z = search(y);
	if(v != z)
	{
		f[z]=v;
		sum[v]+=sum[z];
		ct[v]+=ct[z];
	}	
}

int main()
{
	int i,j,a,b,c;
	while(true)
	{
        cin >> n;
        cin >> m;
        if(cin.get() == EOF)
         break;
		in();
		k = n;
		while(m--)
		{
            cin >> a;
            if(cin.get()==EOF) break;
			if(a == 1)
			{
                cin >> b;
                cin >> c;				
                com(ide[b],ide[c]);
			}
			if(a == 2)
			{
                cin >> b;
                cin >> c;
				if(search(ide[b])==search(ide[c]))
				continue;
				op(b);
				com(ide[b],ide[c]);
			}
			if(a == 3)
			{
                cin >> b;
				int x=search(ide[b]);
                printf("%d %d\n",ct[x],sum[x]);
			}				
		}
	}
	return 0;
}