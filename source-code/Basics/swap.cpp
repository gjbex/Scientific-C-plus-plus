#include <iostream>


void swap(double& x, double& y) {
    double tmp {x};
    x = y;
    y = tmp;
}

void swap(int& x, int& y) {
    int tmp {x};
    x = y;
    y = tmp;
}

int main() {
    double x {3.5};
    double y {5.7};
    std::cout << x << " <-> " << y << std::endl;
    swap(x, y);
    std::cout << "swqpped: " <<  x << " <-> " << y << std::endl;
    int a {3};
    int b {5};
    std::cout << a << " <-> " << b << std::endl;
    swap(a, b);
    std::cout << "swqpped: " <<  a << " <-> " << b << std::endl;
    return 0;
}
