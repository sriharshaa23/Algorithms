#include<bits\stdc++.h>
using namespace std;




int main(){
    int n;
    cin>>n;
    int a=log2(n);
    // int b=1.44*log2(n);

    int arr0[n], arr1[n];
    arr0[0] = 1;
    arr0[1] = 2;
    for(int i=2;i<n;i++) arr0[i]=arr0[i-1]+arr0[i-2]+1;

    int h = 0;
    for(int i=0;i<n;i++){
        if(n==arr0[i]) {h = i; break;}
        else if(n<arr0[i]) {h = i!=0?i-1:0; break;}
    }
    

    cout<<"When height of one node is 0 : \n";
    cout<<"Maximum height of AVL tree with "<<n<<" nodes is "<<h<<endl;
    cout<<"Minimum height of AVL tree with "<<n<<" nodes is "<<a<<endl<<endl;
    cout<<"When height of one node is 1 : \n";
    cout<<"Maximum height of AVL tree with "<<n<<" nodes is "<<h+1<<endl;
    cout<<"Minimum height of AVL tree with "<<n<<" nodes is "<<a+1<<endl;


}