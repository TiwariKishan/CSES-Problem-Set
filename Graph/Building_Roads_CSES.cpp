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
vector<bool> vis(100001,false);
void dfs(vector<ll> adj[],ll s)
{
    vis[s]=true;
    f(i,0,adj[s].size())
    {
        if(!vis[adj[s][i]])
            dfs(adj,adj[s][i]);
    }
}
void solve()
{
ll n,m;
cin>>n>>m;
vector<ll> adj[n+1];
f(i,0,m)
{
    ll u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
vector<ll> v;
f(i,1,n+1)
{
    if(!vis[i])
    {
        dfs(adj,i);
        v.pb(i);
    }
}
if(v.size()<=1)
    c(0);
else
{
    c(v.size()-1);
    f(i,0,v.size()-1)
    cout<<v[i]<<" "<<v[i+1]<<"\n";
}
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
