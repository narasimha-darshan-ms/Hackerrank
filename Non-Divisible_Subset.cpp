#include <bits/stdc++.h>
#include<set> 
#include<algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, vector<int> S) {
    int count = 0; 
    int mod[k] = {0};

    if(k == 1)  return 1;
    for(int i=0 ; i < S.size() ; i++)
        mod[ S[i] % k ]++;
    
    
    count = mod[0];
    int i=1 , j=k-1;
    while( i < j ){
        count += mod[i] >= mod[j] ? mod[i] : mod[j] ;
        j--;
        i++;
    }
    return count;
}

int main()
{

    int n , k ,num;
    cin>>n>>k;

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        cin>>num;
        S[i] = num;
    }

    int result = nonDivisibleSubset(k, S);

    cout << result << "\n";
    return 0;
}
