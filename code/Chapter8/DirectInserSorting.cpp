#include<iostream>

using namespace std;

void directinser(int target[], int n);
void directinser_withsentry(int target[], int n);

int main(){
    int a[12]={0,22,44,556,146,16,7,6,88,9,356,0};
    int n = sizeof(a)/sizeof(a[0]);
    // directinser(a,n);
    directinser_withsentry(a,n);
    for(int y=1;y<n;y++){
        cout<<a[y]<<",";
    }
}

void directinser(int target[], int n){
    int x,j;
    //sizeof(target)×
    //无法直接sizeof（target），因为此处的target为指向一个数组的指针，不是一个数组
    //void directinser(int *target, int n)同样正确
    for(int i=1;i<n;i++){
        x=target[i];
        for(j=i-1;j>=0&&x<target[j];j--){
            target[j+1]=target[j];
        }
        target[j+1]=x;
    }
}

void directinser_withsentry(int target[], int n){
    int x,j;
    //sizeof(target)×
    //无法直接sizeof（target），因为此处的target为指向一个数组的指针，不是一个数组
    //void directinser(int *target, int n)同样正确
    for(int i=1;i<n;i++){
        target[0]=target[i];
        for(j=i-1;target[0]<target[j];j--){
            target[j+1]=target[j];
        }
        target[j+1]=target[0];
    }
}