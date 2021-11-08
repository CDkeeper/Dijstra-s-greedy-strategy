#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f;
int n, m;
int g[N][N], dist[N], vis[N];
ll sum;
int dijkstra(){
    for (int i = 0; i <= n; ++i){
        dist[i] = INF;
    }
    dist[1] = 0;
    for (int i = 0; i < n; ++i){
        int t = -1;
        for (int j = 1; j <= n; ++j){
            if (!vis[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        for (int j = 1; j <= n; ++j){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        vis[t] = 1;
    }
    if (dist[n] == INF)
        return -1;
    else
        return dist[n];
}
int main(){
    cin >> n >> m;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
    return 0;
}
