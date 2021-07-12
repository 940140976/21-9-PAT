//
// Created by JIANG on 2021/6/29.
//
/**
 * 坑坑坑坑
 * 粗心 因为将44行的     if(result<0)cout<<0<<' '<<A[0]<<' '<<A[K-1]; 后一个A[K-1]写成了A[K]，后来测试了一下过了
 * 最大连续子列和问题
 * 状态转移方程：dp[i] = max{dp[i-1]+A[i],A[i]}
 * 暴力解法需要o(n),但是本题左端点的枚举是没有必要的，可以从第一个到最后一个建立一种顺序，
 *                                          本题具有无后效性，即dp[i]只用到dp[i-1]的信息，不会用到dp[i]以后的信息
 *  边界是dp[0] = A[0];
 *  本题需要考虑边界，变化一下
 *
 *  PAT好坑啊
 *  错了2个案例，不知道是为啥，有时哪个恶心人的特殊例子
 */
#include <iostream>
int A[10001] = {0};
int sum[10001] = {0};
int head[10001] = {0};
using namespace std;

int main7(){
    int K,result=-1,h,tail;
    cin>>K;
    for (int i = 0; i < K; ++i)  cin>>A[i];
    for (int i = 0; i < K; ++i) {
        if(i == 0) {
            sum[0] = A[0];
        }else {
            if (sum[i - 1] + A[i] > A[i]) {
                sum[i] = sum[i - 1] + A[i];
                head[i] = head[i - 1];
            } else {
                sum[i] = A[i];
                head[i] = i;
            }
        }
        if (sum[i]>result){
            result = sum[i];
            h = head[i];
            tail = i;
        }
    }
    if(result<0)cout<<0<<' '<<A[0]<<' '<<A[K-1];
    else cout<<result<<' '<<A[h]<<' '<<A[tail];
    return 0;
}

