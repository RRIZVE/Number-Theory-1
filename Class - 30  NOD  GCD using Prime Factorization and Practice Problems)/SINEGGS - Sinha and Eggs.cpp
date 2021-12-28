//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int MX = 1e6+123;
bitset<MX> is_prime;
vector<int> prime;

void primeGen ( int n )
{
    n += 100;
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 )
    {
        if ( is_prime[i] == 1 )
        {
            for ( int j = i*i; j <= n; j += ( i + i ) )
            {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[2] = 1;
    prime.push_back (2);

    for ( int i = 3; i <= n; i += 2 )
    {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}


int NOD (long long n) // 60
{
    int ret = 1;
    for ( auto p : prime )   // p = 5
    {
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 )
        {
            int cnt = 1;

            while ( n % p == 0 )   // n = 5
            {
                n /= p; // n = 5;
                cnt++; // 2
            }

            ret *= cnt; // 1 * 3 * 2
        }
    }

    if ( n > 1 ) ret *= 2; // 1 * 3 * 2  * 2 = 12

    return ret;
}



int main()
{
    optimize();

    int lim = 1e6;
    primeGen ( lim );

    int t,x,y;
    long long n,m;

    cin>>t;
    while(t--)
    {
        cin>>n;
        m=NOD(n);
        if(m%2==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }












    return 0;
}
