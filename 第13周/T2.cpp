#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void function(int a[],int n,int k,int t){
    int d=t+1;
    int max_a=*max_element(a,a+n);
    int min_a=*min_element(a,a+n);
    int bucket_num=(max_a-min_a)/d+1;
    vector<vector<int> > bucket(bucket_num);
    for(int i=0;i<n;i++){
        int order=(a[i]-min_a)/d;
        if(bucket[order].size()!=0){
            cout<<"true";
            exit(0);
        }else{
            if(order-1>=0 && bucket[order-1].size()!=0)
                if(a[i]-*max_element(bucket[order-1].begin(),bucket[order-1].end())<=t){
                    cout<<"true";
                    exit(0);   
                }
            if(order+1>=0 && order+1<bucket_num && bucket[order+1].size()!=0)
                if(*min_element(bucket[order+1].begin(),bucket[order+1].end())-a[i]<=t){
                    cout<<"true";
                    exit(0);   
                }
            bucket[order].push_back(a[i]);
        }
        if(i>=k){
            order=(a[i-k]-min_a)/d;
            bucket[order].erase(bucket[order].begin());
        }
    }
    cout<<"false";
}

int main(){
    int a[6]={1,5,9,1,5,9};
    function(a,6,2,3);
}