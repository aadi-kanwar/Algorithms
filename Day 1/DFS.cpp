#include<iostream>
#include<list>
#include<map>
using namespace std;
class GraphStructure
{
	map<int, bool> visitedNodes;
	map<int, list<int>> adjacencyList;
	public:
		void addEdge(int node1, int node2);
		void DFS(int startNode);
};

void GraphStructure :: addEdge(int node1, int node2)
{
	adjacencyList[node1].push_back(node2);
}
void GraphStructure :: DFS(int startNode)
{
	visitedNodes[startNode] = true;
	cout<<startNode<<" ";
	for( auto nextNode : adjacencyList[startNode])
	{
		if( !visitedNodes [nextNode])
			DFS(nextNode);
	}
}
int main()
{
	GraphStructure graph;
	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(1,4);
	graph.addEdge(4,3);
	graph.addEdge(3,5);
	cout<<"Depth First Traversal of 1st Graph: ";
	graph.DFS(1);
	
	GraphStructure graph1;
	graph1.addEdge(3,7);
	graph1.addEdge(3,4);
	graph1.addEdge(4,8);
	cout<<endl<<"Depth First Traversal of 2nd Graph: ";
	graph1.DFS(3);
	
	GraphStructure graph2;
	graph2.addEdge(9,5);
	graph2.addEdge(5,4);
	graph2.addEdge(5,3);
	cout<<endl<<"Depth First Traversal of 3rd Graph: ";
	graph2.DFS(9);
	return 0;
}
