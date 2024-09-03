#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

#define REST 998244353

struct Node {
    int value;

    struct Node* parent;
    struct Node* left_leaf;
    struct Node* right_leaf;

    Node(Node* p, int v) : parent(p), value(v){}
};

vector<int> forth_cycle;
vector<int> back_cycle;
bool visited[505050];

int back_cycle_index = 0;

vector<Node*> node_list;

Node* makeNewNode(Node* parent, int value) {
    Node* new_node = new Node(parent, value);
    new_node->left_leaf = NULL;
    new_node->right_leaf = NULL;
    node_list.push_back(new_node);
    return new_node;
}

int main() {
    fio;    

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        forth_cycle.push_back(input);
    }
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        back_cycle.push_back(input);
    }

    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    if(forth_cycle[0] != back_cycle[n-1]) {
        cout << "0\n";
        return 0;
    }

    Node* root = makeNewNode(NULL, forth_cycle[0]);
    Node* node = root;
    visited[forth_cycle[0]] = true;

    ll result = 1;
    bool force_break_trigger = false;

    for(int i = 1; i < n; i++) {
        int current_value = forth_cycle[i];
        
        visited[current_value] = true;
        
        //좌우에 노드 할당
        if(node->left_leaf == NULL) {
            node->left_leaf = makeNewNode(node, current_value);
            node = node->left_leaf;    
        }
        else if(node->right_leaf == NULL) {
            node->right_leaf = makeNewNode(node, current_value);
            node = node->right_leaf;
        }
        else { //양쪽 노드 다 차있는데 부모노드 못올라갔을 때
            cout << "0\n";
            return 0;
        }

        // 부모 올라가기
        for(int j = back_cycle_index; j < n; j++) {
            if(visited[back_cycle[back_cycle_index]] && node->value == back_cycle[back_cycle_index]) {
                
                ++back_cycle_index;
                if(node->left_leaf != NULL && node->right_leaf == NULL) {
                    result = (result * 2) % REST;
                }
                
                node = node->parent;
            }
            else if(visited[back_cycle[back_cycle_index]]) {
                cout << "0\n";
                return 0;
            }
            else {
                break;
            }
        }
        
        
    }

    //cout << "=================================\n";
/*
    if(root->left_leaf != NULL && root->right_leaf == NULL) {
        result = (result * 2) % REST;
    }
*/
    
    if(node != NULL) {
        cout << "0\n";
    }
    else {
        cout << result << "\n";
    }
    

    for(int i = 0; i < node_list.size(); i++) {
        delete node_list[i];
    }


    return 0;
}
