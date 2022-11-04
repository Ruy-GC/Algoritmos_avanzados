#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    vector<pair<int,int>> points;
    while (n%4 != 0){
        cin>>n;
    }

    for(int i = 0; i < n; i++){
        int x;
        int y;
        cin>>x;
        cin>>y;
        points.push_back(make_pair(x,y));
    }

    return 0;
}