//
// Created by JIANG on 2021/6/16.
//

#include <iostream>
#include <vector>
using namespace std;
int ma1in1()
{
    int a,b;
    cin>>a>>b;
    int sum = a+b;
    if(sum==0)
    {
        cout<<0;
        return 0;
    }
    if(sum<0)
    {
        cout<<'-';
        sum *= -1;
    }
    vector<int> v;
    while(sum!=0)
    {
        v.emplace_back(sum%10);
        sum /= 10;
    }
    for(int i = v.size()-1;i >= 0;i--)
    {
        cout<<v[i];
        if (i>0&&i%3==0) cout<<',';
    }
    return 0;
}
/**
* 本题需要注意的是：输出顺序
 * 本题粗心错误是：vector的下标开始 应当从0开始
 * 本题学到的新东西是：vector的emplace方法
*/