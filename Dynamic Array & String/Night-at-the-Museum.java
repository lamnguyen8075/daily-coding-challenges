import java.util.Scanner;

class Main {  
  public static void main(String args[]) { 
    Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
    int result = 0;
    int current = 0;
    for (int i = 0; i<str.length();i++){
      int next = str.charAt(i) - 'a';
      result += Math.min (Math.abs(current - next), Math.min(current+26-next,26-current+next));
      current = next;
    }
		System.out.println(result);
  }
}
