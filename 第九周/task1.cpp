#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string>s[100]; 

void function(string str,int x){	
	string word="";
	str+="!"; 	
	for(int i=0; i<str.size();i++){
		if(isalpha(str[i])){		
			if(word.size()<10){
				word+=tolower(str[i]);
			}		 	
		}else{		
			if(word.size()>2){
				s[x].insert(word);
			}
			word.clear();
		} 
	} 
}

int main(){	
	int N;
	cin >>N;	
	getchar(); 	
	for( int i=0;i<N;i++){		
		string s="";		
		while(s!="#"){
			function(s,i);
			getline(cin,s);
		}	
	}
	int n;
	cin >> n; 	
	for(int i=0;i<n;i++){
		int a,b,k = 0;
		cin>>a>>b;	
		a--; b--;	
		int m=s[a].size()+s[b].size();	
		set<string>::iterator t;	
		for(t=s[a].begin();t!=s[a].end();t++){	
			if( s[b].find(*t)!= s[b].end())
			k++;
		} 
		printf("%0.1lf%\n",100.0*k/(m-k)); 		
	} 
} 

