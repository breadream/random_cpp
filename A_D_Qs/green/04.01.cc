#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph 
{
public:
	Graph(int V); // Constructor
	void addEdge (int v, int w); // to add an edge to graph
	bool isReachable(int s, int d); // check whether if there's route between two nodes
private:
	int V; // number of vertices 
	list <int> *adj; // pointer to an array containing adjacency lists
};

Graph::Graph(int v) 
{
	V = v;
	adj = new list<int> [V]; // each vertex has an individual adj list 
}

void Graph::addEdge(int v, int w)
{
	adj[v].emplace_back(w); // add w to v's list 
}

// BFS function to check whether d(destination) is reachable from s(source)
bool Graph::isReachable(int s, int d)
{
	if (s == d) return true;

	vector<bool> visited (V, false);
	// Create a queue for BFS
	list <int> queue;

	// Mark the current node as visited and enqueue it 
 	visited[s] = true;
	queue.emplace_back(s);

	// get all adjacency list of dequeued vertex s
	// if an adjacent node hasn't been visited, mark it visited and 
	// enqueue it to visit its adjacent nodes 
	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();

		// 'it' evaluates to iterator to list of int elements
		for (auto it = adj[s].begin(); it != adj[s].end(); it++)
		{
			if (*it == d) // found destination
				return true;
			if (!visited[*it])
			{
				visited[*it] = true;
				queue.emplace_back(*it);
			}
		}
	}
	// BFS is doen w/o visiting d
	return false;

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

    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;

    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;

    return 0;
}
