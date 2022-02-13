#include<bits/stdc++.h> // #include <bits/stdc++.h>

using namespace std;

const int MXN=1e5;

int main (){
  int n=0;
  int k=0;
  
  int left=-1;
  int right=-1;
  
  cin>>n>>k;
  
  int array[MXN]={};
  
  for(int i=0;i<n;i++){
    cin>>array[i];
  }
  
  int l=0;  
  int count = 0;
  int freq[MXN+1]={0};
  // [0; 0] -> [0; 1] -> [0; R] => count == k,
  // [0, R]  == k -> [1; R] == k? 
  for(int r = 0;r<n;r++){
    freq[array[r]]+=1;
    if(freq[array[r]]==1){
      count+=1;
    }
    //     l
    // [1, 2]
    if(count==k){
      while (count == k){
        freq[array[l]]-=1;
        if(freq[array[l]]==0){
          count-=1;
        }
        l+=1;        
      }
      left=l-1;
      right=r;
      // // [left; right] != [-1; -1]
      // // [left; right] so với [l; r] thì left <= l <= r <= right thì nên cập nhật lại 
      // if ( left == -1){
      //   left=l;
      //   right=r;
      // } else {
      //   // cập nhật lại left = l, right = r nếu left <= l <= r <= right
      //   if(left<=r && r<=right){
      //     left=l;
      //     right=r;            
      //   }
      // }
      break;
    }
  } 
  if(left==-1){
    cout<<-1<<" "<<-1;
  }
  else{
    cout<<left+1<<" "<<right+1;
  }
  return 0;
}
