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
vector<vector<ll> > dis(1001,vector<ll>(1001));
vector<vector<bool> > vis(1001,vector<bool>(1001,false));
vector<vector<char> > p(1001,vector<char>(1001));
pair<ll,ll> bfs(vector<vector<char> > &a,ll ip,ll jp)
{
    queue<pair<ll,ll> > q;
    q.push({ip,jp});
    dis[ip][jp]=0;
    vis[ip][jp]=true;
    p[ip][jp]='-';
    while(!q.empty())
    {
        pair<ll,ll> ij=q.front();
        ll i=ij.first,j=ij.second;
        if(a[i][j]=='B')
        {
            return {i,j};
        }
        q.pop();
        if(i+1<a.size()&&!vis[i+1][j]&&(a[i+1][j]=='.'||a[i+1][j]=='B'))
        {q.push({i+1,j});
         vis[i+1][j]=true;
         p[i+1][j]='D';
        }
        if(j+1<a[0].size()&&!vis[i][j+1]&&(a[i][j+1]=='.'||a[i][j+1]=='B'))
        {q.push({i,j+1});
         vis[i][j+1]=true;
         p[i][j+1]='R';
        }
        if(i-1>=0&&!vis[i-1][j]&&(a[i-1][j]=='.'||a[i-1][j]=='B'))
        {q.push({i-1,j});
         vis[i-1][j]=true;
         p[i-1][j]='U';
        }
        if(j-1>=0&&!vis[i][j-1]&&(a[i][j-1]=='.'||a[i][j-1]=='B'))
        {q.push({i,j-1});
         vis[i][j-1]=true;
         p[i][j-1]='L';
        }
    }
    return {-1,-1};
}
void solve()
{
ll n,m;
cin>>n>>m;
vector<vector<char> > a(n,vector<char>(m));
pair<ll,ll> s;
f(i,0,n)
f(j,0,m)
{cin>>a[i][j];
     if(a[i][j]=='A')
     s={i,j};
}
s=bfs(a,s.first,s.second);
ll iu=s.first,ju=s.second;
if(iu==-1)
    cout<<"NO\n";
else
{
    cout<<"YES\n";
    string str="";
    while(1)
    {
        if(p[iu][ju]=='R')
        {
            str+='R';
            ju--;
        }
        else if(p[iu][ju]=='L')
        {
            str+='L';
            ju++;
        }
        else if(p[iu][ju]=='D')
        {
            str+='D';
            iu--;
        }
         else if(p[iu][ju]=='U')
        {
            str+='U';
            iu++;
        }
          else if(p[iu][ju]=='-')
        {
            break;
        }
    }
    c(str.size());
    reverse(str.begin(),str.end());
    c(str);

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
