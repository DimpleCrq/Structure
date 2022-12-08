#include<iostream>
#include<vector>
using namespace std;

struct graph{
	int vertex;
	int edge;
	int** G;
    bool* ver;
    int* length;
    int* rescue_num;
}; 
typedef graph* MGraph;

int* road;
int* r_num;
int* road_num;

MGraph Creat_Graph(int v,int e){
    MGraph Graph=new graph;
	Graph->edge=e;
	Graph->vertex=v;
    Graph->ver=new bool[v];
	Graph->G=new int*[v];
    Graph->length=new int[v];
    Graph->rescue_num=new int[v];
    road=new int[v];
    r_num=new int[v];
    road_num=new int[v];
	for(int i=0;i<v;i++){
		Graph->G[i]=new int[v];
        Graph->ver[i]=true;
        Graph->rescue_num[i]=0;
        Graph->length[i]=0;
        road[i]=-1;
        r_num[i]=0;
        road_num[i]=1;
	} 
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			Graph->G[i][j]=0;
		}
	}
	return Graph;
}

MGraph Input_info(MGraph Graph){
    for(int i=0;i<Graph->vertex;i++){
        cin>>Graph->rescue_num[i];
    }
    int x,y,weight;
    for(int i=0;i<Graph->edge;i++){
        cin>>x>>y>>weight;
        Graph->G[x][y]=weight;
        Graph->G[y][x]=weight;
    }
    return Graph;
}

void BFS(MGraph Graph,int v_begin){
    vector<int> q;
    q.push_back(v_begin);
    r_num[v_begin]=Graph->rescue_num[v_begin];
    while(q.size()){
        int location=q.front();
        q.erase(q.begin());
        Graph->ver[location]=false;
        int k=0;
        while(k<Graph->vertex){
            if(k!=location && Graph->G[location][k] && Graph->ver[k]==true){
                q.push_back(k);
                if(Graph->length[k]==0){
                    Graph->length[k]=Graph->G[location][k];
                    road[k]=location;
                    r_num[k]=r_num[location]+Graph->rescue_num[k];
                }else if(Graph->G[location][k]+Graph->length[location]<Graph->length[k]){
                    Graph->length[k]=Graph->G[location][k]+Graph->length[location];
                    road[k]=location;
                    r_num[k]=r_num[location]+Graph->rescue_num[k];
                }else if(Graph->G[location][k]+Graph->length[location]==Graph->length[k]){
                    if(Graph->rescue_num[k]+r_num[location]>r_num[k]){
                        r_num[k]=r_num[location]+Graph->rescue_num[k];
                        road[k]=location;
                    }
                    road_num[k]++;
                }
            }
            k++;
        }
    }
}

void Function(){
	int v,e,v_begin,v_end;
	cin>>v>>e>>v_begin>>v_end;
    MGraph Graph=Creat_Graph(v,e);
    Graph=Input_info(Graph);
    BFS(Graph,v_begin);
    cout<<road_num[v_end]<<' '<<r_num[v_end]<<endl;
    vector<int> q;
    int k=v_end;
    q.push_back(k);
    while(road[k]>=0){
        q.push_back(road[k]);
        k=road[k];
    }
    for(vector<int>::iterator i=q.end()-1;i!=q.begin()-1;i--)
        cout<<*i<<' ';
    cout<<endl;
}

int main(){
    Function();
}
/*
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
*/