#include <iostream>
using namespace std;

void Hanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << fromRod << " den " << toRod << endl;
        return;
    }
    Hanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Di chuyen dia " << n << " tu " << fromRod << " den " << toRod << endl;
    Hanoi(n - 1, auxRod, toRod, fromRod);
}

int main () {
    cout << "Giai bai toan thap Ha Noi cho 3 dia:" << endl;
    Hanoi(3, 'A', 'C', 'B');
}