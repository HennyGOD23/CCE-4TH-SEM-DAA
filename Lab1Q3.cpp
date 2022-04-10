#include<iostream>

using namespace std;
int countG =0;


void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){ //done
        countG++;
        int key = a[i]; // done
        countG++;
        int j = i-1; //done
        countG++;
        while(j>=0 && a[j]>key){ //done
            countG++;
            a[j+1] = a[j]; // done  
            countG++;
            j = j-1;  // done
            countG++;
        }
        countG++;  //while end, done
        a[j+1] = key; // done
        countG++;
    }
    countG++;
}

int main(){
    int arr[10]; 
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array after sorting is:"<<endl;
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"countG = "<<countG;
    return 0;
}