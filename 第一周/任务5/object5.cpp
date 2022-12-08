#include <iostream>
using namespace std; 

void function(int a){
	int b[3]={0};
	int i=2;
	while(a){
		b[i--]=a%10;
		a/10;
	}
	cout<<"Output:";
	for(int j=0;j<b[0];j++)
		cout<<"B";
	for(int j=0;j<b[1];j++)
		cout<<"S";
	for(int j=0;j<b[2];j++)
		cout<<j+1;
} 

int main(int argc, char** argv) {
	int a;
	cout<<"Input:";
	cin>>a;
	function(a);
	return 0;
}
