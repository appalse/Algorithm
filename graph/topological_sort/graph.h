#pragma once

class Graph
{
public:
	Graph(int vertex_count);

	void AddEdge(int from, int to);

	bool HasCircle();

	std::deque<int> TopologicalSort();

private:
	std::vector<std::vector<int>> graph;

	enum class COLOR { WHITE, GREY, BLACK };

	bool is_cyclic_(unsigned int vertex, std::vector<COLOR>& colors);
	void visit(int vertex, std::vector<COLOR>& colors, std::deque<int>& sorted);
};