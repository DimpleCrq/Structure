#include<iostream>
using namespace std;

typedef struct Queue{
	int Data[10];
	int Count;
	int front;
	int rear;
};

Queue Intital(){
	Queue q;
	q.Count=q.front=q.rear=0;
	return q;
}

Queue Add(Queue& q,int x){
	if(q.Count==2)
		cout<<"error";
	else{
		q.Data[q.front]=x;
		q.front=(q.front+1)%10;
		q.Count++;
	}
}

void Output(Queue& q){
	if(q.Count--){
		cout<<q.Data[q.rear]<<' ';
		q.rear=(q.rear+1)%10;
	}
}

void Function(){
	Queue q1=Intital();
	Queue q2=Intital();
	int a,r;
	cin>>a;
	int b[a];
	int j=0;
	while(cin>>r && j<a){
		b[j++]=r;
		if(getchar()!=' ')
			break;
	}
	for(int i=0;i<a;i++){
		if(b[i]%2!=0){
			Add(q1,b[i]);
			if(q1.Count==2){
				Output(q1);
				Output(q1);
				if(q2.Count>0)
					Output(q2);
			}
		}
		else {
			Add(q2,b[i]);
		}
	}
	Output(q1);
	Output(q2);
}

int main(){
	Function();
}
