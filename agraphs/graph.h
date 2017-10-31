#ifndef GRAPH_H
#define GRAPH_H
#include "../util/util.h"
#include <queue>
#include <list>
#include <stack>


class graph {
	int v;
	list<int>* adj;
	void DFSUtil(int v, bool*&visited);
	void topoSortUtil(int v, bool*&visited, stack<int>& st);
	bool isCyclicUtil(int v, bool*&visited, bool*&rs);
public:
	graph(int V);
	void addEdge(int v, int w);
	void DFS();
	void BFS(int node);
	void topoSort();
	bool isCyclic();
};

#endif
