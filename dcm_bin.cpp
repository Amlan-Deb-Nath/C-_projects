#include<bits/stdc++.h>

using namespace std;

int main(){
    long dcm;
    long bin = 0 ;
    long power = 1 ;
    cout<<"Enter a Decimal Number : ";
    cin>>dcm;

    while(dcm > 0){
        long lastdigit = dcm%2 ;
        bin += (lastdigit*power);
        power *= 10;
        dcm /=2;
    }
    cout<<"The binary number is : "<<bin;

    return 0 ;
}