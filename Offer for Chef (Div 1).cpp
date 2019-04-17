#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef unsigned long long int ll;

vector<ll> v;
ll k;
ll sum[55];
int vis[55][55];
set<ll> comp;
set<ll> m[55][55];

set<ll> solve(int x, ll level)
{
    if(level >= k)
    {
        set<ll> ans;
        ans.insert(sum[x]);
        return ans;
    }
    
    ll s = 0;
    set<ll> ans;
    ans.insert(0);
    ll n = v.size()-(k - level);
    
    for(int i = x; i < n; i++)
    {
        s += v[i];
        
        if(vis[i+1][level+1] == 1)
        {
            for(auto j : m[i+1][level+1])
            {
                ll t = (s&j);
                if(t > 0)
                    ans.insert(t);
            }
        }
        else
        {
            
            m[i+1][level+1] = solve(i+1, level+1);
            
            vis[i+1][level+1] = 1;
            
            for(auto j : m[i+1][level+1])
            {
                ll t = (s&j);
                if(t > 0)
                    ans.insert(t);
            }
        }
    }
    
    return ans;
}

int main()
{
    fast
    
    int n;
     
    cin >> n;
    
    ll a[n+5];
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    int q;
    
    cin >> q;
    
    while(q--)
    {
        cin >> k;
        
        v.clear();
        
        for(int i = 0; i < n; i++)
        {
            int t;
            
            cin >> t;
            
            if(t > 0)
                v.push_back(t*a[i]);
        }
        
        assert(v.size() <= 50);
        
        if(v.size() < k)
            cout << '0' << endl;
        else if(k == 1)
        {
            ll ans = 0;
            
            for(int i = 0; i < v.size(); i++)
                ans += v[i];
                
            cout << ans << endl;
        }
        else if(v.size() == k)
        {
            ll ans = v[0];
            
            for(int i = 1; i < v.size(); i++)
            {
                ans = (ans & v[i]);
                if(ans == 0)
                    break;
            }
            
            cout << ans << endl;
        }
        else
        {
            memset(sum,0,sizeof(sum));
            
            for(int i = v.size()-1; i >= 0; i--){
                
                sum[i] = sum[i+1] + v[i];
            }
            
            comp.clear();

            memset(vis,0,sizeof(vis));
            
            comp = solve(0, 1);
            
            cout << *comp.rbegin() << endl;
        }
    }
}
