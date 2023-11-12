#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int dp[maxN];
int mk[maxN];

bool cmp(int a, int b){
    return mk[a] < mk[b];
}

void dfs(int nu){
    vector <ii> ls;
    for (auto i: adj[nu]){
        dfs(i);
        ls.push_back({dp[i],i});
    }
    sort(rall(ls));
    for (int i = 0; i < (int)ls.size(); i++){
        dp[nu] = max(dp[nu], ls[i].fi + i);
        mk[ls[i].se] = i;
    }
    sort(all(adj[nu]), cmp);
}

void trace(int nu){
    // cout << nu << endl;
    for (auto i: adj[nu]){
        trace(i);
    }
    if (adj[nu].size()){
        cout << adj[nu].size();
    }
    else{
        cout << "a";
    }
}

signed main(){
    freopen("A.out", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    int n = 0;
    vector <int> st;
    string s;
    cin >> s;
    for (auto c: s){
        n++;
        if (c == 'a'){
            dp[n] = 1;
            st.push_back(n);
        }
        else{
            int t = c - '0';
            while(t--){
                adj[n].push_back(st.back());
                // cout << n << ' ' << st.back() << endl;
                st.pop_back();
            }
            st.push_back(n);
        }
    }

    dfs(n);
    // cout << dp[n] << endl;
    if ((dp[n] == x)){
        cout << x << endl;
        cout << s;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}