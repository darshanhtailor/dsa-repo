#include <bits/stdc++.h>

using namespace std;

int main(){
    int r, c;
    cout << "r: "; cin >> r;
    cout << "c: "; cin >> c;
    
    int arr[r][c];
    vector<int> x, y;
    cout << "mat:\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];

            if(arr[i][j]){
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    // x is already sorted
    sort(y.begin(), y.end());

    int sz = x.size();    //x.size() == y.size()
    int xind = x[sz/2];   //median in x
    int yind = y[sz/2];   //median in y
    
    int dist = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j]){
                dist += abs(xind-i) + abs(yind-j);
            }
        }
    }

    cout << "min dist: " << dist;
    return 0;
}