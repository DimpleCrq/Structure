#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 110;
struct info{
	int mtim,tim,in,out,num;
};
int net[MAXN][MAXN];
info node[MAXN];
int main()
{
	int n,m,cnt = 0,t1,t2,w,Max = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0;i < m;i++){
		scanf("%d %d %d",&t1,&t2,&w);
		net[t1][t2] = w;
		node[t2].in++;
		node[t1].out++;
	}
	queue<int> q,que;
	for(int i = 1;i <= n;i++){
		if(node[i].in == 0){
			q.push(i);
			cnt++;
		}
	}
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i = 1;i <= n;i++){
			if(net[temp][i] > 0){
				node[i].in--;
				if(node[i].tim < node[temp].tim + net[temp][i]){
					node[i].tim = node[temp].tim + net[temp][i];
					Max = max(Max,node[i].tim);
				}
				if(node[i].in == 0){
					q.push(i);
					cnt++;
				}
			}
		}
	}
	if(cnt != n) printf("0");
	else{
		for(int i = 1;i <= n;i++){
			node[i].mtim = -1;
			if(node[i].out == 0){
				que.push(i);
				node[i].mtim = Max;
			}
		}
		while(!que.empty()){
			int temp = que.front();
			que.pop();
			for(int i = 1;i <= n;i++){
				if(net[i][temp] > 0){
					node[i].out--;
					if(node[i].mtim == -1 || node[i].mtim > node[temp].mtim - net[i][temp])
						node[i].mtim = node[temp].mtim - net[i][temp];
					if(node[i].in == 0)
						que.push(i);
				}
			}
		}
		printf("%d\n",Max);
		for(int i = 1;i <= n;i++){
			if(node[i].mtim == node[i].tim){
				for(int j = n;j >= 1;j--){
					if(net[i][j] > 0 && node[j].mtim == node[j].tim && node[j].mtim - node[i].tim == net[i][j])
						printf("%d->%d\n",i,j);
				}
			}
		}
	}
	return 0;
} 