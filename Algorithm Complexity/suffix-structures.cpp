#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, t; 
  string alphabetS[26]={};
  string alphabetT[26]={};
  bool isNeedTree=false;
  bool isRemove=false;
  bool isSwap=true; // true
  int sHead=0;
  cin>>s>>t;
  
  for(int i=0;i<s.length();i++){
    int pos=s[i]-'a';
    alphabetS[pos]+=1;
  }
  
  
  for(int i=0;i<t.length();i++){
    
    int pos=t[i]-'a';
    alphabetT[pos]+=1;
  }
  
  
  for(int i=0;i<s.length();i++){
    if(sHead<t.length() && s[i]==t[sHead]){
      sHead+=1;
      if(sHead==t.length()){
        isSwap=false; // false
      }
    }
  }
  
  for(int i=0;i<26;i++){
    if(alphabetS[i]<alphabetT[i]){
      isNeedTree=true;
      break;
    }
    else if(alphabetS[i]>alphabetT[i]){
      isRemove=true;
    }

    
  }
  
  if(isNeedTree){
    cout<<"need tree"; // need tree
  }  // swap -> "array", add -> "automaton", swap + add -> "both"
  else if (isRemove && isSwap){
    cout<<"both";
  }
  else if(isRemove){
    cout<<"automaton";
  }
  else{
    cout<<"array";
  }

}
