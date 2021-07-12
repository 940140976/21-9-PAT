//
// Created by JIANG on 2021/7/1.
//
/**
 * 预先准备：将给出的数的进制放在N1，未给出的放在N2
 * 1.将N1转为10进制表示
 * 2. 开始遍历进制寻找N2的合适进制
 *
 *
 * ####有两个比较刁钻的测试点
 *
 */
//#include <iostream>
//
//using namespace std;
//int trans(char c){
//    if(c>='0'&&c<='9') return c-'0';
//    else return c-'a'+10;
//}
////进制转换
//long long translate(string n,int r){
//    int sum = 0;
//    for(int i = n.size()-1,unit = 1;i>=0;i--,unit*=r)
//    {
//        int j = trans(n[i]);
//        sum+=j*unit;
//    }
//    return sum;
//}
//int translate2(string N,long long r,long long value)
//{
//    long long sum = 0;
//    for (long long i = N.size() -1 ,unit = 1; i >= 0 ; i--,unit *= r) {
//        if (unit > value) return 1;
//        long long  j = trans(N[i]);
//        sum += j*unit;
//    }
//    if (sum > value) return  1;
//    if (sum < value) return  -1;
//    if (sum == value) return  0;
//}
// int main(){
//     string N1,N2;
//     long long tag,radix,r2;
//     cin>>N1>>N2>>tag>>radix;
//     if(tag==2) {
//         string tempstr = N1;
//         N1 = N2;
//         N2 = tempstr;
//     }
//     long long value = translate(N1,radix);
//     int maxdigit = 0;
////     对N2进行遍历，找出最大的数
//     for (char c:N2) {
//         int j = trans(c);
//         if(j>maxdigit) maxdigit = j;
//     }
////     测试是否超时
////    return 1;
//     //注意这个地方循环是为了找到r2的值，不必在循环体离写其他东西
////     成功到达34行
////     for (r2 = maxdgit+1; translate(N2,r2)<value;r2++);
////     经测试,此处超时,考虑改用二分法
////  本题最大范围是INT_MAX,需要把左右变量都改成long long
////     return 1;
//        long long low,high;
////     二分之前先判断如果最大数+1正好是满足条件的话,那么直接输出----此种情况对应有不同的进制能使结果成立.此种情况意味着,只含有个位,对于值含有个位的书来说,结果菜可能有多种情况
//
//     for (low = maxdigit + 1; low <= high;) {
//         long long mid = low + (high - low) / 2;
//         int temp = translate2(N2,mid,value);
//         if ((temp == 0)){
//             cout<<mid;
//             return 0;
//         }
////         long long temp = translate(N2,mid);
////         if (temp == value) {
////             cout<<mid;
////             return 0;
////         }
////         if (temp < value)low = mid + 1;
//         if (temp < 0) low = mid + 1;
//         else high = mid - 1;
//     }
////         if (translate(N2,r2)==value){
////             cout<<r2;
////             return 0;
////         }
////仍然有错,原因是如果有好几种满足情况,输出最小的`
//    cout<<"Impossible";
//     return 0;
// }
#include <iostream>
using namespace std;
int trans(char c){
    if(c>='0'&&c<='9') return c-'0';
    else return c-'a'+10;
}
long long translate(string n,int r){
    int sum = 0;
    for(int i = n.size()-1,unit = 1;i>=0;i--,unit*=r)
    {
        int j = trans(n[i]);
        sum+=j*unit;
    }
    return sum;
}
int translate2(string N,long long r,long long value)
{
    long long sum = 0;
    for (long long i = N.size() -1 ,unit = 1; i >= 0 ; i--,unit *= r) {
        if (unit > value) return 1;
        long long  j = trans(N[i]);
        sum += j*unit;
    }
    if (sum > value) return  1;
    if (sum < value) return  -1;
    if (sum == value) return  0;
}
int main10(){
    string N1,N2;
    long long tag,radix,r2;
    cin>>N1>>N2>>tag>>radix;
    if(tag==2) {
        string tempstr = N1;
        N1 = N2;
        N2 = tempstr;
    }
    long long value = translate(N1,radix);
    int maxdigit = 0;
    for (char c:N2) {
        int j = trans(c);
        if(j>maxdigit) maxdigit = j;
    }
    long long low,high;
    for (low = maxdigit + 1; low <= high;) {
        long long mid = low + (high - low) / 2;
        int temp = translate2(N2,mid,value);
        if ((temp == 0)){
            cout<<mid;
            return 0;
        }
        if (temp < 0) low = mid + 1;
        else high = mid - 1;
    }
    cout<<"Impossible";
    return 0;
}
