
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

// simple swap
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// permutation function it is 
void heapPermutation(int array[], int position, const int N) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (position == 1) 
    { 
        //leaf of tree
        for (int i = 0; i < N; ++i) 
            std::cout << array[i] << " ";
        std::cout << std::endl;
        return; 
    } 
  
    for (int i = 0; i < position; i++) 
    { 
        heapPermutation(array, position-1, N); 
  
        // if size is odd, swap first and last 
        // element 
        if (position % 2 == 1) 
            swap(array[0], array[position - 1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(array[i], array[position-1]); 
    } 
} 

// main func for heap permutation
void startHeapPermutation(int array[], const int N)
{
    heapPermutation(array, N, N);
}

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
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

    int arr[] = {1, 2, 3};
    startHeapPermutation(arr, 3); 

    std::cout << std::endl;

    int arrHeap[] = {12, 11, 13, 5, 6, 7}; 
    int NHeap = sizeof(arrHeap)/sizeof(arrHeap[0]); 
  
    heapSort(arrHeap, NHeap);

    for (int i = 0; i < NHeap; ++i) 
        std::cout << arrHeap[i] << " "; 
    std::cout << "\n"; 


    std::cout << "<END>" << std::endl;    
    return 0;
}