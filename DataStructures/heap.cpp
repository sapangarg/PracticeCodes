// Program to insert values in a heap and then make it a max heap or a min heap


#include<iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;


void rearrange_to_max_heap(int arr[], int index)
{

	for(int i=index/2; i>0; i--)
	{
		int temp, j;
		int child=2*i;
		while(child<=index)
		{
			if(arr[child]<arr[child+1])
				child=child+1;

			if(arr[i]< arr[child])
			{
				temp = arr[child/2];
				arr[child/2] = arr[child];
				arr[child] = temp;
				child = 2*child;
			}

			else if(arr[i] >= arr[child])
				break;
			i=child/2;
	
		}
	}
	//arr[child/2] = arr[i];
return;
}




void rearrange_to_min_heap(int arr[], int index)
{

	for(int i=index/2; i>0; i--)
	{
		int temp, j;
		int child=2*i;
		while(child<=index)
		{
			if(arr[child]>arr[child+1])
				child=child+1;

			if(arr[i] > arr[child])
			{
				temp = arr[child/2];
				arr[child/2] = arr[child];
				arr[child] = temp;
				child = 2*child;
			}

			else if(arr[i] <= arr[child])
				break;
			i=child/2;
	
		}
	}
	//arr[child/2] = arr[i];
return;
}




int main()
{
	int n;
	cout<<"\n enter the number of elements in the heap";
	cin>>n;
	int arr[n+2];
	for(int i =1; i<n+1;i++)
	{
		cin>>arr[i];
	}
	
	rearrange_to_max_heap(arr,n);
	rearrange_to_min_heap(arr,n);

	for(int i = 1 ; i<n+1; i++)
	{
		cout<<arr[i]<<"\n";
	}
return 0;
}
