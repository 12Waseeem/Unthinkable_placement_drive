/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;

int main()
{   
    int n=0;
    cout<<"Enter the no.";
    cin>> n;
    vector<int> prime;
    int count=0;
    // storing n primes number in vector
    prime.push_back(1);
    prime.push_back(2);
    prime.push_back(3);
    int j=4;
    while(prime.size()<=n){
          int i=2;
        for(; i<j; i++){
            if(j%i==0) break;
        }
         if(i==j)prime.push_back(j);
            j++;
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<prime[j]<<" ";
        }
        cout<<endl;
    }
    
    

    return 0;
}
