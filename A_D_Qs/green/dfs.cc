#include <iostream> 
#include <vector>
#include <list> 

using namespace std; 
  
class Graph 
{ 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void DFS();    // prints DFS traversal of the complete graph 
private:
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    void DFSUtil(int v, vector<bool>& visited);  // A function used by DFS 
}; 
  
Graph::Graph(int v) 
{ 
    V = v; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].emplace_back(w); // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, vector<bool>& visited) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    for(auto it = adj[v].begin(); it != adj[v].end(); ++it) 
        if(visited[*it] == false) 
            DFSUtil(*it, visited); 
} 
  
// The function to do DFS traversal. It uses recursive DFSUtil() 
void Graph::DFS() 
{ 
    // Mark all the vertices as not visited 
	vector<bool> visited (V, false);
  
    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 
  
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal: "; 
    g.DFS(); 
  
    return 0; 
} 
