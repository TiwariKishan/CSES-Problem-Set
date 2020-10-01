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
#define sec           second
#define pa           pair <ll,ll>
#define mp           make_pair
#define pb           push_back
#define ve           vector<ll>
#define vep          vector< pa >
#define all(a)       a.begin(), a.end()
#define sz(x)        (ll)x.size()
#define c(t)         cout<<t<<"\n"
using namespace std;
ll inf=LONG_MAX;
vector<vector<pair<ll,ll> > > adj(100001);
vector<ll> dis(100001,inf);
void dijstra(ll s,ll n)
{
    set<pair<ll,ll> > se;
    se.insert({0,s});
    dis[s]=0;
    while(!se.empty())
    {
        ll u=se.begin()->sec;
        se.erase(se.begin());
        if(dis[u]==inf) break;

        f(i,0,adj[u].size())
        { ll v=adj[u][i].fi;
          ll w=adj[u][i].sec;
            if(dis[u]+w<dis[v])
            {   se.erase({dis[v],v});
                dis[v]=dis[u]+w;
                se.insert({dis[v],v});

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
    adj[u].pb({v,w});
    adj[v].pb({u,w});
}
dijstra(1,n);
f(i,1,n+1)
cout<<dis[i]<<" ";
cout<<"\n";
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
