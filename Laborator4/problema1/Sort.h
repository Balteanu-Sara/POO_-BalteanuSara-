class Sort
{
private:
    int *a, n;
public:
    Sort();
    Sort(int cont, int a, int b);
    Sort(int cont, int v[]);
    Sort(int cont,...);
    Sort(char c[]);
    Sort(const Sort &s)
    {
        std::cout<<"Copy constructor\n";
        this->n=s.n;
        this->a=new int[this->n];
        for(int i=0; i<s.n; i++)
            a[i]=s.a[i];
    }
    Sort(Sort &&s)
    {
        std::cout<<"Move constructor\n";
        this->n=s.n;
        this->a=s.a;
        s.n=0;
        s.a=0;
    }
    ~Sort()
    {
        delete []a;
    }
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void quickSort(int p, int q, bool ascendent);
    void partitioneaza(int p, int q, int &k, bool ascendent);
    void BubbleSort(bool ascendent=false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
