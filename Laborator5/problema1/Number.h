#include <cstring>
class Number
{
   char *v;
   int base;
public:
   Number(const char *s, int value): base(value) //constructor simplu
   {
       v=new char[strlen(s)+1];
       memcpy(v,s,strlen(s)+1);
   }

   Number(int x) //constructor cu int
   {
       base=10;
       v=new char[256];
       int i=0;
       while(x>0)
       {
           char nr;
           nr=x%10+'0';
           v[i]=nr;
           i++;
           x=x/10;
       }
       v[i]=NULL;
       strrev(v);
   }

   ~Number() //deconstructor
   {
       delete[]v;
       v=nullptr;
       base=0;
   }

   Number(const Number &n) //constructor de copiere
   {
       this->v= new char[strlen(n.v)+1];
       memcpy(this->v,n.v,strlen(n.v)+1);
       this->base=n.base;
   }

   Number(Number &&n) //constructor de mutare
   {
       this->base=n.base;
       memcpy(this->v,n.v,strlen(n.v)+1);
       n.base=0;
       n.v=nullptr;
   }

   friend Number& operator+ (const Number &n1, const Number &n2);
   friend Number& operator- (const Number &n1, const Number &n2);
   Number& operator= (const Number &n);
   Number& operator= (int value);
   Number& operator= (const char* const s);
   friend Number& operator+= (Number &n1 , const Number &n2);
   friend Number& operator-= (Number &n1 , const Number &n2);
   char operator[] (int index);
   Number& operator-- ();
   Number& operator-- (int value);
   friend bool operator > (const Number &n1,const Number &n2);
   friend bool operator < (const Number &n1,const Number &n2);
   friend bool operator >= (const Number &n1,const Number &n2);
   friend bool operator <= (const Number &n1,const Number &n2);

   void SwitchBase(int newBase);
   int GetBase();
   void Print();
   int  GetDigitsCount();
};
