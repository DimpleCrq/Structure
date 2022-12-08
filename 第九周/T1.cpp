#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define SIZE 26

typedef struct node{
    string str;
    node* next;
}; 

struct h{
    int size;
    node* array;
};
typedef struct h* Hash;

void Initial(Hash& H){
    H->size=SIZE;
    H->array=new node[H->size];
    for(int i=0;i<H->size;i++){
        H->array[i].next=NULL;
    }
}

int HashKey(string key){
	unsigned int hashnum=key[0];
    if(hashnum>96)
        hashnum-=32;
	return hashnum-'A';
} 

string Judge1(string s){
	auto k=s.size();
	if(k<3){
        string s2;
        s2.clear();
		return s2;
	}else{
		if(k>10){
			string s2;
			for(int i=0;i<10;i++){
				s2+=s[i];
			}
			return s2;
		}else return s;
	}
}
vector<string> Judge(string s){
    string h=Judge1(s);
  //  cout<<h<<' ';
    vector<string> t;
    string s1;
        for(int i=0;h[i];i++){
            int k=0;
            if(h[i]>96 && h[i]<123 &&h[i]!=46)
                k=1;
            if(h[i]>64 && h[i]<91 && h[i]!=46)
                k=1;
            if(k==1){
                s1+=h[i];
            }
            else if(k==0){
             //   cout<<s1<<endl;
                t.push_back(s1);
                string s1;
            }
        }
   /*     vector<string> t2;
        while(t.size()){
            string b=t.back();
            t.pop_back();
            string v=Judge1(b);
            if(v.size())
                t2.push_back(v);
        }*/
    return t;
}


bool Judge_Aa(string s1,string s2){
	int i=0;
	while(s1[i]==s2[i] || s1[i]-32==s2[i] || s2[i]-32==s1[i]){
		i++;
		if(!s1[i] && s2[i])
			return false;
		if(s1[i] && !s2[i])
			return false;
		if(!s1[i] && !s2[i])
			return true;
	}
	return false;
}

bool Find(Hash& H,string s){
    int k=HashKey(s);
    node* p=H->array[k].next;
    while(p && !Judge_Aa(p->str,s)){
        p=p->next;
        
    }
    if(p){
        return true;
    }else return false;
}

void Insert(Hash& H,string s){
        if(Find(H,s)){}
        else{
            int k=HashKey(s);
            node* p=new node;
            p->str=s;
            p->next=H->array[k].next;
            H->array[k].next=p;
        }
}

int function(Hash& H,vector<string> s,auto l){
    int k=0;
    for(int i=0;i<(int)l;i++){
        if(Find(H,s[i]))
            k++;
    }
    return k;
}

void Function(){
    int n;
    cin>>n;
    Hash *H=new Hash[n];
    for(int i=0;i<n;i++){
    	H[i]=new h;
    	Initial(H[i]);
	}
    getchar();
	vector<vector<string>> s(n);
    vector<string> m;
    string c;
    int j=0;
    while(j<n){
        while(cin>>c){
        	m=Judge(c);
            while(m.size()){
                string e=m.back();
                m.pop_back();
                Insert(H[j],e);
                s[j].push_back(e);
            }
            if(getchar()=='\n')
                break;
        }
        getchar();
        getchar();
        j++;
    }
    int r,a,b;
    cin>>r;
    float q[r]={};
    float t;
    for(int i=0;i<r;i++){
        cin>>a>>b;
        float k=function(H[a-1],s[b-1],s[b-1].size());
        float l=(s[a-1].size()+s[b-1].size()-k);
        t=k/l;
        q[i]=t;
    }
    for(int i=0;i<r;i++){
       cout<<q[i]*100<<'%'<<endl;
    }
}

int main(){
    Function();
}

/*
2
This is a test to show ... 
#
Not similar at all
#
1
1 2


2
These two files are the same 
#
these.two_files are the SAME 
#
1
1 2


2
This is a test for repeated repeated words.
#
All repeated words shall be counted only once. A longlongword is the same as this longlongwo.
#
1
1 2

*/
