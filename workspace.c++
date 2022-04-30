#include <vector>
#include <queue>
using namespace std;


int main() {

}

bool canFinish(int n, vector<pair<int, int>>& pre) {
    // Create adj list and count the degree
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);

    // Build up adj list
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }

    // Create empty queue
    queue<int> q;

    // Scan the degree, push thoes who have no prequestic
    // If the edge does have a degree
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    
    // While queue is not empty
    while (!q.empty()) {
        // Get an element from queue
        // Decrease a element of n
        int curr = q.front(); q.pop(); n--;

        // Scan the course that require this course
        for (auto next: adj[curr])
            // If this edge only require this one course
            // Push the edge
            if (--degree[next] == 0) q.push(next);
    }
    // If all courses eventually get out of queue
    // Suppose there is cycle in graph, if they are not connected to other part of graph, then none of them get added to the queue
    // Suppose they are connected to the graph, consider there must have a edge that either have two inner edge. 
    // Means at first --  if (--degree[next] == 0) q.push(next); not equal to 0, so not get pushed to the graph
    return n == 0;
}
