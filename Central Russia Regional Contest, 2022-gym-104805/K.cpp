#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <omp.h>

using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define OO 4e18
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<ll,ll>, null_type,greater<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define nl '\n'
#define pii pair<ll,ll>
#define ld long double
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define posmod(v,m) ((v%m)+m)%m
#define all(v) (v.begin(),v.end())
#define allg(v) (v.begin(),v.end(),greater<ll>())
#define ELROSHDY ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


//vctor<vector<ll>> gf (N)
ll xr[] = { -1,1,0,0 ,1,-1,-1,1};
ll yr[] = { 0,0,1,-1 ,1,-1,1,-1};
//ll xr[]={0,0,1,1};
//ll yr[]={0,1,0,1};
const ll mod =  1e9+7;
const int M =  998244353;

set<ll>se;
map<pii,bool>isvis;
void calc(vector<ll> &v2,int ind ,int n,ll pref,ll l)
{
    if(pref>l)return ;
    if(isvis[{pref,ind}])return;
    isvis[{pref,ind}]=1;
    if(pref)
    se.insert(pref);
    if(ind>=n)return ;
    while(pref<=l)
    {
        calc(v2,ind+1,n,pref,l);
        pref+=pref*v2[ind]+v2[ind];
    }
}

void solve(int t) {
    ll n ,l;cin>>n>>l;
    vector<ll>v(n);
    vector<ll> v2;
    set<ll> s;
    fr(i,n) {
        cin >> v[i];
        if(v[i]<=l)
        s.insert(v[i]);
    }
    for(auto i:s)v2.pb(i);
    v.resize(s.size());
    v=v2;
    n=s.size();


    calc(v2,0,n,0,l);
    cout<<se.size()<<nl;
}
int main() {
    //    freopen("car.in", "r", stdin);
    //            freopen("output.txt", "w", stdout);
    ELROSHDY

    ll t = 1;
//         cin>>t;



    //    string t;
    while (t--) {


        solve(t);

    }
}