#pragma once

#include "../../Priority Queue/src/PQADT.h"
#include "../../Queues/src/Queues.h"

/*****************************************************************************
	Graph: A data structure that consists of a set of nodes and a set of edges that relate the nodes to each other.
	Vertex: A node in the graph.
	Edge (Arc): A apir of vertices representing a connection between two ndoes in a graph.


	Structure: The graph conssits of a set of vertices and a set of weighted edges that connect some or all of the vertices.

	Assumption: Before any call is made to a graph operation, the graph has been delcared and a constructor has been applied.

******************************************************************************/

namespace graph {

	template<class VertexType>
	struct ItemType {
		bool operator<(ItemType otherItem);
		// < means greater distance;
		bool operator==(ItemType otherItem);
		bool operator<=(ItemType otherItem);
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	template<class VertexType>
	class GraphType {
		public:
			GraphType();		 // Default of 50 vertices.
			GraphType(int maxV); // maxV <= 50.
			~GraphType();	
			void MakeEmpty();

			bool IsEmpty() const;
			bool IsFull() const;

			void AddVertex(VertexType);
			void AddEdge(VertexType, VertexType, int);
			int WeightIs(VertexType, VertexType);
			void GetToVertices(VertexType, Queue<VertexType>&);
			void ClearMarks();
			void MarkVertex(VertexType);
			bool IsMarked(VertexType) const;
	
	private:
		int numVertices;
		int maxVertices;
		VertexType* vertices;
		int edges[50][50];
		bool* marks;	// marks[i] is mark for vertices[i].
	};

	template<class VertexType>
	void ShortestPath(GraphType<VertexType> graph, VertexType startVertext) {

	}

	/// <summary>
	/// Arrays of size 50 are dynamically allocated for marks and vertices. numVertices is set to 0; maxVertices is set to 50.
	/// </summary>
	/// <typeparam name="VertexType"></typeparam>
	/// <returns></returns>
	template<class VertexType>
	GraphType<VertexType>::GraphType() {
		numVertices = 0;
		maxVertices = 50;
		vertices = new VertexType[50];
		marks = new bool[50];
	}

	/// <summary>
	/// Arrays of sizse maxV are dynamically allocated for marks and vertices. numVertices is set to 0; maxVertices is set to maxV.
	/// </summary>
	/// <typeparam name="VertexType"></typeparam>
	/// <returns></returns>
	template<class VertexType>
	GraphType<VertexType>::GraphType(int maxV) {
		numVertices = 0;
		maxVertices = maxV;
		vertices = new VertexType[maxV];
		marks = new bool[maxV];
	}

	template<class VertexType>
	GraphType<VertexType>::~GraphType() {
		delete vertices[];
		delete marks[];
		
		vertices = nullptr;
		marks = nullptr;
	}

	const int NULL_EDGE = 0;

	template<class VertexType>
	void GraphType<VertexType>::AddVertex(VertexType vertex) {
		vertices[numVertices] = vertex;

		for (int index = 0; index < numVertices; ++index) {
			edges[numVertices][index] = NULL_EDGE;
			edges[index][numVertices] = NULL_EDGE;
		}

		++numVertices;
	}

	template<class VertexType>
	int IndexIs(VertexType* vertices, VertexType vertext) {
		int index(0);

		while (!(vertex == vertices[index]))
			index++;
		return index;
	}

	template<class VertexType>
	int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex) {
		int row(0);
		int col(0);

		row = IndexIs(vertices, toVertex);
		col = IndexIs(vertices, fromVertex);

		return edges[row][col];
	}

	template<class VertexType>
	void GraphType<VertexType>::GetToVertices(VertexType vertext, Queue<VertexType>& adjvertexQ) {
		int fromIndex;
		int toIndex;

		fromIndex = IndexIs(vertices, vertex);

		for (toIndex = 0; toIndex < numVertices; toIndex++) {
			if (edges[fromIndex][toIndex] != NULL_EDGE)
				adjvertexQ.Enqueue(vertices[toIndex]);
		}
	}

	// Make ClearMarks, MarkVertex and IsMarked, MakeEmpty, IsFull, IsEmpty

}