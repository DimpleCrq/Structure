#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[50]={};
    int key;
    for(int i=0;i<n;i++){
        cin>>key;
        a[key]++;
    }
    for(int i=0;i<50;i++){
        if(a[i]){
            cout<<i<<':'<<a[i]<<endl;
        }
    }
}