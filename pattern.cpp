#include<bits/stdc++.h>

using namespace std;

void rectangle(int row , int column , char pattern );
void rectangle_1(int row , int column , char pattern );
void rectangle_2(int row , int column , char pattern );
void rectangle_3(int row , int column , char pattern );
void hollow_rectangle(int row , int column , char pattern );
void triangle_1(int row , int column , char pattern );
void triangle_2(int row , int column , char pattern );
void triangle_3(int row , int column , char pattern );
void triangle_4(int row , int column , char pattern );
void triangle_5(int row , int column , char pattern );
void triangle_6(int row , int column , char pattern );
void hollow_triangle(int row , int column , char pattern );

int main(){
    int row , column ;
    char pattern;
    cout<<"The Number of Row : ";
    cin>>row;
    cout<<endl<<"The Number of Column : ";
    cin>>column;
    cout<<endl<<"The pattern : ";
    cin>>pattern;

    rectangle(row, column, pattern);
    rectangle_1(row, column, pattern);
    rectangle_2(row, column, pattern);
    rectangle_3(row, column, pattern);
    hollow_rectangle(row, column, pattern);
    triangle_1(row, column, pattern);
    triangle_2(row, column, pattern);
    triangle_3(row, column, pattern);
    triangle_4(row, column, pattern);
    triangle_5(row, column, pattern);
    triangle_6(row, column, pattern);
    hollow_triangle(row, column, pattern);

    return 0 ;
}

void rectangle(int row , int column , char pattern ){
    for(int i =1 ; i <= row ; i++){
        for(int j = 1 ; j <= column ; j++){
            cout<<pattern<<" ";
        }
        cout<<endl;
    }
}

void rectangle_1(int row , int column , char pattern ){
    for(int i =1 ; i <= row ; i++){
        for(int j = i ; j <= row ; j++){
            cout<<j<<" ";
        }
        for(int j = 1 ; j <= i-1 ; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

void rectangle_2(int row , int column , char pattern ){
    for(int i =1 ; i <= row ; i++){
        for(int j = 1 ; j <= row ; j++){
            if( i==1 || i==row || j==1 || j==row ){
                cout<<j<<" ";
            }else cout<<"  ";            
        }
        cout<<endl;
    }

}

void rectangle_3(int row , int column , char pattern ){
    for(int i =1 ; i <= row ; i++){
        for(int j = 1 ; j <= column ; j++){
            if( (i+j)%2 == 0 ){
                cout<<"1 ";
            }else cout<<"2 ";            
        }
        cout<<endl;
    }

}

void hollow_rectangle(int row , int column , char pattern ){
    for(int i =1 ; i <= row ; i++){
        for(int j = 1 ; j <= column ; j++){
            if( i==1 || i== row || j == 1 || j == column ){
                cout<<pattern<<" "; // An extra space given to look more appropriate
            }else{
                cout<<"  ";  //double space given in the pattern . as there is an extra space in pattern
            }
        }
        cout<<endl;
    }
}

void triangle_1(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout<<pattern<<" ";
        }
        cout<<endl;
    }

}

void triangle_2(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= row-i+1 ; j++){
            cout<<pattern<<" ";
        }
        cout<<endl;
    }

}

void triangle_3(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= row-i ; j++){
            cout<<"  ";
        }
        for(int j = 1 ; j <= 2*i-1 ; j++){
            cout<<pattern<<" ";
        }
        cout<<endl;
    }

}

void triangle_4(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

void triangle_5(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= row-i ; j++){
            cout<<"  ";
        }
        for(int j = 1 ; j <= i ; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

void triangle_6(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= row-i ; j++){
            cout<<"  ";
        }
        for(int j = i ; j >=1 ; j--){
            cout<<j<<" ";
        }
        for(int j = 2 ; j <= i ; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

void hollow_triangle(int row , int column , char pattern ){
    for(int i = 1 ; i<= row ; i++){
        for(int j = 1 ; j <= row-i ; j++){
            cout<<"  ";
        }
        for(int j = 1 ; j <= (2*i-1) ; j++){
            if( i==1 || i==row || j==1 || j==(2*i-1))
            cout<<i<<" ";
            else cout<<"  ";
        }
        cout<<endl;
    }

}