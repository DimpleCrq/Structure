#include<iostream>
using namespace std;

int function(int* a){
	int sum=0;
	for(int i=0;a[i] && i<sizeof(a);i++){
		sum+=a[i];
	}
	cout<<sum<<endl;
	int b[3]={-1};
	int j=0;
	for(;sum%10,sum>0;j++){
		b[j]=sum%10;
		sum=sum/10;
	}
	j--;
	while(j>-1){
		switch(b[j]){
			case 0:
				cout<<"ling";
				break;
			case 1:
				cout<<"yi";
				break;
			case 2:
				cout<<"er";
				break;
			case 3:
				cout<<"san";
				break;
			case 4:
				cout<<"si"; 
				break;
			case 5:
				cout<<"wu";
				break;
			case 6:
				cout<<"liu";
				break;
			case 7:
				cout<<"qi";
				break;
			case 8:
				cout<<"ba";
				break;
			case 9:
				cout<<"jiu";
				break;
			default:
				cout<<"error!";
		}
		if(j--)
			cout<<' ';
	}
} 

int main(){
	int a[100]={0};
	int s;
	int j=0;
	while((s=getchar())!='\n'){
		a[j++]=s;
	}
	function(a);
}
