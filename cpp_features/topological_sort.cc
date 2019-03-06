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
void Graph::dfs(int v, bool visited[], stack<int> &stack) 
{ 
	// Mark the current node as visited. 
	visited[v] = true; 

	// Recur for all the vertices adjacent to this vertex 
	for (const auto &it = adj[v].begin(); it != adj[v].end(); ++it) 
		if (!visited[*it]) 
			dfs (*it, visited, stack); 

	// Push current vertex to stack which stores result 
	stack.push(v); 
} 

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
	stack<int> stack; 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to store Topological 
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			dfs(i, visited, stack); 

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

