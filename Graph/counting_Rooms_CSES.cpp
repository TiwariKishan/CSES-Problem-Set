/*
  Author - KISHAN TIWARI
  Dream bigger. Do bigger.
  Wake up with determination. Go to bed with satisfaction.
*/
//Sometimes later becomes never. Do it now.
#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define f(i,a,b)     for(ll i=a;i<b;i++)
#define mod          1000000007
#define fi           first
#define se           second
#define pa           pair <ll,ll>
#define mp           make_pair
#define pb           push_back
#define ve           vector<ll>
#define vep          vector< pa >
#define all(a)       a.begin(), a.end()
#define sz(x)        (ll)x.size()
#define c(t)         cout<<t<<"\n"
using namespace std;
vector<vector<bool> > vi(1000,vector<bool>(1000,false));
void dfs(vector<vector<char> > &a,ll i,ll j)
{
    vi[i][j]=true;
    if((i-1)>=0&&!vi[i-1][j]&&a[i-1][j]=='.')
        dfs(a,i-1,j);
    if((j-1)>=0&&!vi[i][j-1]&&a[i][j-1]=='.')
        dfs(a,i,j-1);
    if((i+1)<a.size()&&!vi[i+1][j]&&a[i+1][j]=='.')
        dfs(a,i+1,j);
    if((j+1)<a[0].size()&&!vi[i][j+1]&&a[i][j+1]=='.')
        dfs(a,i,j+1);
}
void solve()
{
ll n,m,count=0;
cin>>n>>m;
vector<vector<char> > a(n,vector<char>(m));
f(i,0,n)
f(j,0,m)
    cin>>a[i][j];
f(i,0,n)
f(j,0,m)
{
    if(!vi[i][j]&&a[i][j]=='.')
    {
        dfs(a,i,j);
        count++;
    }
}
c(count);
}
int main()
{
    ios::sync_with_stdio(true);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
return 0;
}
