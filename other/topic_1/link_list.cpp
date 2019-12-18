#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node(int new_val) {
        val = new_val;
    }
}