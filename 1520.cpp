#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int m, n;


int position[555][555];

int direction[4][2] = {
    {-1,0},
    {1, 0},
    {0,-1},
    {0, 1}
};

int values[555][555];

int dfs(pair<int, int> current_p, int accumulated_count) {
    //cout << current_p.first << ", " << current_p.second << ": " << accumulated_count << "\n";

    if(current_p.first == m && current_p.second == n) {
        
        return accumulated_count;
    }
    int current_value = position[current_p.first][current_p.second];
    if(values[current_p.first][current_p.second] != -1) {
        
        return values[current_p.first][current_p.second] * accumulated_count;
    }

    int dfs_result = 0;
    for(int i = 0; i < 4; i++) {
        int next_f = current_p.first + direction[i][0];
        int next_s = current_p.second + direction[i][1];

        int next_value = position[next_f][next_s];
        if(next_value == 0) {
            continue;
        }
        if(next_value < current_value) {
            dfs_result += dfs({next_f, next_s}, accumulated_count);
        }
    }

    values[current_p.first][current_p.second] = dfs_result;
    
    accumulated_count *= dfs_result;


    return accumulated_count;

}

int main(int argc, char* argv[]) {
    fio;

    cin >> m >> n;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            values[i][j] = -1;
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> position[i][j];
        }
    }

    

    cout << dfs({1, 1}, 1) << "\n";


    return 0;
}
