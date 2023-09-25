#include "Node.h"
template <class T>

class Tree
{
    Node<T>* root;
    typedef bool (*funcPointer)(T , T );

public:
    Tree()
    {
        root= nullptr;
    }
    void Add(Node<T> *p, T x)
    {
        if(p==nullptr)
        {
            if (root == nullptr)
            root=new Node<T>(x);
        }
        else
        {
            Node<T> **aux;
            aux= new Node<T>*[p->c+1];
            for(int i=0; i<p->c; i++)
                aux[i]=p->childList[i];
            aux[p->c]= new Node<T>;
            aux[p->c]->value = x;
            p->c++;
            delete[]p->childList;
            p->childList=aux;
        }
    }

    Node<T>* GetNode(Node<T> *p, int index)
    {
        if(p==nullptr) return root;
        else
            if(index>=0 && index< p->c)
                return p->childList[index];
    }

    void Delete(Node<T> *p)
    {
        int i;
        for(i=0; i<p->c; i++)
            delete p->childList[i];
        delete[]p;
    }

    static bool eq(T x, T y)
    {
        return (x==y);
    }

    static bool lessthan(T x, T y)
    {
        return (x<y);
    }

    Node<T>* Find(T val, funcPointer eq, Node<T> *n)
    {
        if(eq(val, n->value)) return n;
        else
            for(int i=0; i<n->c; i++)
                {
                    Node <T>* aux = this->Find(val, eq, n->childList[i]);
                    if (aux != nullptr) return aux;
                }
        return nullptr;
    }

    void Insert(Node<T> *p, int index, T val)
    {
        if(index==p->c)
        {
            Node<T> **aux;
            aux= new Node<T>*[p->c+1];
            for(int i=0; i<p->c; i++)
                aux[i]=p->childList[i];
            aux[p->c]= new Node<T>;
            aux[p->c]->value=val;
            p->c++;
            delete[]p->childList;
            p->childList=aux;
        }
        else
        {
            Node<T> **aux;
            aux= new Node<T>*[p->c+1];
            for(int i=0; i<index; i++)
                aux[i]=p->childList[i];
            aux[index]= new Node<T>;
            aux[index]->value=val;
            for(int i=index; i<p->c; i++)
                aux[i+1]=p->childList[i];
            p->c++;
            delete[]p->childList;
            p->childList=aux;
        }
    }

    void Sort(Node<T> *n, funcPointer lessthan)
    {
        for(int i=0; i<n->c -1; i++)
            for(int j=i+1; j<n->c; j++)
                if(!lessthan(n->childList[i]->value, n->childList[j]->value))
                {
                    Node<T>*aux= n->childList[i];
                    n->childList[i]= n->childList[j];
                    n->childList[j]= aux;
                }
    }

    int Parcurgere(Node<T> *n)
    {
        int sum=1;
        for(int i=0; i< n->c; i++)
            sum+=Parcurgere(n->childList[i]);
        return sum;
    }

    int Count(Node<T> *n)
    {
        if(n==nullptr)
            return Parcurgere(root)-1;
        else
            return Parcurgere(n)-1;
    }
};

