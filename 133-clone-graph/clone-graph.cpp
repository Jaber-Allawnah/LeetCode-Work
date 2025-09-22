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
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map <Node*,Node*> myMap;
        queue<Node*> q;

        myMap[node]=new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* current=q.front();
            q.pop();
            for(int i=0;i<current->neighbors.size();i++){
                Node * nei= current->neighbors[i];
                if(!myMap.count(nei)){
                    myMap[nei]=new Node(nei->val);
                    q.push(nei);
                }
                myMap[current]->neighbors.push_back(myMap[nei]);
            }
        }
        return myMap[node];

    }
};