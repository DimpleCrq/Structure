#include<iostream>
#include<vector>
using namespace std;

struct graph{
	int vertex;
	int edge;
	int** G;
    bool* ver;
}; 
typedef graph* MGraph;

MGraph Initialize(int v){
	MGraph Graph=new graph;
    Graph->ver=new bool[v];
	Graph->G=new int*[v];
	for(int i=0;i<v;i++){
		Graph->G[i]=new int[v];
        Graph->ver[i]=true;
	} 
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			Graph->G[i][j]=0;
		}
	}
	return Graph;
}

MGraph Creat_Graph(){
	int v,e;
	cin>>v>>e;
	MGraph Graph=Initialize(v);
	Graph->edge=e;
	Graph->vertex=v;
	int x,y;
	for(int i=0;i<e;i++){
		cin>>x>>y;
		Graph->G[x][y]=1;
		Graph->G[y][x]=1;
	}
	return Graph;
}

int NextNode(MGraph Graph,int v){
	for(int i=0;i<Graph->vertex;i++){
        if(Graph->G[v][i]==0){}
        else{
            if(Graph->ver[i]==true)
                return i;
        }
    }
    return -1;
}

void DFS(MGraph Graph,int v){
    cout<<v<<' ';
    Graph->ver[v]=false;
    int temp;
	while((temp=NextNode(Graph,v))>=0){
        DFS(Graph,temp);
    }
}

void BFS(MGraph Graph,int v){
    vector<int> q;
    cout<<v<<' ';
    Graph->ver[v]=false;
    q.push_back(v);
    while(q.size()){
        int temp=q.front();
        q.erase(q.begin());
        int var;
        while((var=NextNode(Graph,temp))>=0){
            cout<<var<<' ';
            Graph->ver[var]=false;
            q.push_back(var);
        }
    }
}

void Function1(MGraph Graph){
    for(int i=0;i<Graph->vertex;i++){
        if(Graph->ver[i]==true){
            DFS(Graph,i);
            cout<<endl;
        }
    }
    for(int i=0;i<Graph->vertex;i++)
        Graph->ver[i]=true;
    for(int i=0;i<Graph->vertex;i++){
        if(Graph->ver[i]==true){
            BFS(Graph,i);
            cout<<endl;
        }
    }
}

void DFS2(MGraph Graph,int v){
    cout<<v+1<<' ';
    Graph->ver[v]=false;
    int temp;
	while((temp=NextNode(Graph,v))>=0){
        DFS2(Graph,temp);
        cout<<v+1<<' ';
    }
}

void Function2(){
	int v,e,n;
	cin>>v>>e>>n;
	MGraph Graph=Initialize(v);
	Graph->edge=e;
	Graph->vertex=v;
	int x,y;
	for(int i=0;i<e;i++){
		cin>>x>>y;
		Graph->G[x-1][y-1]=1;
		Graph->G[y-1][x-1]=1;
	}
    DFS2(Graph,n-1);
}

int  main(){
    MGraph Graph=Creat_Graph();
    BFS(Graph,2);
    //Function2();
}

/*
7 9
0 3
0 2
0 4
3 2
3 1
1 5
2 5
4 5
5 6

6 8 1
1 2
2 3
3 4
4 5
5 6
6 4
3 6
1 5
*/