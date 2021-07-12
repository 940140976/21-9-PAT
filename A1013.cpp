#include <iostream>
#include <vector>

using namespace std;

int N,M,K,lost,visited[1000];
vector<int> v[1000];

void dfs(int curcity){
    visited[curcity] = 1;
    for (int i:v[curcity]) {
        if (i!=lost && !visited[i]) dfs(i);
    }
}
int main13(){
    int i,j,k;
    cin>>N>>M>>K;
    for (i = 0; i < M; ++i) {
//        cin>>j>>k;
        scanf("%d %d",&j,&k);
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    while (K--){
        cin>>lost;
        for (i = 1; i <= N; ++i) visited[i] = 0;
        j = 0;
        for (i = 1; i <= N; ++i) {
            if (!visited[i] && i != lost){
                j++;
                dfs(i);
            }
        }
        cout<<j-1<<endl;
    }
}