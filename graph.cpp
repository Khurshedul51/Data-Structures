#include <bits/stdc++.h>
using namespace std;

class Graph{
    int verticesNum;
    list<int>* adjacentList;
    bool* visited;

public:
    Graph(int vertices){
        verticesNum = vertices;
        adjacentList = new list<int>[vertices];
    }

    void addEdge(int src, int dest){
        adjacentList[src].push_back(dest);
        adjacentList[dest].push_back(src);
    }

    void BFS(int startVertex){
        visited = new bool[verticesNum];
        for(int i = 0; i < verticesNum; i++){
            visited[i] = false;
        }

        list<int> queue;
        
        queue.push_back(startVertex);
        visited[startVertex] = true;

        while(!queue.empty()){
            const int currentVertex = queue.front();
            cout << currentVertex << "-->";
            queue.pop_front();

            for(auto i = adjacentList[currentVertex].begin(); i != adjacentList[currentVertex].end(); i++){
                const int adjacentVertex = *i;
                if(!visited[adjacentVertex]){
                    visited[adjacentVertex] = true;
                    queue.push_back(adjacentVertex);
                }
            } 
        }
        cout << "\n";
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    return 0;
}