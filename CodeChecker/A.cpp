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

int nxt[100];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DIGIT.inp", "r")) {
        freopen("DIGIT.inp", "r", stdin);
        freopen("DIGIT.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    nxt[1] = 9;
    // int t = 9;
    for (int i = 2, t = 9; i <= 18; i++){
        nxt[i] = t * 10 * i;
        t *= 10;
        // t += nxt[i];
    }
    // cout << t << endl;
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int t = 1;
        while(n - nxt[t] > 0){
            n -= nxt[t];
            t++;
        }
        // cout << n << " " << t << endl;
        for (int s = pow(10,t - 1); 1; s++){
            if (n - t > 0){
                n -= t;
                continue;
            }
            vector <int> ls;
            while(s){
                ls.push_back(s % 10);
                s /= 10;
            }
            reverse(all(ls));
            // cout << n - 1 << " ";
            cout << ls[n - 1] << endl;
            // for (auto i: ls){
            //     cout << i;
            // }
            // cout << endl;
            break;
        }
    }
    return 0;
}

/*


*/