#include<bits/stdc++.h>
using namespace std;

void q5(){
    string num1, num2;
    cout<<"Enter two floating numbers one followed by another: \n";
    cin>>num1>>num2;

    string ip1,ip2,dp1,dp2;

//SPLITTING NUMBERS IN INTEGER AND DECIMAL PARTS
    int i=0;
    while (num1[i]!='.'){
        ip1.push_back(num1[i]);
        i++;
    }
    i++;
    while (i<num1.length()){
        dp1.push_back(num1[i]);
        i++;
    }
    i=0;
    while (num2[i]!='.'){
        ip2.push_back(num2[i]);
        i++;
    }
    i++;
    while (i<num2.length()){
        dp2.push_back(num2[i]);
        i++;
    }

    if(dp1.length()<dp2.length()){
        for(int i=dp1.length();i<dp2.length();i++) dp1.push_back('0');
    }
    else{
        for(int i=dp2.length();i<dp1.length();i++) dp2.push_back('0');
    }

//DECIMAL PART
    reverse(dp1.begin(),dp1.end());
    reverse(dp2.begin(),dp2.end());

    int len = dp1.length();

    string dp = "";
    int c = 0;

    for(i=0;i<len;i++){
        int temp_sum = ((dp1[i]-'0')+(dp2[i]-'0')+c);
        dp.push_back(temp_sum%10+'0');
        c = temp_sum/10;
    }

    reverse(dp.begin(), dp.end());

//INTEGER PART
    int len1 = ip1.length(), len2 = ip2.length();

    if(len1>len2) {
        swap(ip1,ip2);
        swap(len1,len2);
    }

    reverse(ip1.begin(),ip1.end());
    reverse(ip2.begin(),ip2.end());

    string ip = "";
    int temp_sum = ((ip1[0]-'0')+(ip2[0]-'0')+c);
    ip.push_back(temp_sum%10+'0');
    int c2 = temp_sum/10;

    for(int i=1;i<len1;i++){
        int temp_sum = ((ip1[i]-'0')+(ip2[i]-'0')+c2);
        ip.push_back(temp_sum%10+'0');
        c2 = temp_sum/10;
    }
    for(int i = len1;i<len2;i++){
        int temp_sum = ((ip2[i]-'0') + c2);
        ip.push_back(temp_sum%10+'0');
        c2 = temp_sum/10;
    }
    if(c2) ip.push_back(c2+'0');

    reverse(ip.begin(), ip.end());
    
    cout<<num1<<" + "<<num2<<" = "<<ip<<"."<<dp<<endl;

}



int main(){
    q5();
}