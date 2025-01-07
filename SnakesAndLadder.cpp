#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

// Template class for the graph
template <typename T>
class graph
{
    // An unordered map to store the graph (adjacency list)
    unordered_map<T, list<T>> h;

public:
    // Function to add an edge between two nodes
    void addedge(T u, T v, bool bird = false)
    {
        h[u].push_back(v); // Add an edge from u to v
        if (bird == true)
        {
            h[v].push_back(u); // If the edge is bi-directional, add the reverse edge
        }
    }

    // Function to print the graph
    void printgraph()
    {
        for (auto x : h)
        {
            cout << x.first << " --> "; // Print the node
            for (auto p : x.second)
            {
                cout << p << " "; // Print all adjacent nodes of the node
            }
            cout << endl;
        }
    }

    // Function to find the shortest path from src to dest using BFS
    int snakeandladder(T src, T dest)
    {
        unordered_map<T, T> parent; // To store the parent node for path reconstruction
        parent[src] = src;          // Source node's parent is itself

        unordered_map<T, int> distance; // To store the distance from src to each node
        distance[src] = 0;              // Distance to the source node is 0

        queue<T> q;                     // Queue for BFS
        q.push(src);                    // Start from the source
        unordered_map<T, bool> visited; // To keep track of visited nodes
        visited[src] = true;            // Mark the source node as visited

        // Perform BFS
        while (!q.empty())
        {
            T x = q.front(); // Get the front node
            q.pop();

            // Explore all adjacent nodes of x
            for (auto p : h[x])
            {
                if (!visited[p])
                {                                  // If node p is not visited
                    q.push(p);                     // Add node p to the queue
                    visited[p] = true;             // Mark node p as visited
                    distance[p] = distance[x] + 1; // Distance to p is one more than the distance to x
                    parent[p] = x;                 // Set the parent of p to be x
                }
            }
        }

        // Reconstruct the path from dest to src
        T temp = dest;
        while (temp != src)
        {
            cout << temp << "<--"; // Print the path
            temp = parent[temp];   // Move to the parent of temp
        }
        cout << src << endl; // Finally print the source

        return distance[dest]; // Return the distance from src to dest
    }
};

int main()
{
    graph<int> g; // Create a graph of integers

    // Define a board array to represent the snake and ladder positions
    int board[50] = {0};
    board[2] = 13;   // Ladder at 2
    board[5] = 2;    // Ladder at 5
    board[9] = 18;   // Ladder at 9
    board[18] = 11;  // Ladder at 18
    board[17] = -13; // Snake at 17
    board[20] = -14; // Snake at 20
    board[24] = -8;  // Snake at 24
    board[25] = -10; // Snake at 25
    board[32] = -2;  // Snake at 32
    board[34] = -22; // Snake at 34

    // Create edges in the graph based on dice rolls and board positions
    for (int src = 0; src <= 35; src++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int dest = src + dice + board[src + dice]; // Calculate the destination after a dice roll and board adjustment
            g.addedge(src, dest);                      // Add the edge from src to dest
        }
    }

    // Find and print the shortest path from 0 to 36 (snake and ladder game)
    cout << g.snakeandladder(0, 36) << endl;

    // Game starts with both persons at position 0
    cout << "person1 is at 0 " << endl;
    cout << "person2 is at 0 " << endl;
    int srcp1 = 0; // Starting position for person 1
    int srcp2 = 0; // Starting position for person 2

    cout << "start the game" << endl;

    // Simulate the game where two persons take turns rolling the dice
    while (true)
    {
        cout << "take value of dice for person 1" << endl;
        int d1;
        cin >> d1; // Input for person 1's dice roll
        // Update person 1's position based on the dice roll and the board
        cout << "person 1 is at pos " << srcp1 + d1 + board[srcp1 + d1] << endl;
        srcp1 = srcp1 + d1 + board[srcp1 + d1]; // Update position
        if (srcp1 == 36)
        {
            cout << "yeyy person 1 won the game " << endl;
            break; // Person 1 wins
        }

        cout << "take value of dice for person 2" << endl;
        int d2;
        cin >> d2; // Input for person 2's dice roll
        // Update person 2's position based on the dice roll and the board
        cout << "person 2 is at pos " << srcp2 + d2 + board[srcp2 + d2] << endl;
        srcp2 = srcp2 + d2 + board[srcp2 + d2]; // Update position
        if (srcp2 == 36)
        {
            cout << "yay person 2 won the game " << endl;
            break; // Person 2 wins
        }
    }

    return 0;
}
