#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;  

        unordered_map<long long, long long> mp; 
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;  
        }
		long long count = 0 ;
		for ( int i = 0 ; i < n ; i++) {
			long long hieu = k -a[i];
			if ( hieu == a[i]) {
				count+= mp[hieu] - 1 ;
				mp[a[i]]--;
			} else {
				count+= mp[hieu];
				mp[a[i]]--;
			}	
		}
		cout << count << endl;
    }
}
