#include <iostream>
#include <deque>
#include <vector>
#include "graph.h"

using namespace std;

int main()
{
	int vertex_count, edges_count;
	cout << "Enter vertex count : ";
	cin >> vertex_count;
	cout << "Enter edges count : ";
	cin >> edges_count;

	Graph graph(vertex_count);

	cout << "Enter edges as " << edges_count << " pairs of vertex: from to" << endl;
	cout << "(vertex enumeration starts from 1)" << endl;
	for (int i = 0; i < edges_count; ++i) {
		int from, to;
		cin >> from >> to;
		graph.AddEdge(from, to);
	}

	if (graph.HasCircle()) {
		cout << "This graph has circle. Cannot call topological sort " << endl;
	} else {
		cout << "Topological sort:" << endl;
		for (auto v : graph.TopologicalSort())
			cout << v << " ";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}