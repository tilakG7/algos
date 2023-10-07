#include <iostream>
#include <utility> // for std::pair
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

using edge = pair<int, int>;
using q_elem_t = pair<int, int>;
using graph_t = unordered_map<int, vector<edge>>;

struct Compare{
    bool operator()(const q_elem_t& a, const q_elem_t& b){
        return a.second < b.second;
    }
}; // Compare

using heap_t = priority_queue<q_elem_t, vector<q_elem_t>, Compare>; 

vector<int> djikstra(graph_t& g, int s, int f) {
    vector<int> ans{};
    if(!g.contains(s) || !g.contains(f)) {
        cout << "Invalid start/finish" << endl;
        return ans;
    }
    heap_t h{}; 
    set s{};

    h.push({s, 0});
    while(h.size() > 0) {
        q_elem_t node_pl = h.top(); h.pop();
        if(node_pl[0] == f) {
            cout << "I found the path legnth to reach finish: " << node_pl[1];
            return ans;
        }
        if (s.find(node_pl[0]) == s.end()) {
            for(auto iter = g[q_elem_t[0]].begin(); iter != g[q_elem_t[0]].end(); iter++) {
                h.push({iter->first, node_pl[1] + iter->second});
            }
        }
    }
    return ans;
}

int main() {
    graph_t graph{};
    // populate graph
}
