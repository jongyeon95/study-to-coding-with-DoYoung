#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int Wdist = 0;
    int Hdist = 0;


    //w과의 거리
    Wdist = w - x;

    //h과의 거리
    Hdist = h- y;

    int answer = min(x, min(y, min(Hdist, Wdist)));

    cout << answer ;
}