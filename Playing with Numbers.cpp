#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef unsigned long long int ll;

vector<int> adj[100005];
ll n;
ll v[100005];
ll m[100005];
int vis[100005];
vector<int> leaves;
int parent[100005];

void dfs(int x)
{
    vis[x] = 1;
    if(adj[x].size() == 1 and x > 1)
        leaves.push_back(x);
    for(int i = 0; i < adj[x].size(); i++){
        if(vis[adj[x][i]] == 0)
        {
            parent[adj[x][i]] = x;
            dfs(adj[x][i]);
        }
    }
    
}

ll solve(int x, ll mod)
{
    stack<int> s;
    
    s.push(x);
    
    ll gcd = v[x];
    
    while(!s.empty())
    {
        x = s.top();
        s.pop();
        
        if(x > 1)
            s.push(parent[x]);
        
        gcd = __gcd(gcd, v[x]);
    }
    
    gcd = __gcd(gcd, mod);
    
    return (mod - gcd);
}

int main()
{
    fast
    
    int t;
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        for(int i = 0; i <= n; i++)
            adj[i].clear();
            
        for(int i = 0; i < n-1; i++)
        {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        leaves.clear();
        
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        for(int i = 1; i <= n; i++)
            cin >> m[i];
        
        memset(vis,0,sizeof(vis));
        parent[1] = 1;
        
        dfs(1);
        
        sort(leaves.begin(),leaves.end());
        
        vector<ll> ans;
        
        for(int i = 0; i < leaves.size(); i++)
        {
            ans.push_back( solve(leaves[i] , m[ leaves[i] ]) );
        }
        
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
            
        cout << endl;
    }
}
