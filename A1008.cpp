//
// Created by JIANG on 2021/7/1.
//
/**
 * 本题坑点在于若与当前层数相同，应停留5s
 */
#include <iostream>

using namespace std;
int main8(){
    int N,current=0,next,time=0;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>next;
        if(current==next){
            time+=5;
        } else if(next>current){
            time += (next - current) * 6 + 5;
        } else{
            time += (current - next) * 4 + 5;
        }
        current = next;
    }
    cout<<time;
    return 0;
}
