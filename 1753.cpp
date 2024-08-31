#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

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