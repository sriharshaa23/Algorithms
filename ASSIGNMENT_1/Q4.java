import java.util.*;
   class Add
    {
      static String findSum(String str1,String str2)
      {
         
          if(str1.length() > str2.length())
          {
             String t = str1;
             str1 = str2;
           }
           
           String str ="";
           
           int n1 = str1.length(), n2 = str2.length(); 
           str1=new StringBuilder(str1).reverse().toString();
           str2=new StringBuilder(str2).reverse().toString(); 
  
           int carry = 0;  
           for (int i = 0; i < n1; i++)  
           {
              int sum = ((int)(str1.charAt(i) - '0') + (int)(str2.charAt(i) - '0') + carry);  
                 str += (char)(sum % 10 + '0');  
                
              carry = sum/10;
           }
           
           if (carry > 0)  
           str += (char)(carry + '0');  
  
           str = new StringBuilder(str).reverse().toString(); 
  
          return str;  
          }  
  
 
  public static void main(String[] args)  
    {  
        Scanner sc=new Scanner(System.in);
       
        System.out.print("Enter the integer1: ");
        String str1=sc.nextLine();
        System.out.print("Enter the integer2: ");
        String str2=sc.nextLine();
        System.out.println(findSum(str1, str2));  
    }  
 } 
