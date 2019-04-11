#include <bits/stdc++.h>
using namespace std;

int countarr[201];
int arr[200005];

int calc(int d) {
  int tot = 0;
  for (int i = 0; i < 201; i++) {
    tot += countarr[i];
    if (d % 2 == 1 && tot > d / 2)
      return 2 * i;
    else if (d % 2 == 0) {
      if (tot > d / 2)
        return 2 * i;
      else if (tot == d / 2) {
        int j = i + 1;
        while (countarr[i] == 0)
          j++;
        return i + j;
      }
    }
  }
  return -1;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  int i;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(countarr, 0, sizeof countarr);
  for (i = 0; i < d; i++) {
    countarr[arr[i]]++;
  }
  int j = 0;
  int warnings = 0;
  while (i < n) {
    int median = calc(d);
    // cout<<i<<" "<<median<<endl;
    if (arr[i] >= median)
      warnings++;
    countarr[arr[j]]--;
    countarr[arr[i]]++;
    i++;
    j++;
  }
  cout << warnings << endl;
  return 0;
}
