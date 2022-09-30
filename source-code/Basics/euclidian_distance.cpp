#include <iostream>
using namespace std;
#include <cmath>

double eucl_distance_from_origin(float x, float y){
    double distance = sqrt(pow(x,2) + pow(y,2));
    return distance;
}
int main(int argc, char *argv[]) {
    cout << eucl_distance_from_origin(3.0, 4.0) << endl;
}