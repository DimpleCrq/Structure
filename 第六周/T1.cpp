#include<iostream>
using namespace std;

void Search(int *a,int n){
	int b[100]={};
	int i; 
	for(i=0;a[i]&&a[i]!=n;i++){
		b[i]=a[i];
	} 
	cout<<"˳��������ȽϵĹؼ��֣�"<<endl;
	for(int j=0;j<i;j++){
		cout<<b[j];
		if(j!=i)
			cout<<',';
	}
	cout<<endl<<"˳����ҽ����"<<endl;; 
	cout<<"Ŀ�������"<<n<<"��λ�ã�" <<i<<','<<"�Ƚϴ�����"<<i<<endl; 
} 

int BinarySearch(int *a,int left,int right,int n,int& k){
	int mid=(left+right)/2;
	if(a[mid]==n){
		cout<<"˳����ҽ����"<<endl;; 
		cout<<"Ŀ�������"<<n<<"��λ�ã�" <<n<<','<<"�Ƚϴ�����"<<k<<endl;
		exit(0);
	}
	cout<<"��"<<k<<"�αȽϣ���["<<a[left]<<','<<a[right]<<"]�бȽ�Ԫ��"<<endl; 
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
