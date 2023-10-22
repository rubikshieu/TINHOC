#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(s) s.begin(), s.end()
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int random(int left, int right){
    if (left >= right){
        return left;
    }
    return (rng() % (right - left + 1)) + left;
}

void randomTree(int n){
    for (int i = 2; i <= n; i++){
        cout << random(1,i - 1) << " " << i << endl;
    }
}

string randomStr(const int len) {
    static const char alphanum[] =
        "01";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

vector <int> adj[1000];

signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << 5 << endl;
    int n = random(2,3);
    set <ii> s;
    for (int i = 2; i <= n; i++){
        s.insert({random(1,i - 1),i});
    }
    int m = random(1,n);
    while(m--){
        int a = random(1,n - 1);
        s.insert({a, random(a,n)});
    }

    cout << n << " " << s.size() << endl;
    for (int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << endl;
    for (auto i: s){
        cout << i.fi << " " << i.se << " " << random(1,5) << endl;
    }
    return 0;
}