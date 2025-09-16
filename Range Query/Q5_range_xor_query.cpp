#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	// vector<ll> v(n);
	ll x;
	vector<int> dp(n+1,0);
	for(int i=0;i<n;i++){
		cin>>x;
		// v[i]=x;
		dp[i+1]=dp[i]^x;
	}
	// for(int i=1;i<=n;i++){
	// 	dp[i]=dp[i-1]^v[i-1];
	// }

	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
        // cout<<a<<" : "<<b<<endl;
		
        cout<<(dp[b]^dp[a-1])<<endl;
	}
}