#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<int> A;

int main(int argc, char* argv[]) {
    fio;

    int N;

    cin >> N;

    A.push_back(0);

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        A.push_back(a);
    }

    bool changed = false;
    for (int i=1; i<=N+1; i++) {
        changed = false;
        for (int j=1; j<=N-i; j++) {
            if (A[j] > A[j+1]) {
                changed = true;
                swap(A[j], A[j+1]);
            }
        }
        if (changed == false) {
            cout << i << '\n';
            break;
        }
/*
        for(int j = 1; j <= N; j++) {
            cout << A[j] << " ";
        }
        cout << "\n";*/
    }

    return 0;
}
