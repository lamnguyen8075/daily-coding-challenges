#include <iostream>

using namespace std; 
int main() {
    int N;
    cin >> N;
  	int T[N]={};
  	int value=0;
  	int keeper=0;
    for (int i = 0; i < N; i++){
    	cin>>T[i];
    }

		for (int j = 0; j < N; j++){
      
      if (j==0 && T[0]>15){
      	value=15;
        break;
      }
      else{
      	if((T[j]-keeper)>15){
          value=keeper+15;
          break;
        }
        else{
        	keeper=T[j];
        }
      }
      value=keeper+15;
      if(value>90){
        value=90;
      }
    }
		

		cout << value;
    return 0;
}
