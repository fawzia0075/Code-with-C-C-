#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int b[100],i;
    int left=low;
    int right=mid+1;

    for(i=low;left<=mid&& right<=high;i++)
    {
        if(arr[left]<=mid)
        {
            b[i]=arr[left];
            left++;
        }
        else
        {
            b[i]=arr[right];
            right++;
        }
    }

    while(left<=mid)
    {
        b[i]=arr[left];
        i++;
        left++;
    }
    while(right<=high)
    {
        b[i]=arr[right];
        right++;
        i++;
        }

        for(i=low;i<=high;i++)
            arr[i]=b[i];
}

void sort(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        sort(arr,low,mid);
        sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    else
        return;
}

int main()
{
    int n,i,arr[100];
    cout<<"Enter the array size:";
    cin>>n;

     cout<<"Enter the array elements:";
     for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"List before sorting:"<<" ";
      for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
}
cout<<endl;
     sort(arr,0,n-1);

     cout<<"List after sorting array:"<<" ";
     for(i=0;i<n;i++)
     {
       cout<<arr[i]<<" ";
     }

     return 0;
}

