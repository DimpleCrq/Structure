#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv) {
	string s;
	cout<<"Input:";
	getline(cin,s);
	cout<<"Output:";
	for(int i=s.length()-1;i>=0;i--)
		cout<<s[i];
	return 0;
}
