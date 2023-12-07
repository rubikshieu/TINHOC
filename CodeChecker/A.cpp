#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;

int n, m;
ii node[maxN];
vector <ii> adj[maxN];
int dist[maxN];
priority_queue<ii,vector <ii>, greater <ii>> q;


void add(int a, int b, int c){
    if (node[a].fi > node[b].fi){
        return;
    }
    if (node[a].se > node[b].se){
        return;
    }
    adj[a].push_back({c,b});
    // cout << a << " " << b << " " << c << endl;
}

int cost(int a, int b){
    return abs(node[a].fi - node[b].fi) + abs(node[a].se - node[b].se);
}

bool cmpx(int a, int b){
    return node[a].fi < node[b].fi;
}

bool cmpy(int a, int b){
    return node[a].se < node[b].se;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("boards.in", "r")) {
        freopen("boards.in", "r", stdin);
        freopen("boards.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    node[0] = {0,0};
    node[k + k + 1] = {n,n};
    int s = 0;
    int t = k + k + 1;
    add(s,t,cost(s,t));

    vector <int> ls1, ls2;

    for (int i = 1; i <= k; i++){
        cin >> node[i].fi >> node[i].se >> node[i + k].fi >> node[i + k].se;
        add(i, i + k, 0);
        add(s, i, cost(s,i));   
        add(i + k, t, cost(i + k, t));   
        ls1.push_back(i + k);
        ls2.push_back(i);
    }

    sort(all(ls1), cmpx);
    sort(all(ls2), cmpx);
    for (int i = 1; i < ls2.size(); i++){
        add(ls2[i],ls2[i - 1],cost(ls2[i],ls2[i - 1]));
        add(ls2[i - 1],ls2[i],cost(ls2[i],ls2[i - 1]));
    }
    for (int i = 0, j = 0; i < ls1.size(); i++){
        while(node[ls1[i]].fi >= node[ls2[j]].fi and j + 1 > ls2.size()){
            j++;
        }
        add(ls1[i],ls2[j],cost(ls1[i],ls2[j]));
        if (j){
            add(ls1[i],ls2[j - 1],cost(ls1[i],ls2[j - 1]));
        }
        if (j + 1 < ls2.size()){
            add(ls1[i],ls2[j + 1],cost(ls1[i],ls2[j + 1]));
        }
    }

    sort(all(ls1), cmpy);
    sort(all(ls2), cmpy);
    for (int i = 1; i < ls2.size(); i++){
        add(ls2[i],ls2[i - 1],cost(ls2[i],ls2[i - 1]));
        add(ls2[i - 1],ls2[i],cost(ls2[i],ls2[i - 1]));
    }
    for (int i = 0, j = 0; i < ls1.size(); i++){
        while(node[ls1[i]].se > node[ls2[j]].se and j + 1 > ls2.size()){
            j++;
        }
        add(ls1[i],ls2[j],cost(ls1[i],ls2[j]));
        if (j){
            add(ls1[i],ls2[j - 1],cost(ls1[i],ls2[j - 1]));
        }
        if (j + 1 < ls2.size()){
            add(ls1[i],ls2[j + 1],cost(ls1[i],ls2[j + 1]));
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({0,s});
    while(q.size()){
        ii nu = q.top();
        q.pop();
        if (nu.fi != dist[nu.se]){
            continue;
        }
        for (auto i: adj[nu.se]){
            if (dist[i.se] > nu.fi + i.fi){
                dist[i.se] = nu.fi + i.fi;
                // cout << nu.se << " " << i.se << ' ' << i.fi << " " << dist[i.se] << endl;
                q.push({dist[i.se], i.se});
            }
        }
    }
    // for (int i = 0; i <= t; i++){
    //     cout << i << " " << dist[i] << endl;
    // }
    cout << dist[t];

    return 0;
}

/*

*/