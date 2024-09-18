#include <iostream>
using namespace std;

#define MAX 10  

bool KiemtratontaidinhV(int v, int graph[MAX][MAX], int path[], int pos, int V) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool GiaichutrinhHamilton(int graph[MAX][MAX], int path[], int pos, int V) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (KiemtratontaidinhV(v, graph, path, pos, V)) {
            path[pos] = v;
            if (GiaichutrinhHamilton(graph, path, pos + 1, V))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

bool ChutrinhHamilton(int graph[MAX][MAX], int V) {
    int path[MAX];
    for (int i = 0; i < V; i++)
        path[i] = -1; 

    path[0] = 0; 
    
    if (!GiaichutrinhHamilton(graph, path, 1, V)) {
        cout << "Khong ton tai chu trinh Hamilton\n";
        return false;
    }

    cout << "Chu trinh Hamilton ton tai: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl; 

    return true;
}

int main() {
    int V; 
    int graph[MAX][MAX];
    cin >> V;
    cout << "Nhap ma tran ke cua do thi (1 neu co canh, 0 neu khong co canh):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    ChutrinhHamilton(graph, V);
    return 0;
}
