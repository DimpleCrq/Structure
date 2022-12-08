#include<iostream>
#include<list>
using namespace std;

typedef struct BT{
	int Data;
	BT* lchild;
	BT* rchild;
}; 

BT* Creat(){           //题 1 
	BT* Head=new BT;
	list<BT*> Queue;     
	int n,k=1,j=1;                
	cin>>n;      
	Head->Data=n;
	Queue.push_back(Head);
	BT* node=Head;
	getchar();
	while(cin>>n){
		if(n==0){
			++k;
			if(k==2*j)
				node->lchild=NULL;
			else if(k==2*j+1)
				node->rchild=NULL;
			if(k==2*j+1){
				Queue.pop_front();
				node=Queue.front();
				j++;
			}
		}
		else{
			BT* p=new BT;
			p->lchild=p->rchild=NULL;
			p->Data=n;    
			Queue.push_back(p);
			++k;
			if(k==2*j)
				node->lchild=p;
			else if(k==2*j+1)
				node->rchild=p;
			if(k==2*j+1){
				Queue.pop_front();
				node=Queue.front();
				j++;
			}
		}
		if(getchar()=='\n')
			break;
	}
	return Head;
}

int Judge_Avl(BT* Tree,BT* Head){               //题2，判断是否为平衡树 
	if(Tree==NULL)
		return 0;
	else{
		int l=Judge_Avl(Tree->lchild,Head);
		int r=Judge_Avl(Tree->rchild,Head);
		if(l-r>1 || r-l>1){
			cout<<"false";
			exit(0);
		}
		if(Tree==Head){
			cout<<"true";
		}
		return l>r ? l+1:r+1;
	}
}

int Judge_ChildStruct(BT* T1,BT* T2,BT* T1_Head,BT* T2_Head){    //题3，判断是否为存在子结构 
	if(!T1 && !T2)	
		return 1;
	if(T1 && !T2)
		return 1;
	if(!T1 && T2)
		return 0;
	if(T1->Data==T2->Data){
		int m=Judge_ChildStruct(T1->lchild,T2->lchild,T1_Head,T2_Head);
		int n=Judge_ChildStruct(T1->rchild,T2->rchild,T1_Head,T2_Head);
		if(m==n==1 && T2==T2_Head){
			cout<<"true";
			exit(0);
		}
		if(m==n)
			return 1;
		else return 0;
	}else if(T1->Data!=T2->Data && T2!=T2_Head){
		return 0;
	}
	if(T2==T2_Head){
		Judge_ChildStruct(T1->lchild, T2, T1_Head, T2_Head);
		Judge_ChildStruct(T1->rchild, T2, T1_Head, T2_Head);
		if(T1==T1_Head)
			cout<<"false";
	}
}

int Max(int a,int b,int c){                            //题4，最大路径和 
	int k=a>b ? a:b;
	return k>c ? k:c;
}

int  DFS(BT* Tree,int &In_Max){
	if(!Tree)
		return 0;
	int l=DFS(Tree->lchild,In_Max);
	int r=DFS(Tree->rchild,In_Max);
	int Out_Max=Max(Tree->Data,l+Tree->Data,r+Tree->Data); 
	In_Max=Tree->Data+r+l>In_Max ? Tree->Data+l+r:In_Max;
	if(Out_Max < 0)
		return 0;
	else return Out_Max;
}

void MAX_Route(BT* Tree){
	int In_Max=0;
	int k=DFS(Tree,In_Max);
	cout<<(k>In_Max ? k:In_Max);
}

void PrePrint(BT* node){                           //输出 
	if(node==NULL){
		return;
	}
	cout<<node->Data<<' ';
	PrePrint(node->lchild );
	PrePrint(node->rchild );
}
void MidPrint(BT* node){
	if(node==NULL){
		return;
	}
	MidPrint(node->lchild );
	cout<<node->Data<<' ';
	MidPrint(node->rchild );
}
void BehPrint(BT* node){
	if(node==NULL){
		return;
	}
	BehPrint(node->lchild);
	BehPrint(node->rchild);
	cout<<node->Data<<' ';
}
void Output(BT* Tree){
	printf("先序遍历结果为: ");
	PrePrint(Tree);
	printf("\n中序遍历结果为: ");
	MidPrint(Tree); 
	printf("\n后序遍历结果为: ");
	BehPrint(Tree);
}


int main(){
	BT* Tree=Creat();
	//Judge_Avl(Tree,Tree);
	//BT* Tree2=Creat();
	//Judge_ChildStruct(Tree,Tree2,Tree,Tree2);
	//MAX_Route(Tree);
	Output(Tree);
}
