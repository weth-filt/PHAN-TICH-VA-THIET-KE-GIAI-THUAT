#include <iostream>

using namespace std;

void Tohop(int a[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            cout << data[j] << " ";
        }ưư
        cout << endl;
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = a[i];
        Tohop(a, data, i + 1, end, index + 1, r);
    }
}

void TohopchapR(int n, int r) {
    int a[n];  
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;  
    }
    
    int data[r];  
    Tohop(a, data, 0, n - 1, 0, r);
}

int main() {
    int n, r;
    cin >> n >> r; 

    if (r > n || r < 0) {
        cout << "Giá trị không hợp lệ! r phải nhỏ hơn hoặc bằng n và lớn hơn hoặc bằng 0." << endl;
        return 1;
    }

    cout << "Cac to hop chap " << r << " cua " << n << " phan tu la:" << endl;
    TohopchapR(n, r);
    return 0;
}   
