#include<iostream>
using namespace std;

typedef struct Tree{
	int num;
	Tree* lchild;
	Tree* rchild;
}; 

void BePrint(Tree* node){
	if(node==NULL){
		return;
	}
	BePrint(node->lchild);
	BePrint(node->rchild);
	cout<<node->num<<' ';
}

Tree* GetNode(){
	int n;
	cin>>n;
	Tree* node=new Tree;
	node->num=n;
	node->lchild=node->rchild=NULL;
	return node;
}

Tree* Creat(){
	Tree* Stack[100];
	Tree* Head=GetNode();
	if(getchar()=='\n')
		return Head;
	Tree* node,*p=Head;
	int k=0;
	Stack[k]=Head;
	while(node=GetNode()){
		while(node->num<p->num){
			Stack[++k]=node;
			p->lchild=node;
			p=node;
			if(getchar()=='\n')
				return Head;
			node=GetNode();
		}
		while(node->num>p->num){
			if(k==0){
				p=Stack[k];
				p->rchild=node;
				Stack[0]=node;
				p=node;	
				if(getchar()=='\n')
					return Head;
			}
			else{
				k--;
				if(node->num>=Stack[k]->num){
					if(k==0){
						p=Stack[k];
						p->rchild=node;
						Stack[0]=node;
						p=node;	
						if(getchar()=='\n')
							return Head;
					}
				}
				else{
					++k;
					p=Stack[k];
					p->rchild=node;
					Stack[++k]=node;
					p=node;
					if(getchar()=='\n')
						return Head;
				}
			}
		}
	}
	return Head;
}

void pre_Judge(Tree* node,int* a,int& i){
	if(node==NULL){
		return;
	}
	pre_Judge(node->lchild,a,i);
	a[i++]=node->num;
	pre_Judge(node->rchild,a,i);
}

void pre_Judge2(Tree* node,int* a,int& i){
	if(node==NULL){
		return;
	}
	pre_Judge2(node->rchild,a,i);
	a[i++]=node->num;
	pre_Judge2(node->lchild,a,i);
}

int Judge(Tree* node,int s){
	int a[s]={},b[s]={};
	int i=0,j=0;
	pre_Judge(node,a,i);
	pre_Judge2(node,b,j);
	int m=0,n=0;
	for(int k=0;k<s-1;k++){
		if(a[k]>a[k+1])
			m=1;
		if(b[k]>b[k+1])
			n=1;
	}
	if(m+n>1){
		cout<<"NO";
		return NULL;
	}else{
		cout<<"YES"<<endl;
		BePrint(node);
	}
}

int main(){
	int n;
	cin>>n;
	Tree* Head=Creat();
	Judge(Head,n);
}
