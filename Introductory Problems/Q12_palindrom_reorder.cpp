#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	string s;
	cin>>s;
	unordered_map<char,int> mp;
	for(auto x:s){
		mp[x]++;
	}
	priority_queue<pair<int,char>> q;
	bool flag=true;
	for(auto x:mp){
		if(x.second%2==1){
			if(flag==false){
				cout<<"NO SOLUTION"<<endl;
				return 0;
			}else{
				flag=false;
			}
		}
		q.push({x.second,x.first});
	}
	int i=0;
	int j=s.size()-1;
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		s[i]=x.second;
		s[j]=x.second;
		i++;
		j--;
		if(x.first-2>0){
			q.push({x.first-2,x.second});
		}

	}
	cout<<s<<endl;
}