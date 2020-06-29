#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    for(i=1;i<=n;i++)
    cin>>arr[i];
    vector <vector <ll> > dp(n+1, vector <ll> (2,0));
    // ll dp[n+1][2]={0};
    ll pos=0,neg=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i]>0)
        {
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1];
        }
        else
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=dp[i-1][0]+1;
        }
        pos+=dp[i][0];
        neg+=dp[i][1];
    }
    cout<<pos<<" "<<neg<<endl;
}