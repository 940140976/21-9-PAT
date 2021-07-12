//
// Created by JIANG on 2021/6/29.
//
#include <iostream>

using namespace std;
int main6(){
     int M;
     cin>>M;
     string earlist_id,latest_id;
     string earlist_singnin= "999",latestsignout= "000";
     for (int i = 0; i < M; ++i) {
         string sid,sin,sout;
         cin>>sid>>sin>>sout;
         if (sin<earlist_singnin){
             earlist_id = sid;
             earlist_singnin = sin;
         }
         if (sout>latestsignout){
             latest_id =sid;
             latestsignout = sout;
         }
     }
    cout<<earlist_id<<' '<<latest_id;
    return 0;
}