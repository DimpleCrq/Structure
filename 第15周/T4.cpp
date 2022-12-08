#include<iostream>
#include<vector>
using namespace std;

struct graph{
	int vertex;
	int edge;
	int** G;
    bool* ver;
    int* length;
}; 
typedef graph* MGraph;

MGraph Creat_Graph(int v){
    MGraph Graph=new graph;
	Graph->vertex=v;
    Graph->ver=new bool[v];
	Graph->G=new int*[v];
    Graph->length=new int[v];
	for(int i=0;i<v;i++){
		Graph->G[i]=new int[v];
        Graph->ver[i]=true;
        Graph->length[i]=0;
	} 
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			Graph->G[i][j]=0;
		}
	}
	return Graph;
}

MGraph Input_info(MGraph Graph){
    int x,y,weight,i=0;
    while(i>=0){
        cin>>x>>y>>weight;
        Graph->G[x-1][y-1]=weight;
        i++;    
        if(getchar()!='\n')
            break;
    }
    Graph->edge=i;
    return Graph;
}

void BFS(MGraph Graph,int v_begin){
    vector<int> q;
    q.push_back(v_begin);
    while(q.size()){
        int location=q.front();
        q.erase(q.begin());
        Graph->ver[location]=false;
        int k=0;
        while(k<Graph->vertex){
            if(k!=location && Graph->G[location][k] && Graph->ver[k]==true){
                q.push_back(k);
                if(Graph->length[k]==0){
                    Graph->length[k]=Graph->length[location]+Graph->G[location][k];
                }else if(Graph->length[location]+Graph->G[location][k]<Graph->length[k]){
                    Graph->length[k]=Graph->length[location]+Graph->G[location][k];
                }
            }
            k++;
        }
    }
}

void Function(){
    int n,v_begin;
    cin>>n>>v_begin;
    MGraph Graph=Creat_Graph(n);
    Graph=Input_info(Graph);
    BFS(Graph,v_begin-1);
    int max=-1;
    for(int i=0;i<Graph->vertex;i++){
        if(Graph->length[i]>max)
            max=Graph->length[i];
    }
    cout<<max<<endl;
}

int main(){
    Function();
}
/*
4 2
2 1 1
2 3 1
3 4 1
*/