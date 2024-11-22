/*#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;

#define MAX(x, y) ((x) > (y) ? (x):(y))
#define MIN(x, y) ((x) > (y) ? (y):(x))

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int cur = 1;
int heap[101010];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    heap[cur] = x;

    int index = cur++;
    while (index)
    {
        int parent= index/2;
        if(parent == 0) {
            break;
        }
        if(heap[index] > heap[parent]) {
            swap(heap+index, heap+parent);
        }
        index /= 2;
    }
    
}

void pop() {
    heap[1] = 0;
    swap(heap+1, heap+cur);
    
    int index = 1;

    while(index < cur) {
        int left_leaf = index * 2;
        int right_leaf = index * 2 + 1;
        if(left_leaf >= cur && right_leaf >= cur) {
            break;
        }

        if(heap[left_leaf] > heap[right_leaf]) {
            if(heap[index] < heap[left_leaf]){
                swap(heap + index, heap + left_leaf);
            }
            index = left_leaf;    
            
        }
        else {
            if(heap[index] < heap[right_leaf]) {
                
                swap(heap + right_leaf, heap + index);
                
            }
            index = right_leaf;            
        }
    }
    cur--;
}

void print() {
    for(int i = 1; i < cur; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int a;
        scanf("%d", &a);

        if (a == 0)
        {
            if(cur == 1) {
                printf("0\n");
                
                continue;
            }
            printf("%d\n", heap[1]);
            pop();
        }
        else {
            push(a);
        }

        
        
    }
    
    return 0;
}
*/

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

priority_queue<int> pq;

int main(int argc, char* argv[]) {
    fio; 

    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;

        if(a == 0) {
            if(pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(a);
        }
    }

    return 0;
}
