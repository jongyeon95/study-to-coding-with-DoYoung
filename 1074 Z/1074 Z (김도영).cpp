#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, r, c;
    cin >> n >> r >> c;

    int row = pow((double)2, (double)n)/2;
    int col = pow((double)2, (double)n)/2;

    int cnt = 0;

    // 4������ ���Ͽ� r, c�� ��ġ�� ã��
    // �� �� ��и��� ������ ���̹Ƿ� 4�ǹ���� ���� �����ش�.
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