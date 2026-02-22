#include <Monomial.hpp>
#include <iostream>
#include <LinkedList.hpp>


using namespace std;


int main() {
    LinkedList<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(4);
    my_list.push_back(5);
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);
    my_list.push_front(4);
    my_list.push_front(5);

    cout << my_list << "size: " << my_list.size() << endl;
    my_list.clear();

    cout << "size: " << my_list.size() << endl;
}