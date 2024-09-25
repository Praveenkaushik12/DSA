#include<iostream>
using namespace std;

void TowerofHanoi(int n, char source, char helper, char dest) {
    if (n == 0) {
        return;
    }
    TowerofHanoi(n - 1, source, dest, helper);
    cout << source << " -> " << dest << endl;
    TowerofHanoi(n - 1, helper, source, dest);
}

int main() {
    TowerofHanoi(3, 'A', 'B', 'C');
    return 0;
}
