#include<bits/stdc++.h>
using namespace std;

int k = 100000;
int a[10000] ; int b[10000*4];

void segtreement ( int x , int l , int r ) {
	if ( l == r ) {
		b[x] = a[l];
	} else {
		int middle = ( l + r) / 2 ;
	segtreement( 2 * x , l , middle);
	segtreement( 2 * x + 1 , middle + 1 , r );
		b[x] = min(b[x*2] , b[x*2 + 1]);
	}
	
}

void update( int x, int l , int r , int value, int pos ) {
	if( l== pos && r == pos) {
		b[x] = value;
	} else {
		int middle = ( l + r ) / 2;
			if ( pos <= middle ) {
				update( 2*x, l, middle, value, pos);
			} else {
				update( 2*x+1, middle + 1 , r , value , pos);
			}
				b[x] = min(b[ 2*x ] , b[ 2*x +1]);
	}
	
	
}

int sum( int x , int tl, int tr, int l, int r ) {
	if ( l > r ) return INT_MAX;
	if ( l==tl && r==tr  ) {
		return b[x];
	} else {
		int middle = ( tl + tr) / 2;
		int sum1 = sum( 2*x     , tl         , middle,        l       , min(r,middle));
		int sum2 = sum( 2*x + 1 , middle + 1 , tr    , max(l,middle+1), r            );
		return min(sum1,sum2);
		
	}
	
}





int main () {
	int n,pos,value ; 
	int t ; cin >> n >> t ;
	for ( int i = 0 ; i < n ; i++) cin >> a[i];
	segtreement( 1 , 0 , n-1 );
	while ( t-- ) {
		int select ; cin >> select;
		if ( select== 1) {
			cin >> pos >> value;
			pos--;
			update(1,0,n-1,value,pos);
		} else {
			int l ,r ; cin >> l>> r ;
			l--, r--;
			cout << sum(1,0,n-1,l,r)<< endl;
		}
	}
	
	
	
	
}