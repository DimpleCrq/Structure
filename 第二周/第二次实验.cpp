#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct Node{
	Node* next;
	int num;
};

void Output(Node* H){                               //��� 
	Node* p=H;
	while(p){
		cout<<p->num<<' ';
		p=p->next;
	}
	cout<<endl;
}

int Length(Node* l){                                //���������� 
	Node* p=l;
	int k=0;
	while(p){
		k++;
		p=p->next;
	}
	return k;
}

Node* SetList(){                                   //����������ʼ�� 
	Node* Head=(Node*)malloc(sizeof(Node));
	Node *End=Head,*p;
	cout<<"������������ڵ�ֵ\n";
	int c;
	cin>>c;
	Head->num=c;
	while((c=cin.get())!='\n'){
		if(c!=' '){
			p=(Node*)malloc(sizeof(Node));
			p->num=c-'0';
			p->next=NULL;
			End->next=p;
			End=p;
		}
	}
	End->next=NULL;
	return Head;
}

Node* Merge(Node *H1,Node* H2){                      //�ϲ� 
	Node *H=(Node*)malloc(sizeof(Node)); 
	Node *p1=H1,*p2=H2,*p=H;
    if(H1->num>=H2->num){
		H->num=H2->num;
		p2=p2->next;
	}
	else{
		H->num=H1->num;
		p1=p1->next;
	}
	while(p1 && p2){
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		if(p1->num<=p2->num){
			p->num=p1->num;
			p1=p1->next;
		}
		else{
			p->num=p2->num;
			p2=p2->next;
		}
	}
	while(p1){
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->num=p1->num;
		p1=p1->next;
	}
	while(p2){
		p->next=(Node*)malloc(sizeof(Node));
		p=p->next;
		p->num=p2->num;
		p2=p2->next;
	}
	p->next=NULL;
	return H;
}

    Node* reverseKGroup(Node* head, int k) {
        Node *t,*r=head;
        t=head;
        int n,m=0;
        for(n=1;n<k && t->next;n++){
            t=t->next;
        }
     //   if(t->next)
      //      m=1;
        if(n==k&&n!=1){
            Node *p,*s;
            p=head;
            s=p->next;
            head->next=NULL;
            while(n>1){
                r=s;
                s=r->next;
                r->next=p;
                p=r;
                n--;
            }
            if(t->next)
                head->next=reverseKGroup(s,k);
        }
        return r;
    }

float Midnum(Node *l1,Node *l2){               //�ǽ������в�����λ�� 
	Node* l=Merge(l1,l2);
	if(Length(l)){
		Node *p=l;
		int k=Length(l),t=k/2;
		if(k%2){
			while(t--)
				p=p->next;
			return (float)p->num;
		}else{
			while(t-- > 1){
				p=p->next;
			}
			return (float)(p->num + p->next->num)/2;
		}
	}else cout<<"error!";
} 

void Reverse(Node* l,int k){                          //����λ�� 
	if(k<1 || k>Length(l))
		cout<<"error!";
	else{
		int m=0,a[k]={};
		Node *tail=l;
		while(m<k-1){
			a[m++]=tail->num;
			tail=tail->next;
		}
		a[m]=tail->num;
		tail=l;
		while(m>=0){
			tail->num=a[m--];
			tail=tail->next; 
		} 
		cout<<"���������\n";
	}
}

void Suffix(Node *l1,Node *l2){                   //������׺ 
	Node *p1=l1,*p2=l2;
	int m=Length(l1),n=Length(l2);
	int *a[m],*b[n];
	for(int i=0;i<m;i++){
		a[i]=&p1->num;
		p1=p1->next;
	}
	for(int i=0;i<n;i++){
		b[i]=&p2->num;
		p2=p2->next;
	}		
	while(a[m-1] && b[n-1] && a[m-1]==b[n-1]){
		m--,n--;
	}
	if(m!=Length(l1)){
		cout<<"������׺:";
		for(int i=m+1;i<=Length(l1);i++)
			cout<<*a[i-1];
		cout<<endl;
	}else cout<<"�޹�����׺��";
} 

int main(){
	Node* s1=SetList();
	s1=reverseKGroup(s1,2);
	Output(s1);
/*	Node* s2=SetList();
	Node* s=Merge(s1,s2);
	Output(s);
	Reverse(s,4);
	Output(s);
	cout<<"��ֵ:"<<Midnum(s1,s2)<<endl;
	
/*	Node* l1=(Node*)malloc(sizeof(Node));    //���Թ�ͬ��׺ 
	l1->num=9;
	l1->next=s1;
	Suffix(l1,s1);*/
}
