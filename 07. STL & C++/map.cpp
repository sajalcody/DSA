#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

    map <int, int> m;
    map <int, int> :: iterator it;
    for(int i = 0; i < 5; i++)
        m.emplace(i, i+1);
    // Accessing Map elements

    // Accessing in Pair style using iterator
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    for(it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    //Accessing with auto
    for(auto x : m)
        cout<< x.first << " " << x.second << endl;

    cout << "\n Testing map of type int, vector<int> \n";
    vector <int> v{1,2,3,4,3,2,1};

    map <int, vector <int> > complexM;
    for (int i = 0; i < v.size(); i++){
        complexM[v[i]].push_back(i);
    }
    for(auto x : complexM){
        cout << x.first << ": ";
        for(auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
}