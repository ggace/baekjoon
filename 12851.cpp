typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()
#define PRIME_SIZE 5
#define PIE M_PIf64
#define arri(n) array<int, n>
#define arrl(n) array<ll, n>
#define input(type, value) type value; cin >> value;

#ifdef BOJ
#define debug(x)  ((void)0);
#define debug_value(x)  ((void)0);
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#else
#define debug(x)  cout << "[Debug] " << x;
#define debug_value(x)  cout << "[Debug] " << #x << " is " << x << '\n';
#define fio ((void)0);
#endif

#include <bits/stdc++.h>

using namespace std;

class Direction {
    public:
        int dx;
        int dy;
};

class Position {
    public:
        int x;
        int y;
};

ll fastpow(ll a, ll n, ll c){
    ll result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=c) result%=c;
        }
        a*=a;
        if(a>=c) a%=c;
        n>>=1;
    }
    return result;
}

vector<ll> prime_list;
bool is_prime[PRIME_SIZE+1] = {1,1,0}; // 0이 소수
void siv(ll n) {
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) prime_list.push_back(i);
        for(auto p : prime_list) {
            if(i*p > n) break;
            is_prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}
/*
int visited[101010];
map<int, int> m;
// time:    node: count
void solution(ll n, ll k){
    memset(visited, -1, sizeof(visited));
    m[n] = 1;
    for(ll i = 0; ; i++) {
        map<int, int> map_by_time;

        //cout << i << ": \n";
        int cnt = 0;
        for (auto iter = m.begin() ; iter !=  m.end(); iter++) {
            int node = iter->first;
            int count = iter->second;
            cnt++;

            //cout << node << " " << count << "\n";

            if(node == k) {
                cout << i << "\n" << count << "\n";
                exit(0);
            }

            if(node *2 <= 100000) {
                if(visited[node*2] < i || visited[node*2] == -1) {
                    continue;
                }
                visited[node * 2] = i;
                map_by_time[node*2]++;
            }
            if(node +1 <= 100000) {
                if(visited[node+1]< i || visited[node+1] == -1) {
                    continue;
                }
                visited[node +1] = i;
                map_by_time[node+1]++;
            }
            if(node -1 >= 0) {
                if(visited[node-1] < i || visited[node-1] == -1) {
                    continue;
                }
                visited[node -1] = i;
                map_by_time[node-1]++;
            }
            
        }
        m = map_by_time;
        if(cnt == 0) {
            break;
        }
        

    }
}
*/

vector<ll> result(101010);
ll visited[101010];
priority_queue<pll> pq; //-time, value

ll result_time = LONG_LONG_MAX;

void solution(int n, int k) {
    memset(visited, -1, sizeof(visited));
    
    pq.push({0, n});

    while(!pq.empty()) {
        auto [time, value] = pq.top();
        pq.pop();
        time = -time;

        //cout << time << " " << value  << "\n";

        if(result_time < time) {
            break;
        }

        if(visited[value] < time && visited[value] != -1) {
            continue;
        }        
        else if(visited[value] == time || visited[value] == -1) {
            if(value == k) {
                result_time = time;
            }
            visited[value] = time;
            ++result[value];
        }
        else {
            cout << "something wrong\n>> unexpected testcase\ni cannot understand why this happen. this is not make sense logically\n";
            exit(0);
        }
        //cout << time << " " << value << ": " << result[value] << ", " << visited[value] << "\n";

        if(2 * value <= 100000) {
            //cout << "test1\n";
            if(visited[value*2] == -1 || visited[value*2] == time+1 ) {
                pq.push({-time-1, 2*value});
            }
            //cout << "test2\n";
        }
        
        if(value+1 <= 100000) {
            if(visited[value+1] == -1 || visited[value+1] == time+1 ) {
                pq.push({-time-1, value+1});
            }
        }
        if(value-1 >= 0) {
            if(visited[value-1] == -1 || visited[value-1] == time+1) {
                pq.push({-time-1, value-1});
            }
        }


    }
    cout << visited[k] << "\n";
    cout << result[k] << "\n";
}
int main(int argc, char* argv[]) {
    fio; 

    ll n, k;
    cin >> n >> k;

    solution(n, k);

    return 0;
}
