#include<iostream>
using namespace std;
int countGI = 0;
int countGR = 0;
int binarySearchIterative();
int binarySearchRecursive();

int binarySearchIterative(int array[],int x, int low, int high){
    while(low<=high){
        countGI ++;
        int mid = low + (high-low)/2 ;
        countGI++;
        countGI++;
        if(array[mid] == x)
          {
            countGI++;
            return mid;
          }
          countGI++;
        if (array[mid]<x)
        { 
          countGI++;
          low = mid+1;
        }
        else
        { 
          countGI++;
           high = mid-1;
        }
    }
    countGI++;
    countGI++;
    return -1;
}
int binarySearchRecursive (int array[], int x, int low, int high) {
  countGR++;
  if (high >= low) {
    int mid = low + (high - low) / 2;
    countGR ++;
    countGI ++;
    if (array[mid] == x)
    { countGR++;
      return mid;
    }
    countGR++;
    if (array[mid] > x)
   { countGR++;
      return binarySearchRecursive(array, x, low, mid - 1);
   }

    countGR++;
    return binarySearchRecursive(array, x, mid + 1, high);
  }
  countGR++;
  return -1;
}
int main()
{
    int array[20],n,x,choice;
    cout<<"enter no. of elements: ";
    cin>>n;
    cout<<"enter "<< n <<" elements: ";
    for(int i=0;i<n;i++)
    cin>>array[i];
    cout<<"Enter the number you want to search: ";
    cin>>x;
    cout<<"Select the method: \n  1.Iterative\n  2.Recursive\n\n";
    cin>>choice;
    if(choice == 1)
    {
     int result = binarySearchIterative(array,x,0,n-1);
     if(result==-1)
     cout<<"Not Found";
     else
     cout<<"Element is found at index: "<<result<<endl;

     cout<<"Steps counted = "<<countGI;
     return 0;
    }
    else{
     int result = binarySearchRecursive(array,x,0,n-1);
     if(result==-1)
     cout<<"Not Found";
     else
     cout<<"Element is found at index: "<<result<<endl;
     cout<<"Steps counted = "<<countGR;
     return 0;
    }

}


