#include <iostream>
#include <Polynomial.hpp>


using namespace std;


int main() {

    Polynomial p1;
    p1.add(1.0, 1, 2, 3);
    p1.add(1.0, 2, 2, 3);
    p1.add(1.0, 3, 2, 3);

    Polynomial p2;
    p2.add(1.0, 1, 2, 3);
    p2.add(1.0, 2, 2, 3);
    p2.add(1.0, 3, 2, 3);

    cout << p1;
    cout << p2;

    Polynomial p3;
    try{
        p3 = p2 + p1;
        cout << p3;
    }
    catch (...) {
        cout << "ватафак мазафака";
    }
}