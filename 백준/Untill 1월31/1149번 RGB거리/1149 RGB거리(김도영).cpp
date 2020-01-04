#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int rgb[1000][3];
    for(int i = 0; i<t; i++){
        for(int j =0; j<3; j++){
            int input;
            cin >> input;
            rgb[i][j] = input;
        }
    }

    for(int i = 0; i<t-1; i++){
        rgb[i+1][0] += min(rgb[i][1], rgb[i][2]);
        rgb[i+1][1] += min(rgb[i][0], rgb[i][2]);
        rgb[i+1][2] += min(rgb[i][0], rgb[i][1]);
    }

    int min = rgb[t-1][0] < rgb[t-1][1] ? rgb[t-1][0] < rgb[t-1][2] ? rgb[t-1][0] : rgb[t-1][2] : rgb[t-1][1] < rgb[t-1][2] ? rgb[t-1][1] : rgb[t-1][2];

    cout << min << endl;

    



}