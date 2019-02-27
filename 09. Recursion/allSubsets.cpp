#include <iostream>
#include <vector>
using namespace std;

void search(int n, int k, vector<int> subset, vector <vector<int> > &allSubsets){
    if(k==n+1)
        allSubsets.push_back(subset);
    else{
        subset.push_back(k);
        search(n,k+1,subset,allSubsets);
        subset.pop_back();
        search(n,k+1,subset,allSubsets);
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <vector<int> > allSubsets;
    int n=3;
    search(n,1,vector<int> {}, allSubsets);
    for(auto v:allSubsets){
        for(auto x:v)
            cout << x <<" ";
        cout << endl;
    }
    return 0;
}