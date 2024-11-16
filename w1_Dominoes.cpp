#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

void test_case() {
  int n;
  cin>>n;
  std::vector<int> arr(n);

  for(int x = 0; x < n; x++){
        cin>> arr[x];

  }
  int fallen = 1;
  int left = arr[0]-1;
  int curr;
  int max;
  for(int i=1; i<n;i++) {
    left--;
    curr = arr[i]-1;
    max = std::max(curr, left);
    left = max;
    fallen++;
     if(left==0){
      break;
    }
  }
  
  cout<<fallen<<endl;

}

int main() {
  
  ios_base::sync_with_stdio(false);
  
  int t;
  cin>>t;
  
  
  for(int i=0; i<t; ++i) {
    test_case();
  }
  
  return 0;
}
