#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
string Add(string str1, string str2)
{
	/*stringstream degree(x);
	int X=0;
	degree>>X;
	stringstream geek(y);
	int Y=0;
	geek>>Y;
	//cout<<X+Y;

	return X+Y;*/
	
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 

    cout<<str<<"\n";
  
    return str; 

}
long long int karatsuba(string x,string y){
	
	int n=max(x.length(),y.length());
	cout<<"MAX\n"<<n;
	if(n==0)
		return 0;
	if(n==1)
	{
		return (x[0]-'0')*(y[0]-'0');
	}

	int low=n/2;
	int high=n-low;

	string X1=x.substr(0,low);
	string X2=x.substr(low,high);
    
    string Y1=y.substr(0,low);
    string Y2=y.substr(low,high);

	//cout<<"Y1"<<X1<<"\n";
	//cout<<"Y2"<<X2<<"\n";

	

	long long int P1=karatsuba(X1,Y1);
	long long int P2= karatsuba(X2,Y2);
    long long int P3=karatsuba(Add(X1,X2),Add(Y1,Y2));
	//cout<<P1<<"\n";

	//return P1+P2;
	return P1*(pow(10,2*low))+ (P3-P2-P1)*(pow(10,low)) + P2;


	

}
int main()
{
    string x,y;
	long long int result;
	cout<<"Enter two numbers(large)";
	getline(cin,x);
	getline(cin,y);
    //cin>>x>>y;
	cout<<x<<" "<<y;
	result=karatsuba(x,y);
	cout<<"RESULT"<<result;

}