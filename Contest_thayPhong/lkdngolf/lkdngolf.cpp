#include<bits/stdc++.h>
using namespace std;


int main (){
int t;
cin>>t;
while(t--){
    int n,x,k;
    cin>>n>>x>>k;
    if (k%x==0 or (n+1-x)%k==0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}


return 0;
}
