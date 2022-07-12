#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        while (m--){
            int x, y;
            cin >> x >> y;
            int l = -1;
            int r = -1;
            for (int i = 1; i <= n; i++){
                if (x == a[i]){
                    l = i;
                    break;
                }
            }
            for (int i = l; i <= n; i++){
                if (y == a[i]){
                    r = i;
                }
            }
            if (l == -1 or r == -1){
                cout << "NO";
            }
            else if (l < r){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
            cout << endl;

        }
        // cout << endl;
    }
    return 0;
}