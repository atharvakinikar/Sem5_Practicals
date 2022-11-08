#include <bits/stdc++.h>
using namespace std;

// represents starting vertex, ending vertex,weight of edge between two vertex
struct node
{
    int u;  // first vertex
    int v;  // second vertex
    int wt; // weight of vertex

    // constructor to initiaise the the graph
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

class graph
{
public:
    vector<node> edges;                                  // vector to store all edges
    void insert_edge(int first, int second, int weight); // member function to insert edge
    void bellman_ford(int N);
    void show_graph(); // member function to call bellman forf algorithm on graph
};

// defining insert_edge function
void graph::insert_edge(int first, int second, int weight)
{
    edges.push_back(node(first, second, weight));
}

// defining bellman_ford function of graph
void graph::bellman_ford(int N)
{
    int src = 0;
    int inf = 10000000;

    // vector to store all the distances
    vector<int> dist(N, inf);

    // making distance of starting vertex as 0
    dist[src] = 0;

    // performing maximum of N-1 iterations through the graph
    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            // relaxing the edge
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // checking for negative cycle
    int fl = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << -1;
            fl = 1;
            break;
        }
    }

    // printing minimum distance from source
    if (!fl)
    {
        cout << "Vertex\t"
             << "|Minimum Dist From source\n";
        cout << "----------------------------" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << i << "\t|" << dist[i] << endl;
        }
    }
}

void graph::show_graph()
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\nThe graph is => " << endl;
    for (auto it : edges)
    {
        cout << it.u << " --> " << it.v << endl;
    }
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

int main()
{

    int N, M;
    cout << "\nEnter Number of Nodes :";
    cin >> N;
    cout << "\nEnter Number of Edges :";
    cin >> M;
    cout << endl;

    // creating object of class graph
    graph gp;

    // gp.insert_edge(0, 1, 5);
    // gp.insert_edge(1, 2, -2);
    // gp.insert_edge(1, 5, -3);
    // gp.insert_edge(2, 4, 3);
    // gp.insert_edge(3, 2, 6);
    // gp.insert_edge(3, 4, -2);
    // gp.insert_edge(5, 3, 1);

    int vertex1, vertex2, dist;
    for (int i = 0; i < M; i++)
    {
        cout << "\nEnter First Vertex => ";
        cin >> vertex1;
        cout << "\nEnter Second Vertex => ";
        cin >> vertex2;
        cout << "\nEnter Weight of edge => ";
        cin >> dist;
        cout << "\nEdge : " << vertex1 << " --> " << vertex2;
        gp.insert_edge(vertex1, vertex2, dist);
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    gp.show_graph();

    // calling bellman ford algorithm on the graph
    gp.bellman_ford(N);

    return 0;
}