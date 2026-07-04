#include <bits/stdc++.h>
using namespace std;

void posOrder(string preT, string inT){
    if(preT.empty()) return;

    auto it = find(inT.begin(), inT.end(), preT[0]);
    int count = it - inT.begin();
    
    posOrder(preT.substr(1, count), inT.substr(0, count));
    
    posOrder(preT.substr(count + 1), inT.substr(count + 1));
    
    cout << preT[0];
}


int main() {
    string preT = "", inT = "";

    while(cin >> preT >> inT){
        posOrder(preT,inT);
        cout << endl;
    }

    return 0;
}