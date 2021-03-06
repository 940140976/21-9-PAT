//
// Created by JIANG on 2021/7/1.
//
/**
 * 最佳排名
 * 本题试一下面向对象
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct student{
    string ID;
//    按照优先级
    double grade[4],rank[4];
};
bool comp0(student x,student y){
    return x.grade[0]>y.grade[0];
}
bool comp1(student x,student y){
    return x.grade[1]>y.grade[1];
}
bool comp2(student x,student y){
    return x.grade[2]>y.grade[2];
}
bool comp3(student x,student y){
    return x.grade[3]>y.grade[3];
}
int main12(){
    student s[2001];
    int N,M,i,j,k,l;
    cin>>N>>M;
    //输入成绩
    for (i = 0; i < N; ++i) {
        string temp;
        cin>>temp>>j>>k>>l;
        s[i].ID = temp;
        s[i].grade[0] = ((double )i+j+k)/3;
        s[i].grade[1] = j;
        s[i].grade[2] = k;
        s[i].grade[3] = l;

    }
    sort(s,s+N,comp0);
    for (i = 0; i < N; ++i) {
        if (i == 0 || s[i].grade[0] != s[i-1].grade[0])
            j = i + 1;
        s[i].rank[0] = j;
    }
    sort(s,s+N,comp1);
    for (i = 0; i < N; ++i) {
        if (i == 0 || s[i].grade[1]!=s[i-1].grade[1])
            j = i + 1;
        s[i].rank[1] = j;
    }
    sort(s,s+N,comp2);
    for (i = 0; i < N; ++i) {
        if (i == 0 || s[i].grade[2]!=s[i-1].grade[2])
            j = i + 1;
        s[i].rank[2] = j;
    }
    sort(s,s+N,comp3);
    for (i = 0 ;i < N; ++i) {
        if (i == 0 || s[i].grade[3]!=s[i-1].grade[3])
            j = i + 1;
        s[i].rank[3] = j;
    }

//    开始找最好的排名
    unordered_map<string,int> MAP;
    for (i = 0; i < N; ++i) {
        MAP[s[i].ID] = i;
    }
    while (M--){
        string temp;
        cin>>temp;
        if(!MAP.count(temp)) {
            cout <<"N/A" << endl;
        } else{
            i = MAP[temp];
            int minrank = 2001;
            for (j = 0; j < 4; ++j) {
                if (minrank > s[i].rank[j])minrank = s[i].rank[j];
            }
            if (minrank == s[i].rank[0]){
                   cout<<minrank<<' '<<'A'<<endl;
            }
            else if (minrank == s[i].rank[1])
            {
                cout<<minrank<<' '<<'C'<<endl;
            }
            else if (minrank == s[i].rank[2]){
                cout<<minrank<<' '<<'M'<<endl;
            }
            else{
                cout<<minrank<<' '<<'E'<<endl;
            }
        }
    }
    return 0;
}

