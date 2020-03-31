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
#define vpii vector<pair<int, int> >
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

int reverse01(int i){
    return (1 - i) * (1 - i); 
}

int main(){
    int N; cin >> N;
    string s;
    cin >> s;
    // hitsuji: 0, okami: 1
    vpii init = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vi ans_animal;

    bool found = false;
    rep(j, 0, 4){
        vi animal(N, -1);
        animal[0] = init[j].first;
        animal[1] = init[j].second;
        rep(i, 1, N-1){
            bool okami = (animal[i] == 1);
            if((okami && s[i] == 'o') || (!okami && s[i] == 'x')){
                animal[i+1] = reverse01(animal[i-1]);
            }
            if((okami && s[i] == 'x') || (!okami && s[i] == 'o')){
                animal[i+1] = animal[i-1];
            }
        }
        // i=0 and test i=0's saying
        bool mujun = false;
        vi tmp = {0, N-1};
        for(auto &i : tmp){
            bool okami = (animal[i] == 1);
            int bac, fro;
            if(i==0){
                bac = N-1;
                fro = 1;
            } else {
                bac = N-2;
                fro = 0;
            }
            if((okami && s[i] == 'o') || (!okami && s[i] == 'x')){
                if(animal[bac] != animal[fro]) continue;
                else mujun = true;
            }
            if((okami && s[i] == 'x') || (!okami && s[i] == 'o')){
                if(animal[bac] == animal[fro]) continue;
                else mujun = true;
            }
        }
        if(!mujun){
            found = true;  
            ans_animal = animal;
            break;
        }
    }
    if(found){
        rep(i, 0, N){
            if(ans_animal[i] == 0) cout << "S";
            else cout << "W";
        }
        cout << endl;
    } else {
        cout << "-1";
    }
    return 0;
}


