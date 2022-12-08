#include<iostream>
#include<vector>
using namespace std;

struct node{
    int v_node;
    int cost;
    int length;
    struct node* next;
};

struct Node{
    struct node** vertex;
    int ver;
    int edge;
    bool* state;
};
typedef struct Node* LGraph;
int* road,*road_l,*Cost;

LGraph Creat_Graph(int v,int e){
    LGraph Graph=new struct Node;
    Graph->state=new bool[v];
    road=new int[v];
    road_l=new int[v];
    Cost=new int[v];
    for(int i=0;i<v;i++){
        Graph->state[i]=true;
        road[i]=-1;
        road_l[i]=0;
        Cost[i]=0;
    }
    Graph->ver=v;
    Graph->edge=e;
    Graph->vertex=new struct node*[v];
    for(int i=0;i<v;i++){
        Graph->vertex[i]=new struct node;
        Graph->vertex[i]->cost=0;
        Graph->vertex[i]->length=0;
        Graph->vertex[i]->v_node=-1;
        Graph->vertex[i]->next=NULL;
    }
    return Graph;
}

LGraph Input_info(LGraph Graph){
    int x,y,l,c;
    for(int i=0;i<Graph->edge;i++){
        cin>>x>>y>>l>>c;
        struct node* p=new struct node;
        p->cost=c;
        p->length=l;
        p->v_node=y;
        p->next=Graph->vertex[x]->next;
        Graph->vertex[x]->next=p;
    }
    return Graph;
}

struct node* NextNode(LGraph Graph,int v,int k){
    struct node* p=Graph->vertex[v];
    for(int i=0;i<k;i++){
        p=p->next;
    }
    if(p==NULL)
        return NULL;
    else{
        return p;
    }
}

void BFS(LGraph Graph,int v_begin){
    vector<int> q;
    q.push_back(v_begin);
    while(q.size()){
        int location=q.front();
        q.erase(q.begin());
        Graph->state[location]=false;
        int k=1;
        struct node* temp;
        while(NextNode(Graph,location,k)!=NULL){
            temp=NextNode(Graph,location,k);
            k++;
            if(Graph->state[temp->v_node]==true){
                q.push_back(temp->v_node);
                if(road_l[temp->v_node]==0){
                    road_l[temp->v_node]=temp->length;
                    road[temp->v_node]=location;
                    Cost[temp->v_node]=temp->cost;
                }else{
                    if(road_l[location]+temp->length<road_l[temp->v_node]){
                        road[temp->v_node]=location;
                        road_l[temp->v_node]=road_l[location]+temp->length;
                        Cost[temp->v_node]=Cost[location]+temp->cost;
                    }
                    else if(road_l[location]+temp->length==road_l[temp->v_node]){
                        if(Cost[location]+temp->cost<Cost[temp->v_node]){
                            road[temp->v_node]=location;
                            Cost[temp->v_node]=Cost[location]+temp->cost;
                        }
                    }
                }
            }
        }
    }
}

void Function(){
    int v,e,v_begin,v_end;
    cin>>v>>e>>v_begin>>v_end;
    LGraph Graph=Creat_Graph(v,e);
    Graph=Input_info(Graph);
    BFS(Graph,v_begin);
    cout<<road_l[v_end]<<' '<<Cost[v_end]<<endl;
}

int main(){
    Function();
}
/*
4 5 0 3
0 1 1 20
1 3 2 20
0 3 4 10
0 2 2 20
2 3 1 20
*/