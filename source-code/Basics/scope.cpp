#include <iostream>

using namespace std;

int main() {
    int i {3};
    cout << "out of block: " << i << endl;
    {
        cout << "in block before declaration: " << i << endl;
        int i {5};
        cout << "in block after declaration: " << i <<  endl;
    }
    cout << "out of block before for: " << i << endl;
    for (int i = 10; i < 13; i++)
        cout << "in for: " << i << endl;
    cout << "out of block after for: " << i << endl;
    return 0;
}
