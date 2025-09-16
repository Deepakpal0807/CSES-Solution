#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> tree;

void build(int i,int j,int index,vector<ll>& v){
	if(i>j)return ;
	if(i==j){
		tree[index]=v[i];
		return ;
	}

	int mid=i+(j-i)/2;
	build(i,mid,index*2,v);
	build(mid+1,j,index*2+1,v);

	tree[index]=max(tree[index*2],tree[index*2+1]);
} 

ll query(int i,int j,int ind,int val){
	if(i>j)return 0;
	if(tree[ind]<val)return 0;

	if(i==j){
		tree[ind]-=val;
		return i+1;
	}
	int mid=i+(j-i)/2;

	ll left=query(i,mid,ind*2,val);

	if(left!=0){
     tree[ind]=max(tree[ind*2],tree[ind*2+1]);
		return left;
	}
	int right= query(mid+1,j,ind*2+1,val);

    tree[ind]=max(tree[ind*2],tree[ind*2+1]);
    return right;

}

int main(){
	int n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	tree.resize(4*n+1);
	build(0,n-1,1,v);

	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		ll ans=query(0,n-1,1,x);
		cout<<ans<<" ";
	}
    cout<<endl;
}