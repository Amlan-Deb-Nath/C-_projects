#include<bits/stdc++.h>
#define pi 3.14159265358979

using namespace std;

int main(){
    int r ;
    float x , y ;
    cout<<"Enter the Radious of the Circle : ";
    cin>>r ;

    for(int i = 0 ; i <= 2*r ; i++){

        x = r - sqrt(pow(r,2) - pow( r-i , 2 ));
        x = round(x);

        for(int j = 0 ; j<x ; j++){                       //for the spaces in column
            cout<<"  ";
        }
        y = 2*sqrt(pow(r,2) - pow( r-i , 2 ));
        y = round(y);

        for(int j=0 ; j<=y ; j++){                      //for the pattern in column
            cout<<" *";
        }

        cout<<endl;
    }
    return 0 ;
}
