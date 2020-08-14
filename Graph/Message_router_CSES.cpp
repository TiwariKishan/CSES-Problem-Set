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
vector<ll> d(100001);
vector<ll> p(100001);
vector<bool> vis(100001,false);
void bfs(vector<ll> a[],ll s)
{
    queue<ll> q;
    q.push(s);
    d[s]=0;
    p[s]=-1;
    vis[s]=true;
    while(!q.empty())
    {
        ll fr=q.front();
        q.pop();
        f(i,0,a[fr].size())
        {
            if(!vis[a[fr][i]])
            {
                vis[a[fr][i]]=true;
                d[a[fr][i]]=1+d[fr];
                p[a[fr][i]]=fr;
                q.push(a[fr][i]);
            }
        }
    }

}
void solve()
{
ll n,m;
cin>>n>>m;
vector<ll> a[n+1];
f(i,0,m)
{
    ll u,v;
    cin>>u>>v;
    a[u].pb(v);
    a[v].pb(u);
}
bfs(a,1);
if(vis[n])
{
    c(d[n]+1);
    vector<ll> path;
    path.pb(n);
    while(p[n]!=-1)
    {
        path.pb(p[n]);
        n=p[n];
    }
    for(ll i=path.size()-1;i>=0;i--)
        cout<<path[i]<<" ";
    cout<<"\n";
}
else
{
    cout<<"IMPOSSIBLE\n";
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
