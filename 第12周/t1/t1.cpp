#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int number,array[128],answer[128];
    int i,r,range=2;
	cin>>number;
	for(i=0;i<number;i++)
        scanf("%d",array+i);
	for(i=0;i<number;i++)
        scanf("%d",answer+i);
	for(i=1;i<number;i++)
        if(answer[i]<answer[i-1])
            break;
	for(r=i;r<number;r++)
        if(answer[r]!=array[r])
            break;
	if(r<number){
		printf("Merge Sort\n");
		while(1){
			for(i=0;i<number;i++)
                if(answer[i]!=array[i])
                    break;
            for(r=0;r<number/range;r++)
                sort(array+r*range,array+(r+1)*range);
            sort(array+number/range*range,array+number);
            if(i==number)
                break;
            range*=2;
		}
        cout<<endl;
	}
	else{
		printf("Insertion Sort\n");
		sort(array,array+i+1);
	}
	for(i=0;i<number;i++){
		if(i)printf(" ");
		printf("%d",array[i]);
	}
    cout<<endl;
	return 0;
}
