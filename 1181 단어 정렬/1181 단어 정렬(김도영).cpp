#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main() {
	int n;
	cin >> n;

    string input; 
    int length;
    vector<pair<string, int>> s;
    for(int i = 0; i< n; i++){
        cin >> input;
        length = input.length();
        s.push_back(pair<string, int>(input, length));
    }

    sort(s.begin(), s.end(),cmp);
    
    for(int i = 0; i< n; i++){
        if(s[i].first != s[i+1].first)
            cout << s[i].first << endl;
    }

    return 0;
}

