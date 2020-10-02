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
#define mod          1000000000000000000007
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
vector<vector<pa> > adj(100001);
vector<vector<pa> > e_adj(100001);
vector<ll> st_d(100001,mod);
vector<ll> en_d(100001,mod);
void S_dijstra(ll s,ll n)
{
    set<pa> q;
    q.insert({0,s});
    st_d[s]=0;
    while(!q.empty())
    {
        ll u=q.begin()->se;
        q.erase(q.begin());
        if(st_d[u]==mod) break;
        f(i,0,adj[u].size())
        {
            ll v=adj[u][i].se,w=adj[u][i].fi;
            if(st_d[v]>st_d[u]+w)
            {   q.erase({st_d[v],v});
                st_d[v]=st_d[u]+w;
                q.insert({st_d[v],v});
            }

        }
    }
}
void E_dijstra(ll s,ll n)
{
    set<pa> q;
    q.insert({0,s});
    en_d[s]=0;
    while(!q.empty())
    {
        ll u=q.begin()->se;
        q.erase(q.begin());
        if(en_d[u]==mod) break;
        f(i,0,e_adj[u].size())
        {
            ll v=e_adj[u][i].se,w=e_adj[u][i].fi;
            if(en_d[v]>en_d[u]+w)
            {   q.erase({en_d[v],v});
                en_d[v]=en_d[u]+w;
                q.insert({en_d[v],v});
            }

        }
    }
}
void solve()
{
ll n,m;
cin>>n>>m;
f(i,0,m)
{
    ll u,v,w;
    cin>>u>>v>>w;
    adj[u].pb({w,v});
    e_adj[v].pb({w,u});
}
S_dijstra(1,n);
E_dijstra(n,n);
ll ans=mod;
f(i,1,n+1)
{
    f(j,0,adj[i].size())
    {
        ans=min(ans,st_d[i]+en_d[adj[i][j].se]+(adj[i][j].fi)/2);
    }
}
c(ans);
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
