import java.util.Scanner;

class Main {  
  public static void main(String args[]) { 
int N = 0; 
Scanner scanner = new Scanner(System.in);
N = scanner.nextInt();
int[] A = new int[N];
for(int i = 0; i < A.length;i++){
  A[i]=scanner.nextInt();  
}
	if(N==1){
	  if(A[0] == 1){
		System.out.print("YES");		  
	  }
    else{
    System.out.print("NO");
    }
	}
	else{
	  int flag=0;
	  for(int i = 0; i < N; i++){
	    if(A[i]==0){
	      flag+=1;
	    }
	  }
	if(flag==1){
		System.out.print("YES");
	}
	else{
		System.out.print("NO");	
	}
	}
  } 
}
