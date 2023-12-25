#include<iostream>
#include<vector>

using namespace std;

void ShellInsert(vector<int>& targrt, int dk);

void ShellSort(vector<int>& target, int dlta[], int t);

int main(){
    vector<int> a={0,81,94,11,96,12,35,17,95,28,58,41,75,15};
    int dlda[3]={5,3,1};
    ShellSort(a,dlda,3);
    for(int r=1;r<a.size();r++){
        cout<<a[r]<<endl;
    }
    return 0;
}

void ShellSort(vector<int>& target, int dlta[], int t){
    for(int k=0;k<t;++k){
        ShellInsert(target,dlta[k]);
    }
}

void ShellInsert(vector<int>& t, int dk){
    int i,j;
    // int temp;
    for(i=dk+1;i<t.size();++i){
        t[0] = t[i];
        for(j=i-dk;j>0&&(t[0]<t[j]);j=j-dk){
            t[j+dk]=t[j];
        }
        t[j+dk]=t[0];
    }
}