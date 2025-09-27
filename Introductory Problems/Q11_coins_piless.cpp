#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n,k;
	cin>>n>>k;

	if((n+k)%3==0  and min(n,k)*2>=max(n,k)){
		cout<<"YES"<<endl;
		return ;
	}
	cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}