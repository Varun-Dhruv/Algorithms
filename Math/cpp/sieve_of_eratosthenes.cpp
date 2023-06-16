#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define totalPrimes 1000
#define int long long
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> isPrime(totalPrimes,1);
	for(int i=2;i<sqrt(totalPrimes-1);i++){
		for(int j=i;j<totalPrimes;j=j+i){
			if(j==i)
				continue;
			else if(isPrime[j]==1){
				isPrime[j]=0;
			}
		}
	}
	for(int i=1;i<totalPrimes;i++){
		if(isPrime[i]) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}