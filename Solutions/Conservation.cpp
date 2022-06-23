#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	struct Vertex
	{
		vector<int> a;
		int pos;
	};
	struct Edge
	{
		int from,to;
	};
	vector<Vertex> v;
	vector<Edge> e;
	Graph(int n):v(n) {}
	void add(const Edge &ed)
	{
		v[ed.from].a.push_back(e.size());
		e.push_back(ed);
	}
	int topo(int first)
	{
		vector<int> deg(v.size(),0);
		for(int i=0; i<e.size(); ++i)++deg[e[i].to];
		deque<int> q;
		for(int i=0; i<deg.size(); ++i)
			if(!deg[i])
				v[i].pos==first?q.push_front(i):q.push_back(i);
		int ans=0,pre=q.back(),u;
		while(!q.empty())
		{
			if(v[q.back()].pos==v[pre].pos)
				u=q.back(),q.pop_back();
			else u=q.front(),q.pop_front();
			if(v[u].pos!=v[pre].pos)++ans;
			for(int i=0,k,to; i<v[u].a.size(); ++i)
				if(k=v[u].a[i],to=e[k].to,!--deg[to])
					v[to].pos==first?q.push_front(to):q.push_back(to);
			pre=u;
		}
		return ans;
	}
};
int main()
{
	int t,n,m;
	for(scanf("%d",&t); t--;)
	{
		scanf("%d%d",&n,&m);
		Graph g(n);
		for(int i=0; i<n; ++i)scanf("%d",&g.v[i].pos);
		for(int i=0,u,v; i<m; ++i)
			scanf("%d%d",&u,&v),g.add({u-1,v-1});
		printf("%d\n",min(g.topo(1),g.topo(2)));
	}
}