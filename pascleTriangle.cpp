#include <iostream>
#include <vector>
using namespace std;

int main() {   
    int n = 0;
    cout << "Enter the number of rows: ";
    cin >> n;

    vector<int> pre(n);

    for (int i = 0; i < n; ++i) {
        vector<int> next(n);
        for (int j = 0; j <= i; ++j) {
            if(j==0 || j==i){
                   next[0] = next[i] = 1;
                   cout<<1<<" ";
            }
            else{
             next[j] =  pre[j - 1] + pre[j];
             cout<<next[j]<<" ";
            }
        }
        pre=next;
        cout << endl;
    }

    return 0;
}
