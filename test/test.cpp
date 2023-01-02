#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 * 2 + 10;

int n;
int a[maxN];
vector <int> adj[maxN];
int sum[maxN];
int dp[maxN];
int dp2[maxN];
int ans = 0;
int SUM = 0;

void dfs1(int node, int father){
    sum[node] = a[node];
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dfs1(newNode, node);
        sum[node] += sum[newNode];
        dp[node] += dp[newNode] + sum[newNode];
    }
}

void dfs(int node, int father){
    
    if (node != father){
        dp2[node] = dp[node] + (dp2[father] - dp[node] - sum[node]);
        ans = max(ans, dp2[node]);  
    }
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        dfs(newNode,node);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        SUM += a[i];
    }

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 2;
    dfs1(root,root);

    for (int i = 1; i <= n; i++){
        cout << i << ": " << dp[i] << endl;
    }

    
    return 0;
}