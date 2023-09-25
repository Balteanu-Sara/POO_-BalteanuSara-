#include <iostream>
template <class T>

class Node
{
public:
    T value;
    Node<T> **childList;
    int c;
    int kids;
    Node<T>(): c(0), childList(nullptr), kids(0) {};
    Node<T>(T x): c(0), childList(nullptr), kids(0), value(x) {};
    Node(Node &n)
    {
        this->value= n->value;
        this->c= n->c;
        this->kids= n->c;
        this->childList= new Node<T>*[this->c];
        for(int i=0; i<this->c; i++)
            this->childList[i]= new Node<T>(&n->childList[i]);
    }
    void Print()
    {
        std::cout<<value<<std::endl;
    }
};
