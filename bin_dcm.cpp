#include<bits/stdc++.h>

using namespace std;

int main(){
    long bin;
    long dcm = 0;
    long power = 1;

    cout<<"Enter a Binary number : ";
    cin>>bin;
    
    while(bin>0){
        long lastdigit = bin%10;
        dcm +=(lastdigit*power);
        power*=2;
        bin/=10;
    }

    cout<<"The Decimal number is : "<<dcm;

    return 0;
}
