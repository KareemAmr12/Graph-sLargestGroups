#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    vector<char> verticies;
    map<char, bool> visited;
    vector<char> visit;
    vector<char> finished;
    map<char, vector<char>> adj;
    
    void addEdge(char v, char w);
    void DFS(char v);
    Graph Transpose();
};

void Graph::addEdge(char v, char w)
{
    bool check1 = true;
    bool check2 = true;
    for (int i = 0; i < verticies.size(); i++)
    {
        if (verticies[i] == v)
        {
            check1 = false;
        }
        if (verticies[i] == w)
        {
            check2 = false;
        }
    }
    if (check1)
    {
        verticies.push_back(v);
    }
    if (check2)
    {
        verticies.push_back(w);
    }
    
    adj[v].push_back(w); 
}

void Graph::DFS(char v)
{
    
    visited[v] = true;
    visit.push_back(v);
    cout << v << " ";
    vector<char>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
    finished.push_back(v);
}

Graph Graph::Transpose()
{
    Graph g;
    vector<char>::iterator i;
    for (i = verticies.begin(); i != verticies.end(); i++)
    {
        for (int j = 0; j < adj[*i].size(); j++)
        {
            g.addEdge(adj[*i][j],*i);
        }
    }
    return g;
}

void get_groups(Graph g)
{
    Graph t;
    vector<char> temp;
    cout << "Graph's DFS result: ";
    g.DFS(g.verticies[0]);
    
    char compare;
    while (g.visit.size() < g.verticies.size())
    {
        for (int i = 0; i < g.verticies.size(); i++)
        {
            for (int j = 0; j < g.visit.size(); j++)
            {
                if (g.verticies[i] != g.visit[j])
                {
                    compare = g.verticies[i];
                    if (g.visited[compare] == false)
                    {
                        g.DFS(compare);
                        break;
                    }
                }
            }
            
        }
    }
    
    
    for (int i = 0; i < g.finished.size(); i++)
    {
        temp.push_back(g.finished[i]); 
    }
    cout << endl;
   
     t = g.Transpose();
     cout << endl;
     cout << "Graph's largest groups: " << endl;
     cout << "Group no.1: { ";
     t.DFS(temp.back());
     cout << "}";
     cout << endl;
     int k = 2;
     while (!temp.empty())
     {
         for (int i = 0; i < t.visit.size(); i++)
         {
             char temp2 = t.visit[i];
             int size = temp.size();
             for (int j = 0; j < size; j++)
             {
                 if (temp2 == temp[j])
                 {
                     temp.erase(temp.begin() + j);

                     break;
                 }
             }
         }
         
             if (!temp.empty())
             {
                 cout << "Group no." << k << ": { ";
                 t.DFS(temp.back());
                 cout << "}";
                 k++;
                 cout << endl;
             }
         }
     
     if (!temp.empty())
     {
         t.DFS(temp.back());
     }
     
}

int main()
{
    cout << "First Graph\n\n";
    Graph test1;
    
    test1.addEdge('b', 'c');
    test1.addEdge('c', 'a');
    test1.addEdge('a', 'b');
    test1.addEdge('b', 'd');
    test1.addEdge('d', 'e');
    test1.addEdge('e', 'f');
    test1.addEdge('f', 'd');
    
    get_groups(test1);


    cout << "_____________________________________________" << endl << endl;

    cout << "Second Graph\n\n";
    Graph test2;
    test2.addEdge('b', 'c');
    test2.addEdge('c', 'a');
    test2.addEdge('a', 'b');
    test2.addEdge('b', 'd');
    test2.addEdge('d', 'e');
    test2.addEdge('e', 'f');
    test2.addEdge('f', 'd');
    test2.addEdge('g', 'f');
    test2.addEdge('g', 'h');
    test2.addEdge('h', 'i');
    test2.addEdge('i', 'j');
    test2.addEdge('j', 'k');
    test2.addEdge('j', 'g');

    
    get_groups(test2);
    cout << endl;
    
   
    
    system("pause");
    return 0;
}