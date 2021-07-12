//
// Created by JIANG on 2021/7/1.
//
#include <iostream>
#include <stdio.h>
using namespace std;

int main11(){
    double res = 1;
    for (int i = 0; i < 3; ++i) {
        double a,b,c;
        cin>>a>>b>>c;
        if (a>b && a>c){
            cout<<"W ";
            res*=a;
        } else if(b >c && b > a){
            cout<<"T ";
            res*=b;
        } else{
            cout<<"L ";
            res *= c;
        }
    }
    printf("%.2f",res*1.3-2);
}
