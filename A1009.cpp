//
// Created by JIANG on 2021/7/1.
//
/**
 * 多项式乘法
 * 本题坑点在于数组应该开到2001
 * 输出格式建议用printf
 * 从高到低输出
 * 好奇怪，又错在哪里了？
 */
#include <iostream>
double arr1[1001]={0.0},res[2001]={0.0},arr2;
int count =0 ;
using namespace std;

int main9(){
    int N,M,ind,i;
    cin>>N;
    for (i = 0; i < N; ++i) {
        cin>>ind;
        cin>>arr1[ind];
    }
    cin>>M;
    for (i = 0; i < M; ++i) {
        cin>>ind;
        cin>>arr2;
//        特别主义，这个地方不应该是N，应该是1001
        for (int j = 0; j < 1001; ++j) {
            res[ind+j] += arr1[j] * arr2;
        }
    }
    for (int i = 0; i < 2001; ++i) {
        if (res[i]!=0.0)count++;
    }
    cout<<count;
    for (int i = 2000; i >=0; i--) {
        if (res[i]!=0.0)
            printf(" %d %.1f",i,res[i]);
    }
    return 0;
}
