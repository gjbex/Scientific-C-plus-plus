#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1)
        cout << "hello " << argv[1] << " " << argv[2] << "!" << endl;
    else
        cout << "hello world!" << endl;

    int m {3}, n {5};
    m += n++; // post
    cout << m << " " << n << endl;
    int k {3}, l {5};
    k += ++l;  // pre
    cout << k << " " << l << endl;
    return 0;
    /*
    multilinecomment
    */
}
