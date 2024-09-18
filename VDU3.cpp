#include <iostream>
using namespace std;

int knapsack(int W, int weight[], int value[], int n) {
    int dt[W + 1] = {0};  
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dt[w] = max(dt[w], dt[w - weight[i]] + value[i]);
        }
    }
    return dt[W];
}

int main() {
    int n, W;
    cin >> n >> W;
    int value[n], weight[n];
    
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << knapsack(W, weight, value, n) << endl;
    return 0;
}
// knapsack : bài toán cái túi
// dt[] : là bảng động ( trong quy hoạch động)
// weight[] : là mảng lưu trọng lượng của các đối tượng
// value[] : là mảng lưu gia trị của các đối tượng 
// n là số lượng đối tượng
// W là trọng lượng của tối tượng