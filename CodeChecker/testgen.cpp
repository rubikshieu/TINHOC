#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
}


signed main(){
    srand(time(0));
    // freopen("input.inp", "r", stdin);
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << 1 << endl;
    int n = 5;
    cout << n << endl;
    for (int i = 1; i <= n; i++){
        cout << random(0,1);
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << random(1,n) << " ";
    }
    cout << endl;
    return 0;
}