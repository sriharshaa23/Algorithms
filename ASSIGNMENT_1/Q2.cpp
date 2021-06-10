#include<bits/stdc++.h>
using namespace std;

struct node{
    int d;
    struct node* l=NULL;
    struct node* r=NULL;
};

struct node* h1,*h2;
int n;

struct node* min_h(int a[],int l,int r){
    if(l>r) return NULL;
    int m = (r+l)/2;
    struct node* N = (struct node*)malloc(sizeof(struct node));
    N->d = a[m];
    N->l = min_h(a,l,m-1);
    N->r = min_h(a,m+1,r);
    return N;
}

int ctr = 0;

struct node* max_h(int a[]){
    if(ctr>n-1) return NULL;
    struct node* N = (struct node*)malloc(sizeof(struct node));
    N->d = a[ctr];
    ctr++;
    N->r = max_h(a);
    N->l = NULL;
    return N;

}


void print(struct node* N){
    if(N!=NULL){
        cout<<N->d<<" ";
        print(N->l);
        print(N->r);
    }
}

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);

    h1 = min_h(a,0,n-1);
    cout<<"min_h tree pre-order : "<<endl;
    print(h1);
    cout<<endl;

    h2 = max_h(a);
    cout<<"max_h tree pre-order : "<<endl;
    print(h2);
}