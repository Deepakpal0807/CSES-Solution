#include <bits/stdc++.h>
using namespace std;

// Macros
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vvll vector<vector<long long>>
#define vl vector<long long>

// Precompute 2D prefix sum
void solve(vvll& arr) {
    int n = arr.size() - 1;   // since arr is (n+1)x(n+1)
    
    // row-wise prefix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    // col-wise prefix
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            arr[i][j] += arr[i-1][j];
        }
    }
}

// Query submatrix sum
int findans(vvll& arr,int x1,int y1,int x2,int y2){
    return arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
}

int main(){
    fastio;

    int n,k;
    cin >> n >> k;
    
    vvll v(n+1, vl(n+1, 0));
    char x;

    // input grid
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            if(x=='*') v[i+1][j+1] = 1;
        }
    }

    // build prefix sum
    solve(v);

    // process queries
    while(k--){
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << findans(v,y1,x1,y2,x2) << "\n";
    }

    return 0;
}
