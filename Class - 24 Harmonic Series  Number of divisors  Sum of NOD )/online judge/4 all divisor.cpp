//In the Name of Allah
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e6+123;
vector<int>divisors[mx];

//nln(n);
//10^6*ln(10^6)==1.4*10^6

int main()
{
    optimize();
    int i,j,k,n,t,x,y,z;
    cin>>n;
    for(i=1;i<=n;i++)
    {

        for(j=i;j<=n;j=j+i)
        {
            divisors[j].push_back(i);
        }


    }

    for(i=1;i<=n;i++)
    {
        cout<<i<<"  :  ";
        for(auto u:divisors[i])
        {
            cout<<u<<" ";
        }

        cout<<endl;
    }











    return 0;
}
