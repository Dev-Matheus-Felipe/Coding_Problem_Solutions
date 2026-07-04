#include <bits/stdc++.h>
using namespace std;

void posOrdem(string pre, string in) {
    if (pre.empty()) return;

    char raiz = pre[0];

    auto pos = find(in.begin(), in.end(), raiz);
    int k = pos - in.begin();

    string inEsq = in.substr(0, k);
    string inDir = in.substr(k + 1);

    string preEsq = pre.substr(1, k);
    string preDir = pre.substr(k + 1);

    posOrdem(preEsq, inEsq);
    posOrdem(preDir, inDir);

    cout << raiz;
}

int main() {
    int n, m;
    string pre, in;

    cin >> n;

    while (n--) {
        cin >> m >> pre >> in;
        posOrdem(pre, in);
        cout << '\n';
    }

    return 0;
}