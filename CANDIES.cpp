#include<bits/stdc++.h>
using namespace std;
vector<long long > a;
vector<long long > tri;

void Tree( long long x, long long l , long long r ) {
    if(l == r ) {
        tri[x]= a[l];
        return;
    }
    long long mid = (l+r)/2;
        Tree( x*2 , l , mid) ;
        Tree( x*2+1 , mid+1, r );
        tri[x] = max(tri[x*2],tri[x*2+1]);
}

long long get( long long x , long long l, long long r , long long value ) {
    if( l == r ) {
        if ( tri[x] >= value ) {
            tri[x]--;
            return 1;
        }
        return 0 ;
    }
    long long mid = (l+r)/2;
        long long sum1,sum2;
        sum1 = sum2= 0;
        if( tri[x*2] >= value ) {
            sum1 = get(x*2, l, mid , value );
        } 
        if ( tri[x*2+1] >= value) {
            sum2 = get(x*2+1, mid+1,r,value);
        } 

        tri[x]=max(tri[x*2+1],tri[x*2]);
        return sum1+sum2;

}

int main  () {

    long long n ; cin >> n;
    a.resize(n);
    tri.resize(4*n,0);
    for ( int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    Tree(1,0,n-1);
    long long m ; cin >> m ;
    vector<long long > c(m);
    for ( int i= 0 ; i < m ; i++) {
        long long value; cin >> value;
        c[i] = get(1,0,n-1,value);
    }
    for ( int i = 0 ; i < c.size() ; i++) cout << c[i] << endl;
}
