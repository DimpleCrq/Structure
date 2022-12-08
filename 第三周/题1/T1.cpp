#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct Node{
	Node* next;
	int num;
};

void Output(Node* H){                               //输出 
	Node* p=H->next;
	if(p==NULL)
		cout<<"NULL";
	else{
		cout<<'[';
		while(p){
			cout<<p->num;
			p=p->next;
			if(p)
				cout<<',';
		}
		cout<<"]";
	}
}

Node* SetList(){                                   //链表建立并初始化 
	Node* Head=(Node*)malloc(sizeof(Node));
	Node *End=Head,*p;
	int c;
	char s;
	cin>>c;
	Head->num=c;
	while(cin>>c && getchar()){
		if(c==-1)
			break;
		else{
			p=(Node*)malloc(sizeof(Node));
			p->num=c;
			p->next=NULL;
			End->next=p;
			End=p;
		}
	}
	End->next=NULL;
	return Head;
}

Node* Function(Node* l1,Node* l2){
	Node* l=(Node*)malloc(sizeof(Node));
	Node *p1=l1,*p2=l2,*p=l;
	while(p1 && p2){
		if(p1->num<p2->num){
			p1=p1->next;
		}
		if(p1->num==p2->num){
			p->next=(Node*)malloc(sizeof(Node));
			p=p->next;
			p->num=p1->num;
			while(p1->next && p1->next->num==p1->num)
				p1=p1->next;
			p1=p1->next;
			p2=p2->next;
		}
		else{
			p2=p2->next;
		}
	}
	p->next=NULL;
	return l;
}

int main(){
	Node* l1=SetList();
	Node* l2=SetList();
	Node* l=Function(l1,l2);
	Output(l);
}
