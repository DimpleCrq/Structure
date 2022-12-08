#include<iostream>
using namespace std;

#define Max 10

typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode{
	int *Data;
	Position Front;
	int Count;
	int MaxSize; 
};
typedef PtrToQNode Queue;

Queue Intital(){
	Queue q=new QNode;
	q->Data=(int*)malloc(sizeof(int)*Max);
	q->Count=0;
	q->Front=0;
	q->MaxSize=Max;
	return q;
}

bool AddQ(Queue Q,int x){
	if(Q->Count==Q->MaxSize){
		cout<<"Queue Full";
		return false;
	}
	else{
		Q->Data[Q->Front]=x;
		Q->Count++;
		Q->Front=Q->Count;
		return true;
	}
}

char* DeleteQ(Queue& Q){
	if(Q->Count==0){
		cout<<"Queue Empty";
		return "ERROR";
	}
	else{
		Q->Front--;
		Q->Data[Q->Front]=0;
		Q->Count=Q->Front;
	}
}

void Output(Queue Q){
	for(int i=0;i<Q->Count;i++){
		cout<<Q->Data[i]<<' ';
	} 
	cout<<endl;
}

int main(){
	Queue q=Intital();
	AddQ(q,1);
	AddQ(q,2);
	AddQ(q,3);
	AddQ(q,4);
	AddQ(q,5);
	
	Output(q);
	
	DeleteQ(q);
	DeleteQ(q);
	
	Output(q);
	
	DeleteQ(q);	
	Output(q);
	
	DeleteQ(q);
	DeleteQ(q);
	DeleteQ(q);
}
