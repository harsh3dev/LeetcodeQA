/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> view;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        // check if the node is visited or not

        if (view.find(node) == view.end()) {
            view[node] = new Node(node->val, {});

            // iterate on the neighbours
            for (auto adj : node->neighbors) {
                view[node]->neighbors.push_back(cloneGraph(adj));
            }
        }

        return view[node];
    }
};