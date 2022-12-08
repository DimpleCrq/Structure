#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct ListNode{
	ListNode* next;
	int val;
};

ListNode* SetList(){                                 
	ListNode* Head=(ListNode*)malloc(sizeof(ListNode));
	ListNode *End=Head,*p;
	int c;
	cin>>c;
	Head->val=c;
	char s;
	while(cin>>c){
		s=cin.get();
		p=(ListNode*)malloc(sizeof(ListNode));
		p->val=c;
		p->next=NULL;
		End->next=p;
		End=p;
		if(s=='\n')
			break; 
	}
	p->next=NULL;
	return Head;
}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1=l1,*p2=l2;
		ListNode *l,*p,*s;
		l=new ListNode();
		s=l;
		int k=0;
		int val_1=p1->val;
		int val_2=p2->val;
		while(p1 || p2 || k!=0){
            p=new ListNode();
            p->val=0;
            p->next=NULL; 
            k+=val_1+val_2;
			p->val=k%10;
            if(k>9){
                k=k/10;
            }else k=0;
            s->next=p;
            s=p;
            if(p1){
            	p1=p1->next;
            	if(p1)
            		val_1=p1->val;
				else val_1=0;	
			}
            if(p2){
            	p2=p2->next;
            	if(p2)
            		val_2=p2->val;
				else val_2=0;
			}
        }
		s->next=NULL;
        return l->next;
	}

void Output(ListNode *s){
	ListNode* p=s;
	while(p){
		cout<<p->val;
		p=p->next; 
	}
	cout<<endl;
}

int main(){
	ListNode* l1=SetList();
	ListNode* l2=SetList();
	ListNode* l=addTwoNumbers(l1,l2);
	Output(l);
}

