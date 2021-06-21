//
// Created by JIANG on 2021/6/18.
//
//Djikstra can get only one path。DFS+Djikstra can be used
//DFS + Djikstra is a template from 《算法笔记》
/**
 *
 * Input  Specification
 * first line   :4 positive integer
 *                N <= 500  - the number of cities
 *                M -the number of roads
 *                C1 - C2 origin - destination
 *  next line   :N integers
 *                 the number of rescue teams
 *  M lines follow: c1, c2 and L, the length of that road
 *
 * Output Specification
 *    in one line 2 numbers:
 *          the number of different shortest ps
 *          the maximum amount of rescue teams you can possibly gather.
 *
 * First,choose the appropriate format according to the question requirements
 * Second,analyze how to solve the problem
 * Third,start coding
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV  = 505;//const是变量常量化，不可被修改
const int INF = 1000000000;
bool vis[MAXV] = {false};
//根据输入格式声明变量
int N,M,C1,C2;//N顶点数 M边数 C1起点路径 C2终点路径

int rescue_team[MAXV],dis[MAXV],G[MAXV][MAXV],ps[MAXV]={0},wei[MAXV]={0};//每个结点的救援队伍数量，图，每个结点的最短路径的数量

int main3()
{
    //initialize
    fill(G[0],G[0]+MAXV*MAXV,INF);
    fill(dis,dis+MAXV,INF);
    int c1,c2,l;//几个要用到的循环变量
    cin>>N>>M>>C1>>C2;
    for(int i = 0; i < N; i ++) cin>>rescue_team[i];
    for (int i = 0; i < M; i ++) {
        cin>>c1>>c2>>l;
        G[c1][c2] = G[c2][c1] = l;
    }
    dis[C1] = 0;
    wei[C1] = rescue_team[C1];
    ps[C1] = 1;
    for(int i = 0;i < N;i ++)
    {
        int min = INF,u = -1;
        for (int j = 0; j < N; j ++)
        {
            if (vis[j] == false && dis[j] < min)
            {
                u = j;
                min = dis[j];
            }
        }
        if(u==-1) break;
        vis[u] = true;
        for (int k = 0; k < N; k++) {
            if (vis[k] == false && G[u][k] != INF)
            {
                if(G[u][k] + dis [u] < dis[k])
                {
                    dis[k] = G[u][k] + dis[u];
                    ps[k] = ps[u];
                    wei[k] = wei[u] + rescue_team[k];

                }
                else if(G[u][k] + dis [u] == dis[k])
                {
                    ps[k] += ps[u];
                    if(wei[u] + rescue_team[k] > wei[k]) {
                        wei[k] = wei[u] + rescue_team[k];
                    }
                }
            }
        }
    }
    printf("%d %d",ps[C2],wei[C2]);
    return 0;
}
