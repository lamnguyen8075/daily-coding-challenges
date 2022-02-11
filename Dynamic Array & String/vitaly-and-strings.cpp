#include <iostream>
#include <string>

using namespace std;

int main(){
  string s="";
  string t="";
	cin>>s>>t;
	for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='z'){
      s[i]='a';
    }
    else{
      s[i]++;
      break;
    }
  } 
  if(s<t){
    cout<<s;
  }
  else{
    cout<<"No such string";
  }
  
  return 0;
}
