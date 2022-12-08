#include<iostream>
using namespace std;

#define SIZE 100

typedef struct Queue{
	int Data[SIZE];
	int front;
	int rear;
};

Queue Intital(){
	Queue q;
	q.front=q.rear=0;
	return q;
}

Queue Add(Queue& q,int x){
	q.Data[q.front]=x;
	q.front=(q.front+1)%SIZE;
}

int Output(Queue& q){
	int n=q.Data[q.rear];
	q.rear=(q.rear+1)%SIZE;
	return n;
}

void function(){
	Queue q=Intital();
	long long int n,r,s,t;
	cin>>n;
	int i=n;
	if(n)
		cout<<1<<endl;
	Add(q,1);
	while(--i){
		r=s=0;
		for(int j=0;j<n-i;j++){
			r=Output(q);
			t=r+s;
			cout<<t<<' ';
			Add(q,t);
			s=r;
		}
		Add(q,1);
		cout<<1;
		cout<<endl;
	}
}

int main(){
	function();
}
