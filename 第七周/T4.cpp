#include<iostream>
#include<string>
using namespace std;
#define Size 10

typedef struct LNode* PtrToLNode;
typedef string ElementType;
struct LNode{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef struct TblNode *HashTable;
struct TblNode{
	int TableSize;
	List Heads;
};

HashTable Intital(){
	HashTable H=new TblNode;
	H->TableSize=Size;
	H->Heads=new LNode[Size];
	for(int i=0;i<Size;i++){
		H->Heads[i].Next=NULL;
	}
	return H;
}

int Hash(ElementType s){
	int i=0,k=0;
	while(s[i]){
		k+=s[i];
		i++;
	}
	return k%Size;
} 

HashTable Insert(HashTable H,ElementType s){
	int k=Hash(s);
	List node=new LNode;
	node->Data=s;
	node->Next=NULL;
	node->Next=H->Heads[k].Next;
	H->Heads[k].Next=node;
	return H;
}

HashTable Creat(){
	HashTable H=Intital();
	string s;
	while(cin>>s){
		H=Insert(H,s);
		if(getchar()=='\n')
			break;
	}
	return H;
}

bool Delete(HashTable H,ElementType s){
	int k=Hash(s);
	if(H->Heads[k].Next && H->Heads[k].Next->Data==s){
		List p=H->Heads[k].Next;
		H->Heads[k].Next=p->Next;
		free(p);
		cout<<s<<" is deleted from list Heads["<<k<<"]"<<endl;
		return true;
	}
	List node=H->Heads[k].Next;
	while(node->Next && node->Next->Data!=s){
		node=node->Next;
	}
	if(!node->Next && node->Data!=s)
		return false;
	else{
		List p=node->Next;
		node->Next=p->Next;
		free(p);
		cout<<s<<" is deleted from list Heads["<<k<<"]"<<endl;
	}
}

int main(){
	HashTable H=Creat();
	Delete(H,"able");
	Delete(H,"key");
}

// zero able key very bye day
