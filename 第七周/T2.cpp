#include<iostream>
using namespace std;

//#define MAXTABLESIZE 100000
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
	return key%5;
}

HashTable Intital(int n){
	HashTable H=new TblNode;
	H->Cells=new Cell[n];
	H->Tablesize=0;
	for(int i=0;i<n;i++){		
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

HashTable Creat(int* a){
	int s;
	cin>>s;
	HashTable H=Intital(s);
	int num,i=0;
	while(1){
		cin>>num;
		a[i++]=num;
		H=Insert(H,num);
		if(getchar()=='\n')
			break;
	}
	return H;
}

Position Find(HashTable H,ElementType key){
	int k=Hash(key);
	while(H->Cells[k].Data!=key){
		k++;
		if(H->Cells[k].Data==key){
			cout<<k;
			exit(0);
		}
	}
	cout<<k;
}

void Print(HashTable H,int* a){
	int n=0;
	for(int i=0;a[i];i++){
		Find(H,a[i]);
		n++;
		if(n!=H->Tablesize)
			cout<<' ';
	}
}

int main(){
	int n;
	cin>>n;
	int* a=new int[n];
	HashTable H=Creat(a);
	Print(H,a);
}

/*
4 5
24 15 61 88
*/
