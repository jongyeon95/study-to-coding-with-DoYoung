#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, r, c;
    cin >> n >> r >> c;

    int row = pow((double)2, (double)n)/2;
    int col = pow((double)2, (double)n)/2;

    int cnt = 0;

    // 4분할을 통하여 r, c의 위치를 찾고
    // 그 전 사분면은 지나온 길이므로 4의배수를 통해 더해준다.
    while(n-- > 0 ) {
        int temp = pow((double)2, (double)n)/2;
        int skip = pow((double)4, (double)n);

        if(r < row && c < col){
            row -= temp;
            col -= temp;
        } else if(r < row && c >= col){
            row -= temp;
            col += temp;
            cnt += skip;
        } else if(r >= row && c < col){
            row += temp;
            col -= temp;
            cnt += skip * 2;
        }
        else{
            row += temp;
            col += temp;
            cnt += skip * 3;
        }
    }

    cout << cnt ;
    
}