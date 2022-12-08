#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int function(int a[],int k){
    if(k<2)
        return 0;
    int max_a=*max_element(a,a+k);
    int min_a=*min_element(a,a+k);
    int d=(max_a-min_a)/(k-1);
    int bucket_num=(max_a-min_a)/d+1;
    vector<pair<int,int>> bucket(bucket_num,{-1,-1});
    for(int i=0;i<k;i++){
        int order=(a[i]-min_a)/d;
        if(bucket[order].first==-1)
            bucket[order].first=a[i];
        else{
            if(a[i]<bucket[order].first)
                bucket[order].first=a[i];
            else bucket[order].second=max(a[i],bucket[order].second);
        }
    }
    int max_deep=0;
    for(int i=0,j=0;i<bucket_num && j<bucket_num;){
        while(i<bucket_num && bucket[i].first==-1)
            i++;
        j=i+1;
        while(j<bucket_num && bucket[j].first==-1)
            j++;
        if(i<bucket_num && j<bucket_num){
            if(bucket[i].second==-1)
                max_deep=max(max_deep,bucket[j].first-bucket[i].first);
            else max_deep=max(max_deep,bucket[j].first-bucket[i].second);
            i=j;
        }
    }
    return max_deep;
}

int main(){
    int a[4]={3,6,9,1};
    cout<<function(a,4);
}