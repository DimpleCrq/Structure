#include<iostream>
#include<vector>
using namespace std;

#define Type char
struct graph{
	int Side_length;
	Type** G;
    bool* ver;
    int* turn_num;
}; 
typedef graph* MGraph;
int* road;

MGraph Initialize(int v){
	MGraph Graph=new graph;
    Graph->ver=new bool[v*v];
    Graph->turn_num=new int[v*v];
	Graph->G=new Type*[v];
	for(int i=0;i<v;i++){
		Graph->G[i]=new Type[v];
	} 
	for(int i=0;i<v*v;i++){
        Graph->ver[i]=true;
        Graph->turn_num[i]=0;
	} 
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			Graph->G[i][j]=0;
		}
	}
	return Graph;
}

MGraph Creat_Graph(){
	int v;
    cout<<"输入参数规模:";
	cin>>v;
    road=new int[v*v];
	for(int i=0;i<v*v;i++){
        road[i]=-1;
	}
	MGraph Graph=Initialize(v);
	Graph->Side_length=v;
	Type weight;
    cout<<"输入方格值："<<endl;
	for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>weight;
            Graph->G[i][j]=weight;
        }
	}
	return Graph;
}

int FindRoad(MGraph Graph,vector<int>& q,int i,int j,int k){
    if(k==1 && j+1<Graph->Side_length && Graph->G[i][j+1]!='x')
        if(Graph->ver[i*Graph->Side_length+j+1]==true){
            q.push_back(i*Graph->Side_length+j+1);
            return i*Graph->Side_length+j+1;
        }
    if(k==2 && i+1<Graph->Side_length && Graph->G[i+1][j]!='x')
        if(Graph->ver[(i+1)*Graph->Side_length+j]==true){
            q.push_back((i+1)*Graph->Side_length+j);
            return (i+1)*Graph->Side_length+j;
        }
    if(k==3 && j-1>=0 && Graph->G[i][j-1]!='x')
        if(Graph->ver[i*Graph->Side_length+j-1]==true){
            q.push_back(i*Graph->Side_length+j-1);
            return i*Graph->Side_length+j-1;
        }
    if(k==4 && i-1>=0 && Graph->G[i-1][j]!='x')
        if(Graph->ver[(i-1)*Graph->Side_length+j]==true){
            q.push_back((i-1)*Graph->Side_length+j);
            return (i-1)*Graph->Side_length+j;
        }
    return -1;
}

int Turn_num(MGraph Graph,int* road,int temp,int location){
    if(road[location]==-1)
        return 0;
    else{
        int t=road[location];
        int x_t=t/Graph->Side_length;
        int y_t=t-x_t*Graph->Side_length;
        int x_temp=temp/Graph->Side_length;
        int y_temp=temp-x_temp*Graph->Side_length;
        if(x_t==x_temp || y_t==y_temp)
            return Graph->turn_num[location];
        else return Graph->turn_num[location]+1;
    }
}

void BFS(MGraph Graph,int i,int j){
    vector<int> q;
    q.push_back(i*Graph->Side_length+j);
    while(q.size()){
        int location=q.front();
        q.erase(q.begin());
        int x=location/Graph->Side_length;
        int y=location-x*Graph->Side_length;
        Graph->ver[location]=false;
        int temp,k=1;
        while(k<5){
            temp=FindRoad(Graph,q,x,y,k);
            k++;
            if(temp>=0){
                int t_n=Turn_num(Graph,road,temp,location);
                if(Graph->turn_num[temp]==0){
                    Graph->turn_num[temp]=t_n;
                    road[temp]=location;
                }else if(t_n<Graph->turn_num[temp]){
                        Graph->turn_num[temp]=t_n;
                        road[temp]=location;
                }
            }
        }
    }
}

void Function(MGraph Graph,Type s,Type t){
    int x=-1,y=-1;
    for(int i=0;i<Graph->Side_length;i++){
        for(int j=0;j<Graph->Side_length;j++){
            if(Graph->G[i][j]==s){
                x=i;
                y=j;
                break;
            }
        }
        if(x>=0)
            break;
    }
    BFS(Graph,x,y);
    for(int i=0;i<Graph->Side_length;i++){
        for(int j=0;j<Graph->Side_length;j++){
            if(Graph->G[i][j]==t){
                int k=i*Graph->Side_length+j;
                cout<<"鏈�灏戣浆寮鏁帮細"<<Graph->turn_num[k]<<endl;
                exit(0);
            }
        }
    }
}

int main(){
    MGraph Graph=Creat_Graph();
    Function(Graph,'A','B');
}
