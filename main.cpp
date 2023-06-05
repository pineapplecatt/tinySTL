#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Vector.h"

using namespace std;

int main() {
    Vector<int> val{1,2,3,4};
    cout << val[2];
}