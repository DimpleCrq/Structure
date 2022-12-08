#include<iostream>
using namespace std;

#define MAXTABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum{
	Legitimate,Empty,Deleted
}EntryType;
typedef struct HashEntry Cell;
struct HashEntry{
	ElementType Data;
	EntryType Info; 
} ;
typedef struct TblNode *HashTable;
struct TblNode{
	int Tablesize;
	Cell* Cells; 
};

int Hash(int key){
	return key%7;
}

HashTable Intital(){
	HashTable H=new TblNode;
	H->Cells=new Cell[MAXTABLESIZE];
	H->Tablesize=0;
	for(int i=0;i<MAXTABLESIZE;i++){		
		H->Cells[i].Data=NULL;
		H->Cells[i].Info=Empty;
	}
	return H;
}

HashTable Insert(HashTable H,int key){
	int k=Hash(key);
	while(H->Cells[k].Info!=Empty){
		k++;
	}
	H->Cells[k].Data=key;
	H->Cells[k].Info=Legitimate;
	H->Tablesize++;
	return H;
}

HashTable Creat(){
	HashTable H=Intital();
	int n;
	cin>>n;
	int s=n;
	int num;
	while(1){
		cin>>num;
		H=Insert(H,num);
		if(getchar()=='\n')
			break;
	}
	return H;
}

Position Find(HashTable H,ElementType key){
	int k=Hash(key);
	while(H->Cells[k].Data!=key && k<MAXTABLESIZE){
		k++;
		if(k==MAXTABLESIZE){
			cout<<"ERROR";
			exit(0);
		}
		else if(H->Cells[k].Data==key){
			cout<<key<<" is at position "<<k<<endl;
			exit(0);
		}else if(H->Cells[k].Data==NULL){
			cout<<key<<" is not found. "<<"Position "<<k<<" is returned"<<endl;
			exit(0);
		}
	}
}

int main(){
	HashTable H=Creat();
	int n;
	cin>>n;
	Find(H,n);
}
/*
11
11 88 21 -1 -1 5 16 7 6 38 10

*/
