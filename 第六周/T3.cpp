#include<iostream>
#include<list>
using namespace std;

typedef struct AVL{
	int Data;
	int Height;
	AVL* lchild;
	AVL* rchild;
}; 

int Max(int a,int b){
	return a>b ? a:b;
}

int High(AVL* Tree){
	if(!Tree)
		return 0;
	else return Tree->Height;
}

AVL* RR(AVL* Tree){
	AVL* Temp=Tree->rchild;
	Tree->rchild=Temp->lchild;
	Temp->lchild=Tree;
	Tree->Height=Max(High(Tree->lchild),High(Tree->rchild))+1;
	Temp->Height=Max(High(Tree->lchild),High(Tree->rchild))+1;
	return Temp;
}

AVL* LL(AVL* Tree){
	AVL* Temp=Tree->lchild;
	Tree->lchild=Temp->rchild;
	Temp->rchild=Tree;
	Tree->Height=Max(High(Tree->lchild),High(Tree->rchild))+1;
	Temp->Height=Max(High(Tree->lchild),High(Tree->rchild))+1;
	return Temp;
}

AVL* RL(AVL* Tree){
	Tree->rchild=LL(Tree->rchild);
	Tree=RR(Tree);
	return Tree;
}

AVL* LR(AVL* Tree){
	Tree->lchild=RR(Tree->lchild);
	Tree=LL(Tree);
	return Tree;
}

AVL* Get_Height(AVL* Tree){
	if(!Tree)
		return NULL;
	Tree->lchild=Get_Height(Tree->lchild);
	Tree->rchild=Get_Height(Tree->rchild);
	Tree->Height=Max(High(Tree->rchild),High(Tree->lchild))+1;
	return Tree;
}

AVL* Get_Balance(AVL* Tree){
	if(!Tree)
		return NULL;
	Tree->lchild=Get_Balance(Tree->lchild);
	Tree->rchild=Get_Balance(Tree->rchild);
	if(High(Tree->rchild)-High(Tree->lchild)>=2)
		if(High(Tree->rchild->rchild)-High(Tree->rchild->lchild)==1)
			Tree=RL(Tree);
		else Tree=RR(Tree);
	if(High(Tree->lchild)-High(Tree->rchild)>=2)
		if(High(Tree->lchild->rchild)-High(Tree->lchild->lchild)==1)
			Tree=LR(Tree);
		else Tree=LL(Tree);
	Tree->Height=Max(High(Tree->rchild),High(Tree->lchild))+1;
	return Tree;
}

AVL* Creat(){
	AVL* Head=new AVL;
	int n;
	cin>>n;
	AVL* node;
	Head->Data=n;
	Head->lchild=Head->rchild=NULL;
	node=Head;
	while(cin>>n){
		AVL* p=new AVL;
		p->Data=n;
		p->lchild=p->rchild=NULL;
		node->lchild=p;
		node=p;
		if(getchar()=='\n')
			break;	
	}
	Head=Get_Height(Head);
	return Head;
}

void PrePrint(AVL* node){ 
	if(node==NULL){
		return;
	}
	cout<<node->Data<<' ';
	PrePrint(node->lchild );
	PrePrint(node->rchild );
}
void MidPrint(AVL* node){
	if(node==NULL){
		return;
	}
	MidPrint(node->lchild );
	cout<<node->Data<<node->Height<<' ';
	MidPrint(node->rchild );
}

int main(){
	int n;
	cin>>n;
	AVL* Tree=Creat();
	Tree=Get_Balance(Tree);
	cout<<Tree->Data;
}
