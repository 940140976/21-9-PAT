//
// Created by JIANG on 2021/6/21.
//
/***
 * 用树的层次遍历思想做
 * 需要额外的层号信息，稍微有点麻烦
 * *****1.因为while(!q.empty)忘记加感叹号，所以就一直没有进去循环
 * *****2.因为段错误只过了一个测试用例，后来把maxl初始化为0就通过了
 * 逻辑理解了但是很容易粗心
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN= 210;
int lay[MAXN]={0};
int l,maxl=0;

struct node{
    int layer = 0;
    int data;
    vector<int> child ;
}Node[MAXN];

void LayerOrder(int root){
    queue<int> Q;
    Q.push(root);
    while(!Q.empty())
    {
        int front = Q.front();
        Q.pop();
        for (int i = 0 ;i < Node[front].child.size();i++) {
            int child = Node[front].child[i];
            Node[child].layer = Node[front].layer+1;
            Q.push(child);
        }
        l=Node[front].layer;
        if (Node[front].child.size()==0 )
            lay[l] ++;
        maxl = l>maxl?l:maxl;
    }
}
int main(){
    int N,M,K,ID,child;
    cin>>N>>M;
    for (int i = 0; i < M; i++) {
        cin>>ID>>K;
        for (int j = 0; j < K; j++) {
            cin>>child;
            Node[ID].child.push_back(child);
        }
    }
    LayerOrder(1);
    for (int i = 0; i <= maxl; i++) {
        if (i==0) cout<<lay[i];
        else cout<<" "<<lay[i];
    }
    return 0;
}

/**
* int n;
vector<int> Adj[MAXV];
bool visq[MAXV];
//遍历u所在的连通块
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visq[u] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0 ;i < Adj[u].size();i++) {
            int v = Adj[u][i];
            if (visq[v] == false)
            {
            q.push(v);
            visq[v] = true;
            }
        }
    }
}

void BFSTravel(int G[][MAXV])
{
    for(int u = 0;u<n;u++)
    {
        if(visq[u]=false)
            BFS(u);
    }
}
*/
/**
*#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXV= 50;
vector<int> Adj[MAXV];
int layers[MAXV] = {0};//记录每个结点的层高
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0 ;i < Adj[p].size();i++) {
            int v = Adj[p][i];
                q.push(v);
                layers[v] = layers[p] + 1;
        }
    }
}
int main(){
    int N,M,K,ID,child;
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        cin>>ID>>K;
        for (int j = 0; j < K; ++j) {
            cin>>child;
            Adj[ID].emplace_back(child);
        }
    }
    BFS(0);
    //看看这层是否有non-leaf结点
    for (int i = 0; i < N; ++i) {
        int lay= i,num=0;
        for (int j = 0; j < N; ++j) {
            if(layers[j]==i && Adj[j].size()!=0)
                ++num;
        }
        if (num!=0)
            cout<<lay<<" "<<num<<"\n";
    }
}
 *
*/