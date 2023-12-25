#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;

map<string, vector<string>> edges;
vector<string> vertices;
map<string, int> set_sizes;

void absorb_node(string absorbing, string new_parent)
{
	//prune any "self references"
	vector<string> adj_from_absorbed_node = edges[absorbing];
	for (int i = 0; i < adj_from_absorbed_node.size(); i++)
	{
		if (adj_from_absorbed_node[i] == new_parent)
		{
			adj_from_absorbed_node.erase(adj_from_absorbed_node.begin() + i);
			i--;
		}
	}

	//prune out references to the absorbed in the new parent adj list!
	for (int i = 0; i < edges[new_parent].size(); i++)
	{
		if (edges[new_parent][i] == absorbing)
		{
			edges[new_parent].erase(edges[new_parent].begin() + i);
			i--;
		}
	}

	//put the adj list from the absorbed node into the new parent's adj list
	for (string& s : adj_from_absorbed_node)
	{
		edges[new_parent].push_back(s);
	}

	edges.erase(absorbing);

	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		for (string& s : it->second)
		{
			if (s == absorbing)
			{
				s = new_parent;
			}
		}
	}

	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i] == absorbing)
		{
			vertices.erase(vertices.begin() + i);
			i--;
		}
	}

	set_sizes[new_parent]+= set_sizes[absorbing] + 1;
}

bool kargers()
{
	//karger's!
	const int initial_V = edges.size();
	int V = initial_V;
	while (V > 2)
	{
		//pick random edge: random node and a random edge on its adj list
		int n, i;
		n = rand() % vertices.size();
		i = rand() % edges[vertices[n]].size();

		if (vertices[n] == edges[vertices[n]][i]) continue; //same subset, dont bother

		absorb_node(edges[vertices[n]][i], vertices[n]);
		V--;
	}

	int cuts = 0;
	long long set_size_total = 1;
	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		if (it->second.size() > 0)
		{
			cout << "\tSet size: " << set_sizes[it->first] + 1 << endl;
			set_size_total *= set_sizes[it->first] + 1;
		}

		for (string& ed : it->second)
		{
			if (ed != it->first) cuts++;
		}
	}

	cout << "made " << cuts / 2 << " cuts!" << endl;
	cout << "Set size total : " << set_size_total << endl << endl;
	return (cuts / 2 == 3);
}

int main()
{
	string ln;
    ifstream f("input.in");
	string u, v;
	
	set<string> nodes_to_add;
	
	while (getline(f, ln))
	{
		stringstream ss(ln);

		ss >> u;
		u = u.substr(0, u.length() - 1);
		nodes_to_add.insert(u);
		while (ss >> v)
		{
			edges[u].push_back(v);
			edges[v].push_back(u);
			nodes_to_add.insert(v);
		}
	}

	vertices.resize(nodes_to_add.size());
	std::copy(nodes_to_add.begin(), nodes_to_add.end(), vertices.begin());
	nodes_to_add.clear(); //clean up

	map<string, vector<string>> edges_copy = edges;
	vector<string> vertices_copy = vertices;
	map<string, int> set_sizes_copy = set_sizes;

	while (!kargers())
	{
		srand(time(0));

		edges = edges_copy;
		vertices = vertices_copy;
		set_sizes = set_sizes_copy;
	}
    
    return 0;
}
