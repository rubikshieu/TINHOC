#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


struct str{
    string s;
    double cal(){
        double res = 0;    
        vector <double> st;
        for (int i = 0; i < s.size(); i++){
            double d = s[i] - '0';
            if (1 <= d and d <= 9){
                st.push_back(d);
            }
            else{
                if (s[i] == '+' or s[i] == '-'){
                    st.push_back(s[i]);
                }
                else if (s[i] == '*'){
                    i++;
                    d = s[i] - '0';
                    double last = st.back();
                    st.pop_back();
                    last *= d;
                    st.push_back(last);
                }
                else{
                    i++;
                    d = s[i] - '0';
                    double last = st.back();
                    st.pop_back();
                    last /= d;
                    st.push_back(last);
                }
            }
        }
        res = st[0];
        for (int i = 1; i < st.size(); i+=2){
            if ((int)st[i] == '+'){
                res += st[i + 1];
            }
            else{
                res -= st[i + 1];
            }
            // cout << st[i] << " ";
        }
        // cout << endl;
        return res;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    str s;
    s.s = "1+1-2*4+5/2+3-3";

    cout << s.cal();


    return 0;
}