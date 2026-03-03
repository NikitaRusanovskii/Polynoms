#include <Polynomial.hpp>
#include <SkipList.hpp>
#include <iostream>

using namespace std;

int main()
{
    Polynomial p1, p2, p4;
    p1.add(1.0, 1, 2, 3);
    p1.add(2.0, 1, 3, 3);

    p2.add(1.0, 1, 2, 3);
    p2.add(2.0, 1, 3, 3);
    
    Polynomial p3(p1);
    p4 = p1 + p2;

    cout << p3;
    cout << p4;
}