#include "bits/stdc++.h"
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
typedef long long ll;
const int inf = 1000000001;
const ll INF = 1e18 * 4;
using namespace std;

int main(){
    ll N; cin >> N;
    vl A(3*N, 0);
    rep(i, 0, 3*N){
        cin >> A[i];
    }
    priority_queue<ll, vl, greater<ll> > left_pq;
    priority_queue<ll> right_pq;
    vl left(3*N+1, 0);
    vl right(3*N+1, 0);
    ll l_sum=0;
    ll r_sum=0;
    rep(i, 0, N){
        left_pq.push(A[i]);
        l_sum += A[i];
    }
    rep(i, 0, N){
        right_pq.push(A[3*N-i-1]);
        r_sum += A[3*N-i-1];
    }
    left[N] += l_sum;
    right[2*N] += r_sum;

    rep(i, 0, N){
        ll newl = A[N+i];
        l_sum += newl;
        left_pq.push(newl);
        l_sum -= left_pq.top();
        left_pq.pop();
        left[N+i+1] += l_sum;

        ll newr = A[2*N-1 - i];
        r_sum += newr;
        right_pq.push(newr);
        r_sum -= right_pq.top();
        right_pq.pop();
        right[2*N-1 - i] += r_sum;
    }
    ll ans = -inf;
    rep(i, N, 2*N+1){
        ans = max(ans, left[i] - right[i]);
    }

    cout << ans << endl;

    return 0;
}


