#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> tree;
void maketree(vector<int>& v,int i,int j,int ind){
	if(i>j)return ;
	if(i==j){
		tree[ind]=v[i];
		return ;
	}
	int mid=i+(j-i)/2;
	maketree(v,i,mid,ind*2);
	maketree(v,mid+1,j,ind*2+1);

	tree[ind]=min(tree[ind*2],tree[ind*2+1]);
	return ;
}
ll query(int i,int j,int qs,int qe,int ind){
	if(i>j)return INT_MAX;
	if(i>qe || j<qs)return INT_MAX;
	if(qs<=i and qe>=j){
		return tree[ind];
	}

	int mid=i+(j-i)/2;
	ll left=query(i,mid,qs,qe,ind*2);
	ll right=query(mid+1,j,qs,qe,ind*2+1);

	return min(left,right);

}
int main(){
	int n,k;
	cin>>n>>k;
	tree.resize(4*n+1,0);
	vector<int> v(n);
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		v[i]=x;
	}
	maketree(v,0,n-1,1);

	int a,b;
	for(int i=0;i<k;i++){
		cin>>a>>b;
		ll ans=query(0,n-1,a-1,b-1,1);
		cout<<ans<<endl;
	}
	return 0;
}