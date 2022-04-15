#include <iostream>

using namespace std;
	
int main() {
  int sizeArr1=0;
  int sizeArr2=0;
  
  int selNum1=0;
  int selNum2=0;
  
  int isLessThan=0;
  
  cin>>sizeArr1>>sizeArr2;
  cin>>selNum1>>selNum2;
  
  int array1[sizeArr1]={};
  int array2[sizeArr2]={};
  
  int arraySel1[selNum1]={};
  int arraySel2[selNum2]={};
  
  for (int i=0; i<sizeArr1;i++){
    cin>>array1[i];
  }
  for (int i=0; i<sizeArr2;i++){
    cin>>array2[i];
  }  
  
  for(int i=0; i<selNum1; i++){
		arraySel1[i]=array1[i];
  }

  for(int i=0; i<selNum1;i++){
    for(int j=sizeArr2-selNum2; j<sizeArr2;j++){
      if(array1[i]>=array2[j]){
        isLessThan=1;
      }
    }
  }
  
  if(isLessThan==1)
 		cout<<"NO";
  else
    cout<<"YES";
}
