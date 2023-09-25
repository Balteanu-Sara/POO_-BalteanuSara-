#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstddef>

using namespace std;

ifstream f("fisier.txt");
struct Compare{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if(a.second==b.second) return a.first> b.first;
        return a.second< b.second;
    }
};
int main()
{

    string s;
    string sep=" .,!?";
    getline(f, s);
    int i;
    for(i=0; i<s.length(); i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]-'A'+'a';

    map <string, int> M;
    vector<string> u;

    int l=0,j;

    for(i=0; i<s.length(); i++)
    {
        char c=s.at(i);

        std::size_t poz = sep.find(c);
        if(poz != std::string::npos)
        {
            string sub=s.substr(l, i-l);
            l=i+1;
            if( sub.length()>0)
            {
                u.push_back(sub);
                M[sub]++;
            }
        }
    }

    string sub=s.substr(l, i-l);
    if(sub.length()>0)
    {
        u.push_back(sub);
        M[sub]++;
    }

    priority_queue< pair<string, int>, vector<pair<string, int> >, Compare> Q;
    for(auto iter= M.begin(); iter !=M.end() ;iter++ )
    {
            Q.push(*iter);
    }

    while(!Q.empty())
    {
        cout<<Q.top().first<<" => "<< Q.top().second<< "\n";
        Q.pop();
    }
    return 0;
}
