#include <iostream>
using namespace std;
int count;
void bubbleSort(int a[], int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        count++;
        for(int j=0;j<n-i-1;j++)
        {
            count++;                            
            count++;
            if(a[j]>a[j+1])
            {
                count++;
                swap(a[j],a[j+1]);
            }
        }
    }
    count++;
    count++;
}
int main()
{
    count=0;
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Sorted array is:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    cout<<"The number of steps are:"<<count;
    
    return 0;    
}
