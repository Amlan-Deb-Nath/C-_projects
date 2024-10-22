#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    int size = arr.size();
    int arr1[size] ;

    cout<<size<<"\n";
    
    int temp;
   
    for(int i = 0 ; i< size/2 ; i++ ){
        temp = arr[size-1-i];
        arr[size-1-i] = arr[i];
        arr[i] = temp; 
    }

    int sum = 0 , count = 1 ;

    for(int i = 0 ; i < size ; i++){
        sum+=(arr[i]*count );
        count*=-1;
    }

    cout<<sum<<"\n";

    for (int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }    

    // for(int i=0 ; i<size ;i++){
    //     if(arr[i] % 2 == 0){
    //         for(int j=0 ; j< size ; j++){
    //             arr1[j] = arr[i] ;
    //         }
    //     } else{
    //         int size1 = sizeof(arr1)/sizeof(arr1[0]) ;
    //         for(int j=size1 ; j< size ; j++){
    //             arr1[j] = arr[i] ;
    //     }
    // }
    // }

    return 0 ;
}