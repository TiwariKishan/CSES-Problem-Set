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
struct edge
{
    ll a,b,cost;
};
vector<edge> edg;
void bellman(ll v,ll n,ll m)
{
    vector<ll> d(n,LONG_MAX),p(n);
    d[v]=0;
    p[v]=-1;
    ll x=-1;
    f(i,0,n)
    {
        x=-1;
        f(j,0,edg.size())
        {
            ll a=edg[j].a,b=edg[j].b,cost=edg[j].cost;
            if(d[a]<LONG_MAX)
            {
                if(d[b]>d[a]+cost)
                {
                    d[b]=LONG_MIN<d[a]+cost?d[a]+cost:LONG_MIN;
                    p[b]=a;
                    x=b;
                }
            }
        }
    }
    if(x==-1)
        {cout<<"NO\n";
         return;
        }
        cout<<"YES\n";
    f(i,0,n)
    x=p[x];
    ll y=x,fl=0;
    vector<ll> ans;
    while(x!=y||fl==0)
    {
        ans.pb(x);
        x=p[x];
        fl=1;
    }
    reverse(ans.begin(),ans.end());
    f(i,0,ans.size())
    cout<<ans[i]+1<<" ";
    cout<<ans[0]+1<<"\n";

}
void solve()
{
ll n,m;
cin>>n>>m;
f(i,0,m)
{
    ll u,v,co;
    cin>>u>>v>>co;
    u--;
    v--;
    edge e;
    e.a=u;
    e.b=v;
    e.cost=co;
    edg.push_back(e);
}
bellman(0,n,m);

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
