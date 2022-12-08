#include<iostream>
using namespace std;

void Search(int *a,int n){
	int b[100]={};
	int i; 
	for(i=0;a[i]&&a[i]!=n;i++){
		b[i]=a[i];
	} 
	cout<<"顺序查找所比较的关键字："<<endl;
	for(int j=0;j<i;j++){
		cout<<b[j];
		if(j!=i)
			cout<<',';
	}
	cout<<endl<<"顺序查找结果："<<endl;; 
	cout<<"目标查找数"<<n<<"的位置：" <<i<<','<<"比较次数："<<i<<endl; 
} 

int BinarySearch(int *a,int left,int right,int n,int& k){
	int mid=(left+right)/2;
	if(a[mid]==n){
		cout<<"顺序查找结果："<<endl;; 
		cout<<"目标查找数"<<n<<"的位置：" <<n<<','<<"比较次数："<<k<<endl;
		exit(0);
	}
	cout<<"第"<<k<<"次比较：在["<<a[left]<<','<<a[right]<<"]中比较元素"<<endl; 
	if(n<a[mid])
		BinarySearch(a,left,mid,n,++k);
	else BinarySearch(a,mid,right,n,++k);
}

int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int k=1;
	Search(a,9);
	BinarySearch(a,0,9,9,k);
}
