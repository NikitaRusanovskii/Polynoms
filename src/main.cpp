#include <iostream>
#include <Polynomial.hpp>
#include <SkipList.hpp>


using namespace std;


int main() {
    SkipList<Monomial> sk;
    sk.push_back(Monomial(1, 1, 1, 1));
    cout << sk;
}