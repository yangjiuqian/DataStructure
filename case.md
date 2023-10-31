# *多项式* 
## 多项式相加  
a表示多项式1的系数，b表示多项式2的系数。实现简单的系数相加 
```
vector<int> AddPolynomal(vector<int> &a, vector<int> &b){
    int *pa,*pb,*pa_last,*pb_last,*pc;
    int a_length=a.size();
    int b_length=b.size();
    int c_length;
    if(a_length>=b_length){
        c_length= a_length;
    }
    else{
        c_length=b_length;
    }
    vector<int> c(c_length,0);
    pa=&a[0];
    pa_last=&a[a_length-1];
    pb=&b[0];
    pb_last=&b[b_length-1];
    pc=&c[0];
    // for(int i=0;i<c_length;i++){
    //     *pc++=(*pa++)+(*pb++);
    // }
    while(pa<=pa_last&&pb<=pb_last){
        *pc++=(*pa++)+(*pb++);
    }
    while(pa<=pa_last){
        *pc++=*pa++;
    }
    while(pb<=pb_last){
        *pc++=*pb++;
    }
    return c;
}
```
**后续改进完善**：
  + 按照多项式的格式输出，系数为0的项不输出；
  + 利用结构变量实现任意顺序的多项式相加；
## 多项式相乘
