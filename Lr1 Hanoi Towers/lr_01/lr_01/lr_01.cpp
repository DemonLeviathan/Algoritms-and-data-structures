#include <iostream>
using namespace std;

void hanoi(int i, int k, int n)
{
    if (n == 1) {
        cout << "Move disk 1 from pin " << i << " to pin " << k << ".\n";
    }
    else {
        int tmp = 6 - i - k; 			
        hanoi(i, tmp, n - 1);
        cout << "Move disk " << n << " from pin " << i << " to pin " << k << ".\n";
        hanoi(tmp, k, n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    cout << endl;
    hanoi(1, 2, n);
    return 0;
}
