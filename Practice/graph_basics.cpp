#include <bits/stdc++.h>

using namespace std;

void DFS (vector<vector<pair<int, int>>>& graph, int curr, vector<bool>& visited) {

	if (visited[curr])	return;

	visited[curr] = true;

	cout << curr << " ";

	for (pair<int, int> adj: graph[curr]) {

		DFS (graph, adj.first, visited);

	}

}

void BFS (vector<vector<pair<int, int>>>& graph, int curr, int curr_count, int& at_level, vector<bool>& visited, vector<bool>& marked) {

	if (visited[curr]) return;

	visited[curr] = true;

	if (--curr_count) {

		for (pair<int, int> adj: graph[curr]) {

			BFS (graph, adj.first, curr_count, at_level, visited, marked);

		}

	}

	else {

		if (marked[curr])	return;

		marked[curr] = true;
		at_level++;
		cout <<	curr << " "; 
		return;

	}

}

int main () {

	cout << "Enter the number of nodes: ";
	int n;
	cin >> n;

	vector <vector<pair<int, int>>> adj(n);

	int m;
	cout << "Enter the number of edges: ";
	cin >> m;

	int node1, node2, wt;

	cout << "Enter the edges in the form node1 node2 weight (0 indexed nodes)\n";

	for (int i = 0; i < m; i++) {

		cin >> node1 >> node2 >> wt;
		adj[node1].push_back ({node2, wt});
		adj[node2].push_back ({node1, wt});
	}

	cout << "\nDFS Recursive\n";

	vector<bool> visited(n);

	DFS (adj, 0, visited);

	fill (visited.begin(), visited.end(), false);

	cout << "\n\nDFS Iterative\n";

	stack<int> to_process;
	int curr;
	to_process.push (0);

	while (!to_process.empty()) {

		curr = to_process.top();
		to_process.pop();

		if (visited[curr]) continue;

		visited[curr] = true;

		cout << curr << " ";
		for (auto neigh: adj[curr]) {

			to_process.push (neigh.first);

		}

	}

	cout << "\n\nBFS Iterative\n";

	queue<int> to__process;
	fill (visited.begin(), visited.end(), false);

	to__process.push (0);

	while (!to__process.empty()) {

		curr = to__process.front();
		to__process.pop();

		if (visited[curr])	continue;

		visited[curr] = true;

		cout << curr << " ";

		for (auto neigh: adj[curr]) {

			to__process.push (neigh.first);

		}

	}

	cout << "\n\nBFS Recursive\n";
	int curr_level = 1;
	int at_level = 0;
	vector<bool> marked(n);

	do {

		at_level = 0;
		fill (visited.begin(), visited.end(), false);
		cout << "Level " << curr_level << ": ";
		BFS (adj, 0, curr_level, at_level, visited, marked);
		curr_level++;
		cout << "\n";

	} while (at_level);

	cout << "\n";

}