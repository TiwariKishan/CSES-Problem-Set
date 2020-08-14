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
vector<ll>used(100001,-1);
bool bfs(vector<ll> adj[],ll s)
{
    queue<ll> q;
    q.push(s);
    used[s]=1;
    bool is_bipartite=true;
    while(!q.empty())
    {
        ll fr=q.front();
        q.pop();
        f(i,0,adj[fr].size())
        {
            if(used[adj[fr][i]]==-1)
                {used[adj[fr][i]]=used[fr]^1;
                 q.push(adj[fr][i]);
                }
            else
            {
                is_bipartite=is_bipartite&(used[adj[fr][i]]!=used[fr]);
            }
        }
    }
    return is_bipartite;
}
void solve()
{
ll n,m;
cin>>n>>m;
vector<ll> adj[100001];
f(i,0,m)
{
    ll u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}
f(i,1,n+1)
if(used[i]==-1)
if(!bfs(adj,i))
{
    cout<<"IMPOSSIBLE\n";
    return;
}
f(i,1,n+1)
cout<<used[i]+1<<" ";
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
