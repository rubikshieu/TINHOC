#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define iii pair <ii,int>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
vector <ii> adj[maxN];
ii visited[maxN];
int POW[maxN];
int cntLim = 0;

int getLen(int a){
    if (a < 10){
        return 1;
    }
    if (a < 100){
        return 2;
    }
    if (a < 1000){
        return 3;
    }
    if (a < 10000){
        return 4;
    }
    if (a < 100000){
        return 5;
    }
    if (a < 1000000){
        return 6;
    }
    if (a < 10000000){
        return 7;
    }
    if (a < 100000000){
        return 8;
    }
    if (a < 1000000000){
        return 9;
    }
    if (a < 10000000000){
        return 10;
    }
    return 0;
}

ii add(ii a, ii b){
    ii res = b;
    res.fi += a.fi;
    // if (getLen(b.se) >= 15){
    //     cout << "LMAO" << endl;
    //     exit(1);
    // }
    res.se += a.se * POW[getLen(b.se)];
    // while(res.se >= mod){
    //     res.se -= mod;
    //     res.fi++;
    // }   
    res.fi += res.se / mod;
    res.se %= mod;
    return res;
}

void init(){
    POW[0] = 1;
    for (int i = 1; i <= n; i++){
        visited[i] = {inf,inf};
    }
    visited[1] = {0,0};
    for (int i = 1; i <= 15; i++){
        POW[i] = POW[i - 1] * 10;
    }
}

void dickcha(){
    priority_queue <iii,vector<iii>,greater<iii>> q;
    q.push({{0,0},1});
    while(!q.empty()){
        iii t = q.top();
        q.pop();
        // cout << "#" << t.se << endl;
        if (visited[t.se] != t.fi){
            continue;
        }
        for (auto nu: adj[t.se]){
            cntLim++;
            // if (cntLim >= 1e5 + 10000){
            //     cout << cntLim << " adudarkqua" << endl;
            //     exit(1);
            // }
            ii w = add(t.fi, {0,nu.fi});
            if (visited[nu.se] > w){
                visited[nu.se] = w;
                q.push({w,nu.se});
                // cout << nu.se << "," << w.se << " ";
            }
        }
        // cout << endl;
    }
}

void dfs(int node, int father){
    for (auto newNode: adj[node]){
        if (father == newNode.se){
            continue;
        }
        visited[newNode.se] = add(visited[node], {0,newNode.fi});
        // (visited[newNode.se].se = visited[node].se * POW[getLen(newNode.fi)] + newNode.fi) %= mod;
        dfs(newNode.se,node);
    }
}

signed main(){
    
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }

    init();
    // if (n - 1 == m){
    //     dfs(1,1);
    // }
    // else{
        dickcha();
    // }

    for (int i = 2; i <= n; i++){
        cout << visited[i].se << endl;
    }


    return 0;
}