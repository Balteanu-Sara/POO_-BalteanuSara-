#include "Tree.h"
using namespace std;

int main()
{
    Tree<int> *t= new Tree<int>;
    t->Add(nullptr, 1);
    t->GetNode(nullptr,0)->Print();
    t->Add(t->GetNode(nullptr,0), 3);
    t->GetNode(t->GetNode(nullptr,0),0)->Print();
    t->Add(t->GetNode(nullptr,0), 2);
    t->GetNode(t->GetNode(nullptr,0),1)->Print();
    t->Add(t->GetNode(t->GetNode(nullptr,0),0), 4);
    t->GetNode(t->GetNode(t->GetNode(nullptr,0),0), 0)->Print();
    cout<<endl;
    //t->Delete(t->GetNode(t->GetNode(nullptr,0),0)); //STERGERE
    //t->GetNode(t->GetNode(t->GetNode(nullptr,0),0), 0)->Print();

    //t->Find(2,Tree<int>::eq, t->GetNode(nullptr,0))->Print(); //FIND

    //t->Insert(t->GetNode(nullptr,0), 1, 5); //INSERARE FIUL AL DOILEA A RADACINEI
    //t->GetNode(t->GetNode(nullptr,0),0)->Print();
    //t->GetNode(t->GetNode(nullptr,0),1)->Print();
    //t->GetNode(t->GetNode(nullptr,0),2)->Print();

    //t->Sort(t->GetNode(nullptr,0), Tree<int>:: lessthan); //SORTEAZA ELEMENTELE DE PE PRIMUL NIVEL
    //t->GetNode(t->GetNode(nullptr,0),0)->Print();
    //t->GetNode(t->GetNode(nullptr,0),1)->Print();
    //t->GetNode(t->GetNode(nullptr,0),2)->Print();

    //cout<<t->Count(t->GetNode(t->GetNode(nullptr,0),0)); //NUMARUL DE FII AI UNUI NOD(DIRECTI SI INDIRECTI)
    return 0;
}
