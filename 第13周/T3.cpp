#include<iostream>
using namespace std;

typedef struct node{
    int num;
    int key;
}Node;

int f(int n,Node* a){
    int i;
    for(i=0;a[i].num;i++){
        if(a[i].key==n){
            return i;
        }
    }
    return i;
}

void swap(Node& a,Node& b){
    a.key=b.key;
    a.num=b.num;
}

void sort(Node* a){
    for(int j=1;a[j].num;j++){
        if(a[j].num>a[j-1].num){
            Node temp=a[j];
            int i=j;
            while(i && temp.num>a[i-1].num){
                swap(a[i],a[i-1]);
                i--;  
            }
            swap(a[i],temp);
        }
    }
}

int main(){
    int n,key;
    cin>>n;
    Node a[n];
    for(int i=0;i<n;i++){
        a[i].num=0;
    }
    for(int i=0;i<n;i++){
        cin>>key;
        a[f(key,a)].key=key;
        a[f(key,a)].num++;
    }
    sort(a);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cout<<a[i].key<<' ';
    }
}