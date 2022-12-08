#include<iostream>
#include<string>
using namespace std;

typedef struct Node{
	string name;
	int T;
	int P;
};

typedef struct Queue{
	Node* Data;
	int front;
	int rear;
};

Queue Intital(int n){
	Queue q;
	q.Data=(Node*)malloc(sizeof(Node)*n);
	q.front=q.rear=0;
	return q;
}

int FindPeople(Queue* q,int n,string s){
	for(int=0;i<n;i++){
		for(int j=0;q[i].Data[j];j++){
			if(s==q[i].Data[j].name)
				return i;
		}
	}
}

Queue Add(Queue q,Node n,int Total){
	q.Data[q.front]=n;
	q.front=(q.front+1)%Total;
}

Node Delete(Queue q,int Total){
	Node n=q.Data[q.rear];
	q.rear=(q.rear+1)%Total;
	return n;
}

void Function(){
	int Total,GroupNum;
	cin>>Total>>GroupNum;
	Queue T_queue=Intital(Total);
	Queue *Arrar=(Queue*)malloc(sizeof(Queue)*GroupNum);
	int i=0;
	string s;
	int a[GroupNum]={};
	while(cin>>a[i] && i++<GroupNum){
		getchar();
		Arrar[i]=Intital(a[i]);
		Node f;
		for(int j=0;j<a[GroupNum];j++){
			cin>>s;
			getchar();
			f.name=s;
			Add(Arrar[i],f,a[i]);
		}
		if(getchar()=='\n')
			break;
	}
	int T_num,P_num;
	for(i=0;i<Total;i++){
		cin>>s>>T_num>>P_num;
		T_queue.Data[i].name=s;
		T_queue.Data[i].T=T_num;
		T_queue.Data[i].P=P_num;
		T_queue.front=i+1;
		getchar();
	}
	i=0;
	while(){
		int temp=FindPeople(Arrar,GroupNum,T_queue.Data[i].name);
		while(){
			Node T=P-T_queue.Data[i];
			for(int j=0;Arrar[temp].Data[j];j++){
				while(Arrar[temp].Data[j].P-T.P<=1){
					Output(T);
					T=Arrar[temp].Data[j];
					Delete(Arrar[temp].Data[j],a[temp]);
					a[temp]--;
				}
				
			}
		}
	}
}

int main(){
	
}
