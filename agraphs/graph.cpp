#include "graph.h"
graph::graph(int vertices) :v(vertices) {
	adj = new list<int>[v];
}

void graph::addEdge(int src, int dest) {
	adj[src].push_back(dest);
	//adj[dest].push_back(src);
}

void graph::DFS() {
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			DFSUtil(i, visited);
		}
	}
}

void graph::DFSUtil(int node, bool* &visited) {
	visited[node] = true;
	cout << node << " ";

	list <int>::iterator it;
	for (it = adj[node].begin(); it != adj[node].end(); it++) {
		if (!visited[*it]) {
			DFSUtil(*it, visited);
		}
	}
}

void graph::BFS(int node) {
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	list<int> queue;
	queue.push_back(node);
	visited[node] = true;

	list<int>::iterator it;
	while (!queue.empty()) {
		node = queue.front();
		cout << node << endl;
		queue.pop_front();

		for (it = adj[node].begin(); it != adj[node].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}

void graph::topoSort() {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;

	stack<int> st;

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			topoSortUtil(i, visited, st);
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

void graph::topoSortUtil(int vertex, bool* &visited, stack<int>& st) {
	
	//Mark current node as visited
	visited[vertex] = true;
	
	list<int>::iterator it;

	//Recur for all vertices adjacent
	for (it = adj[vertex].begin(); it != adj[vertex].end(); it++) {
		if (!visited[*it]) {
			topoSortUtil(*it, visited, st);
		}
	}

	//Push current vertex to stack
	st.push(vertex);
}

bool graph::isCyclic() {
	bool *visited = new bool[v];
	bool *rs = new bool[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		rs[i] = false;
	}

	//Call the helper function to detect cycles
	for (int i = 0; i < v; i++) {
		if (isCyclicUtil(i, visited, rs))
			return true;
	}
	
	return false;
}

bool graph::isCyclicUtil(int vertex, bool*& visited, bool*& rs) {
	if (!visited[vertex]) {

		//Mark teh current node as visited and as a part of the recursion stack
		visited[vertex] = true;
		rs[vertex] = true;

		list<int>::iterator it;
		for (it = adj[vertex].begin(); it != adj[vertex].end(); it++) {
			//If not visited yet, explore that node and check if any of it's adjacents are cyclic
			if (!visited[*it] && isCyclicUtil(*it, visited, rs))
				return true;
			//If that node is already a part of the rec stack
			else if (rs[*it])
				return true;
		}
	}

	//Once done, remove the vertex from rec stack
	rs[vertex] = false;
	return false;
}
