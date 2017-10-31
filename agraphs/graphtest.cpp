#include "graph.h"

int main() {
	int V = 6;

	cout << "Testing traversal and topo sort" << endl;
	{
		graph g(V);
		g.addEdge(5, 2);
		g.addEdge(5, 0);
		g.addEdge(4, 0);
		g.addEdge(4, 1);
		g.addEdge(2, 3);
		g.addEdge(3, 1);

		cout << "Depth First Search" << endl;
		g.DFS();
		cout << endl;

		cout << "Breadth First Search" << endl;
		g.BFS(1);

		cout << "Topological Sort" << endl;
		g.topoSort();
	}

	cout << endl << "------------------" << endl;
	cout << "Testing cycle" << endl;
	{
		graph g(4);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		if (g.isCyclic())
			cout << "Graph contains cycle";
		else
			cout << "Graph doesn't contain cycle";
		return 0;

	}
}