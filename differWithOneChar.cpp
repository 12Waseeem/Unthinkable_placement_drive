
#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
using namespace std;
bool differWithOneChar(vector<string> & disc){
    unordered_map<char, bool> mp;
    for(int i=0; i<disc[0].length(); i++){
        mp[disc[0][i]]=true;
    }

    for(int i=1; i<disc.size(); i++){
        int distinct=0;
        for(int j=0; j<disc[0].length(); j++){
            if(mp.find(disc[i][j])==mp.end()) distinct++;
        }
        if(distinct>1) return false;
    }
    return true;
}

int main() {   
     vector<string> disc = {"abcd ","acbd", "aacc"};
    cout << (differWithOneChar(disc) ? "True" : "False") << endl;
  
    return 0;
}
