#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int sk = 1;
        for(long i = 1; i <= k; i++){
                sk *= 2;
                if (sk > n){
                    break;
                }
        }

        if (sk >= n + 1){
            cout << n + 1 << endl;
        }
        else{
            cout << sk << endl;
        }

    }
    return 0;
}