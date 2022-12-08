#include <iostream>
using namespace std;

void mergeArr(int arr[], int low, int mid, int hight) {
	int* tempArr = new int[hight - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= hight) {
		if (arr[i] < arr[j]) {
			tempArr[k] = arr[i];
			i++;
		}
		else {
			tempArr[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		tempArr[k] = arr[i];
		i++;
		k++;
	}
	while (j <= hight) {
		tempArr[k] = arr[j];
		j++;
		k++;
	}
	i = low;
	for (int tempK = 0;((tempK < k)&&(i<=hight));tempK++) {
		arr[i] = tempArr[tempK];
		i++;
	}
	delete[] tempArr;
	tempArr = NULL;
	
}

void sortArr(int arr[], int low, int hight) {
	if (low < hight) {
		int mid = (hight + low) / 2;
		sortArr(arr,low,mid);
		sortArr(arr, mid + 1, hight);
		mergeArr(arr, low, mid, hight);
	}
}

void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin,right = end;
	int key = arr[begin];
	while (begin < end)
	{
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		while (arr[begin] <= key && begin < end)
		{
		    ++begin;
	    }
    }
        arr[end] = arr[begin];
        arr[begin] = key;
        int keyi = begin;
        QuickSort(arr, left, keyi - 1);
        QuickSort(arr, keyi + 1, right);
}

int main()
{   
    int n;
	cin>>n;
    int a[n];       
	for (int i=1;i<=n;i++)
		cin >>a[i];
    int k;
    cin>>k;
    if(k==1){
        cout<<"Merge Sort"<<endl;
        sortArr(a,0,n);
    }
	else{
        cout<<"Quack Sort"<<endl;
        QuickSort(a,0,n); 
    }
	for (int i=0;i<n;i++)
		cout <<a[i]<<" ";
}