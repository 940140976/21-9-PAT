#include <iostream>
#include <map>
using namespace std;
int main2() {
    map<int,double> xishu;
    int K;
    cin >> K;
    while (K--) {
        int n;
        double d;
        cin >> n >> d;
        xishu[n] = d;
    }
    cin >> K;
    while (K--) {
        int n;
        double d;
        cin >> n >> d;
        xishu[n] += d;
        if (xishu[n]==0) xishu.erase(n);
    }
    cout<<xishu.size();
    map<int,double>::iterator iter;
    for(iter=xishu.end();iter != xishu.begin();)
    {
        --iter;
        printf(" %d %.1f",iter->first,iter->second);
    }
}

//int main() {
//    double xishu[1001] = {0};
//    int K;
//    cin >> K;
//    while (K--) {
//        int n;
//        double d;
//        cin >> n >> d;
//        xishu[n] = d;
//    }
//
//    int sum = 0;
//    cin >> K;
//    while (K--) {
//        int n;
//        double d;
//        cin >> n >> d;
//        xishu[n] += d;
//    }
//    for (int i = 1000; i >= 0; i--) {
//        if (xishu[i] != 0) sum++;
//    }
//    printf("%d",sum);
//    for(int i = 1000;i >= 0;i--)
//    {
//        if (xishu[i] != 0)
//        {
//            printf(" %d %.1f",i,xishu[i]);
//        }
//    }
//}

/**
* 本题需要注意的是：判断系数为0，则不输出
 * 本题我的错误是：顺序输出错误； 忘记输出sum
 * 本题学到的： double输出格式 %.nf 保留n位小数输出
 *             使用map节省空间
 * 一个大注意点：map的begin end 指向
 *  c++ map 插入数据后，begin(),end()以及当前迭代器的变化

1. map.end()指向map的最后一个元素之后的地址，无论执行map.erase(iter)还是map.add(key, value)，map.end()所返回的值永远不会发生变化，都是指向同一块内存。

2. map.begin()指向map的第一个元素，map.begin()可能随着map.erase(iter)或是map.add(key, value)操作而发生改变。例如当第一个元素被删除后，map.begin()就发生了改变，指向原来第一个元素之后的那个元素了。或是如果新插入一个键值对，该键值对的key放到btree（我们假设map内部是由btree实现的，实际上也可能有别的实现方式）中会排在map.begin()->first的前面，那么map.begin()也会指向新插入的这个键值对了。

3. map.erase(iter)执行后，当前iter就失去意义了，再执行++iter就会出问题。
*/