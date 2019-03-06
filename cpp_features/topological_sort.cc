// A C++ program to print topological sorting of a DAG 
#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
	int V; // No. of vertices' 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

	// A function used by topologicalSort 
	void dfs (int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints a Topological Sort of the complete graph 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// A recursive function used by topologicalSort 
void Graph::dfs(int node, bool visited[], stack<int> &stack) 
{ 
	// Mark the current node as visited. 
	visited[node] = true; 

	// Recur for all the vertices adjacent to current vertex 
	for (auto it = adj[node].begin(); it != adj[node].end(); ++it) 
		if (visited[*it] == false) 
			dfs (*it, visited, stack); 

	// store the finished node onto stack
	stack.push(node); 
} 

void Graph::topologicalSort() 
{ 
	stack<int> stack; // store the reverse order that each DFS is done 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int node = 0; node < V; node++) 
		visited[node] = false; 

	// recursively call DFS for unvisited node 
	for (int node = 0; node < V; node++) 
		if (visited[node] == false) 
			dfs(node, visited, stack); 

	// Print contents of stack 
	while (stack.empty() == false) 
	{ 
		cout << stack.top() << " "; 
		stack.pop(); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 

	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 

