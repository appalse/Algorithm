#include <vector>
#include <deque>
#include <cassert>
#include "graph.h"

using namespace std;

Graph::Graph(int vertex_count) :
	graph(vertex_count, vector<int>())
{}

void Graph::AddEdge(int from, int to)
{
	--from; --to;
	graph[from].push_back(to);
}


bool Graph::is_cyclic_(unsigned int vertex, vector<COLOR>& colors)
{
	assert(vertex < graph.size());
	if (COLOR::GREY == colors[vertex])
		return true;
	if (COLOR::BLACK == colors[vertex])
		return false;
	
	colors[vertex] = COLOR::GREY;

	for (int v : graph[vertex]) {
		if (is_cyclic_(v, colors))
			return true;
	}

	colors[vertex] = COLOR::BLACK;
	return false;
}

bool Graph::HasCircle()
{
	vector<COLOR> colors(graph.size(), COLOR::WHITE);
	for (unsigned int vertex = 0; vertex < graph.size(); ++vertex) {
		if (is_cyclic_(vertex, colors))
			return true;
	}
	return false;
}

void Graph::visit(int vertex, vector<COLOR>& colors, deque<int>& sorted)
{
	colors[vertex] = COLOR::GREY;

	for (auto v : graph[vertex]) {
		visit(v, colors, sorted);
	}

	colors[vertex] = COLOR::BLACK;
	
	++vertex;
	if (find(sorted.begin(), sorted.end(), vertex) == sorted.end())
		sorted.push_front(vertex);
}

deque<int> Graph::TopologicalSort()
{
	deque<int> sorted;

	vector<COLOR> colors(graph.size(), COLOR::WHITE);
	for (unsigned int vertex = 0; vertex < graph.size(); ++vertex) {
		if (COLOR::WHITE == colors[vertex])
			visit(vertex, colors, sorted);
	}

	return sorted;
}