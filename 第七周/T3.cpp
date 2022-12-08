#include<iostream>
#include<math.h>
using namespace std;

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

int Hash(int key,int Tsize){
	return key%Tsize;
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

HashTable Insert(HashTable H,int key,int* a){
	int k=Hash(key,a[0]);
	int i=1;
	while(H->Cells[k].Info!=Empty && k<a[0]){
		k+=i*i;
		i++;
	}
	if(k<a[0]){
		H->Cells[k].Data=key;
		H->Cells[k].Info=Legitimate;
		H->Tablesize++;
	}
	return H;
}

HashTable Creat(int* a){
	HashTable H=Intital(a[0]);
	int n;
	cin>>n;
	int num,i=1;
	while(1){
		cin>>num;
		a[i++]=num;
		H=Insert(H,num,a);
		if(getchar()=='\n')
			break;
	}
	return H;
}

Position Find(HashTable H,ElementType key,int n){
	int k=Hash(key,n);
	int i=0;
	while(H->Cells[k].Data!=key){
		k+=i*i;
		i++;
		if(k<n && H->Cells[k].Data==key){
			cout<<k;
			exit(0);
		}
		else if(k>=n){
			cout<<'-';
			exit(0);
		}
	}
	cout<<k;
}

void Print(HashTable H,int* a){
	for(int i=1;a[i];i++){
		Find(H,a[i],a[0]);
		if(a[i+1])
			cout<<' ';
	}
}

int Judge(int k){
	if(k==1)
		return 1;
	else{
		for(int i=2;i<=pow(k,0.5);i++){
			if(k%i==0){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int n;
	cin>>n;
	while(Judge(n)==0){
		n++;
	}
	int* a=new int[n+1];
	a[0]=n;
	HashTable H=Creat(a);
	Print(H,a);
}
