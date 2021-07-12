//
// Created by JIANG on 2021/6/29.
//
/**
 * PAT难度不大但是繁琐
 * 主要模拟多 图论多 字符串多 数组多
 * 注意：函数不能返回数组，但是可以返回数组的引用
 *
 * cctype用法
 * @param num
 */
#include <iostream>
#include <cctype>
using namespace std;

string str[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main5(){
    char c;
    int sum=0;//initialize
    while (isdigit(c=getchar()))
    {
        sum+=c-'0';
    }
    string temp = to_string(sum);
    for (int i =0 ;i < temp.size();i++)
    {
        if (i>0) cout<<' ';
        cout<<str[temp[i]-'0'];//此处严格注意temp[i]是字符型数据，应该减去'0'
    }
    return 0;
}