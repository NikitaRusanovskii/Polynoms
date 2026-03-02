#include <iostream>
#include <Polynomial.hpp>
#include <SkipList.hpp>


using namespace std;


int main() {
    SkipList<int> sk;
    sk.push_back(4);
    sk.remove(4);
    cout << sk;
}