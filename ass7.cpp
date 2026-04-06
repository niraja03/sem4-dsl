#include<iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class prims {
    int graph[ROW][COL], nodes;

public:
    void createGraph();
    void displayGraph();   // NEW FUNCTION
    void primsAlgo();
};

void prims::createGraph() {
    int i, j;

    cout << "Enter Total Warehouses: ";
    cin >> nodes;

    cout << "\nEnter Adjacency Matrix: \n";

    for (i = 0; i < nodes; i++) {
        for (j = i; j < nodes; j++) {
            cout << "Enter distance between " << i << " and " << j << endl;
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            if (graph[i][j] == 0)
                graph[i][j] = infi;
        }
    }
}

// ---------- DISPLAY GRAPH ----------
void prims::displayGraph() {
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] == infi)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nGraph Representation:\n";

    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] != infi && i != j) {
                cout << j << "(" << graph[i][j] << ") ";
            }
        }
        cout << endl;
    }
}

// ---------- PRIM’S ALGORITHM ----------
void prims::primsAlgo() {
    int selected[ROW], i, j, ne = 0;
    int min = 0, x, y;
    int cost = 0;

    for (i = 0; i < nodes; i++)
        selected[i] = 0;

    selected[0] = 1;

    while (ne < nodes - 1) {
        min = infi;

        for (i = 0; i < nodes; i++) {
            if (selected[i] == 1) {
                for (j = 0; j < nodes; j++) {
                    if (selected[j] == 0) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        selected[y] = 1;

        cout << "\n" << x << " --> " << y;

        cost += graph[x][y];
        ne++;
    }

    cout << "\nTotal cost is: " << cost << endl;
}

// ---------- MAIN ----------
int main() {
    prims MST;

    cout << "\nPrims Algorithm to connect several Warehouses\n";

    MST.createGraph();

    MST.displayGraph();   // 🔥 NEW LINE

    cout << "\nThe Edges are:\n";
    MST.primsAlgo();
}