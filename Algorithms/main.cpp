
//Simple: "cmake . && make && ./Algorithms"

//Problem komiwojażera
//Problem Chińskiego Listonosza
//Cykl Hamiltona
//Cykl Eulera
//Algorytm Dijkstry
//Kopiec as priority queue

#include <iostream>

struct Node 
{
	int val;
    //int cost;
    //int priority
	Node* next;
};

struct NumberNode
{
    int node;
    NumberNode* next;
};

class Stack
{
    NumberNode* top;

public :

    Stack()
    { 
        top = NULL;
    }

    ~Stack()
    {
        while (top != NULL)
        {
            NumberNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value)
    {
        NumberNode* temp = new NumberNode();
        temp->node = value;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        NumberNode* temp = top;
        top = top->next;
        return temp->node;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

class Queue
{
    NumberNode* top;

public :

    Queue()
    { 
        top = NULL;
    }

    ~Queue()
    {
        while (top != NULL)
        {
            NumberNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value)
    {
        NumberNode* node = new NumberNode();
        node->next = NULL;
        node->node = value;
        if (top == NULL)
        {
            top = node;
        }
        else
        {
            NumberNode* temp = top;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    int pop()
    {
        NumberNode* temp = top;
        top = top->next;
        return temp->node;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

class Graph
{
	Node* getAdjacentListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;
		newNode->next = head;
		return newNode;
	}

public:

    int N;

	Node **head;
    bool *visited;

    Graph(int N)
    {
		this->N = N;
        head = new Node*[N]();
        visited = new bool[N]();

		for (int i = 0; i < N; i++)
        {
			head[i] = NULL;
        }
        resetVisited();
    }

    void resetVisited()
    {
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int src, int dest)
    {
        head[src] = getAdjacentListNode(dest, head[src]);
        //head[dest] = getAdjacentListNode(src, head[dest]);
    }

	~Graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];
		delete[] head;
	}
};

// Depth First Search
void DFS (Graph& graph, const int begin)
{
    Stack stack;
    stack.push( begin );

    while (!stack.isEmpty())
    {
        int nodeNumber = stack.pop();
        if (graph.visited[nodeNumber]) continue;
        graph.visited[nodeNumber] = true;
        //std::cout << " >> " << nodeNumber;
        //do Something

        Node* node = graph.head[nodeNumber];
        while (node != NULL)
        {
            nodeNumber = node->val;
            if ( graph.visited[nodeNumber] == false )
            {
                stack.push( nodeNumber );
            }
            node = node->next;
        }
    }
    //std::cout << std::endl;
}

void BFS (Graph& graph, const int begin)
{
    Queue queue;
    queue.push( begin );

    while (!queue.isEmpty())
    {
        int nodeNumber = queue.pop();
        if (graph.visited[nodeNumber]) continue;
        graph.visited[nodeNumber] = true;
        //std::cout << " >> " << nodeNumber;
        //do Something
        
        Node* node = graph.head[nodeNumber];
        
        while (node != NULL)
        {
            nodeNumber = node->val;
            if ( graph.visited[nodeNumber] == false )
            {
                queue.push( nodeNumber );
            }
            node = node->next;
        }
        
    }
    //std::cout << std::endl;
}

// print all neighboring vertices of given vertex
void printList(Node* ptr)
{
	while (ptr != NULL)
	{
		std::cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "<BEGIN>" << std::endl;

	int N = 8;

	Graph graph(N);
    graph.addEdge(0,1);
    graph.addEdge(0,6);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(2,1);
    graph.addEdge(2,3);
    graph.addEdge(4,5);
    graph.addEdge(5,4);
    graph.addEdge(3,4);
    graph.addEdge(3,7);

    DFS(graph, 2);
    graph.resetVisited();
    BFS(graph, 2);
    graph.resetVisited();

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++)
	{
		// print given vertex
		std::cout << i << " --";

		// print all its neighboring vertices
		printList(graph.head[i]);
	}

    std::cout << "<END>" << std::endl;    
    return 0;
}