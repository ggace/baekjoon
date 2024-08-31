#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}
/*
struct Node {
    int id;
    int value;

    Node(int i, int v): id(i), value(v) {}

    bool operator<(const Node c) const {
        return this->id < c.id;
    }
};

vector<vector<pair<int, int>>> graph(20001);
vector<int> from_path_count(20001);
vector<ll> minimum_path(20001);
bool visited[20001];

priority_queue<Node> pq;
*/
/*
int maximum_id = 0;
int minimum_id = 0;
*/
/*
void bfs() {
    
    queue<int> not_yet_visited;
    pq.push(Node(minimum_id, K));
    --minimum_id;
    
    minimum_path[K] = 0;

    while(!pq.empty()) {
        Node current_node = pq.top();
        pq.pop();
        //cout << current_node.value << "\n";
        if(visited[current_node.value]) {
            continue;
        }
        int minimum_possible_from_path_value = -1;
        int minimum_possible_from_path_count = -1;
        int push_count = 0;

        for(pair<int, int> next_node : graph[current_node.value]) {
            //cout << "\t" << next_node.first << "\n";
            if(from_path_count[next_node.first] == 0 || visited[next_node.first]) {
                visited[next_node.first] = true;
                continue;
            }
            if(minimum_possible_from_path_count == -1 || from_path_count[next_node.first] < minimum_possible_from_path_count) {
                minimum_possible_from_path_value = next_node.first;
                minimum_possible_from_path_count = from_path_count[next_node.first];
            }
            if(minimum_path[next_node.first] == -1 || minimum_path[next_node.first] > minimum_path[current_node.value] + next_node.second) {
                minimum_path[next_node.first] = minimum_path[current_node.value] + next_node.second;
            }
            
            from_path_count[next_node.first] --;
            if(from_path_count[next_node.first] <  1) {
                
                pq.push(Node(minimum_id--, next_node.first));
                push_count++;
                continue;
            }
            else {
                not_yet_visited.push(next_node.first);
            }
            
        }
        if(push_count == 0 && pq.empty() && minimum_possible_from_path_count != -1) {
            pq.push(Node(minimum_id--, minimum_possible_from_path_value));
        }
        if(pq.empty() && !not_yet_visited.empty()) {
            while(!not_yet_visited.empty()) {
                if(visited[not_yet_visited.front()]) {
                    not_yet_visited.pop();
                }
                else {
                    break;
                }
                
            }
            if(!not_yet_visited.empty()){
                pq.push(Node(minimum_id--, not_yet_visited.front()));
                not_yet_visited.pop();
            }
        }
    }
}

int main(int argc, char* argv[]) {
    //fio;

    cin >> V >> E >> K;

    fill_n(minimum_path.begin(), minimum_path.size(), -1);

    for(int i = 0; i < E; i++) {
        int v, u, w;

        cin >> v >> u >> w;

        graph[v].push_back({u, w});
        from_path_count[u]++;
    }

    bfs();
    //cout << "\n";
    //cout << "\n==========================\n";
    for(int i = 1; i <= V; i++) {
        if(minimum_path[i] == -1) {
            cout << "INF\n";
        }
        else{
            cout << minimum_path[i] << "\n";
        }
    }

    





    return 0;
}
*/

int V, E, K;

struct Node {
    int weight;
    int value;
    Node(int w, int v) : weight(w), value(v) {}

    bool operator<(const Node &a) const {
        if(a.weight == this->weight) {
            return a.value < this->value;
        }
        return a.weight < this->weight;
    }

};

vector<vector<pair<int, int>>> graph(20001);
priority_queue<Node> pq;
vector<int> minimum_weight(20001);
bool visited[20001];

void dijkstra() {
    pq.push(Node(0, K));

    while(!pq.empty()) {
        Node current_node = pq.top();
        pq.pop();
        if(visited[current_node.value]) {
            continue;
        }
        visited[current_node.value] = true;
        minimum_weight[current_node.value] = current_node.weight;

        //cout << current_node.value << " ";

        for(auto [u, w] : graph[current_node.value]) {
            if(!visited[u]) {
                pq.push(Node(current_node.weight + w, u));
            }
        }
    }
}

int main(int argc, char* argv[]) {
    //fio;

    cin >> V >> E >> K;
    fill_n(minimum_weight.begin(), minimum_weight.size(), -1);

    for(int i = 0; i < E; i++) {
        int v, u, w;

        cin >> v >> u >> w;

        graph[v].push_back({u, w});
    }

    dijkstra();
    //cout << "\n";
    for(int i = 1; i <= V; i++) {
        if(minimum_weight[i] == -1) {
            cout << "INF\n";
        }
        else{
            cout << minimum_weight[i] << "\n";
        }
    }




    return 0;
}