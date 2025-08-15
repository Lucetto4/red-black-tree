#ifndef redBlackTree_H 
#define redBlackTree_H
#include <iostream>
using namespace std;
class redBlackTree{
    public:
    redBlackTree();
    ~redBlackTree();
    
    void insert(int value);
    void remove(int value);
    void print();
    void getValCount(int value);
    private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;
        bool color;
        int count;
    };
    Node* root;
    void rbdestructor(Node* curr);
    void printfunc(Node* curr);
    void insFix(Node* newN);
    void rotateLeft(Node* current);
    void rotateRight(Node* current);
};



#endif