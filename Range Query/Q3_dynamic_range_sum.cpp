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

	tree[ind]=tree[ind*2]+tree[ind*2+1];
	return ;
}
ll query(int i,int j,int qs,int qe,int ind){
	if(i>j)return 0;
	if(i>qe || j<qs)return 0;
	if(qs<=i and qe>=j){
		return tree[ind];
	}

	int mid=i+(j-i)/2;
	ll left=query(i,mid,qs,qe,ind*2);
	ll right=query(mid+1,j,qs,qe,ind*2+1);

	return left+right;

}
void update(int i,int j,int index,int val,int ind){
	if(i>j)return ;
	if(i==j and i==index){
             tree[ind]=val;
             return ;
	}
	if(i>index || j<index){
		return ;
	}

	int mid=i+(j-i)/2;
	update(i,mid,index,val,ind*2);
	update(mid+1,j,index,val,ind*2+1);

	tree[ind]=tree[ind*2]+tree[ind*2+1];
	return ;
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

	int a,b,c;
	for(int i=0;i<k;i++){
		cin>>a>>b>>c;
		if(a==2){
		ll ans=query(0,n-1,b-1,c-1,1);
		cout<<ans<<endl;
	   }else{
        update(0,n-1,b-1,c,1);
	   }
	}
	return 0;
}