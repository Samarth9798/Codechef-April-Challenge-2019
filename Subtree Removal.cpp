#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long int ll;

vector<int> v[100001];
int vis[100001];
ll a[100001];
ll max_sum;
ll k;
int n;

ll dfs1(int x)
{
    vis[x] = 1;
    ll s = a[x];
    for(int i = 0; i < v[x].size(); i++)
        if(vis[v[x][i]] == 0)
            s += max(dfs1(v[x][i]),(-1)*k);
    return s;
}
void solve()
{
    memset(vis,0,sizeof(vis));
    max_sum = max(dfs1(1),(-1)*k);
    cout << max_sum << endl;
}
int main()
{
    fast
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0; i <= n; i++)
                v[i].clear();
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i < n; i++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        solve();
    }
}
