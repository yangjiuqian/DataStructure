#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& target);

int main(){
    vector<int> a={2,55,1,44,17};
    bubbleSort(a);
    for(int elem:a){
        cout<<elem<<endl;
    }
    return 0;
}

void bubbleSort(vector<int>& target){
    int m,i,j;
    int temp;
    int n=target.size();
    for(m=1;m<=n-1;m++){
        for(j=0;j<n-m;j++){
            if(target[j]>target[j+1]){
                temp=target[j];
                target[j]=target[j+1];
                target[j+1]=temp;
            }
        }
    }
}
