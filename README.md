在C语言中，结构体指针的定义和操作用于访问和操作结构体类型的成员。结构体指针是指向结构体变量的指针，它允许您在函数中以更有效的方式传递和修改结构体数据。以下是结构体指针的定义和操作：

1. **定义结构体指针：**

   您可以定义结构体指针如下：

   ```c
   struct MyStruct {
       int a;
       float b;
   };

   struct MyStruct myVar; // 创建结构体变量
   struct MyStruct *ptr;  // 创建结构体指针
   ptr = &myVar;          // 将指针指向结构体变量
   ```

   在上面的示例中，`ptr` 是指向 `MyStruct` 结构体类型的指针，它指向 `myVar` 结构体变量。

2. **通过指针访问结构体成员：**

   使用指针访问结构体成员可以通过指针运算符 `->` 或间接访问操作符 `*` 来完成。

   - 使用 `->`：

     ```c
     printf("a = %d, b = %f\n", ptr->a, ptr->b);
     ```

   - 使用 `*`：

     ```c
     printf("a = %d, b = %f\n", (*ptr).a, (*ptr).b);
     ```

3. **修改结构体成员：**

   通过结构体指针，您可以修改结构体的成员变量：

   ```c
   ptr->a = 42;
   ptr->b = 3.14;
   ```

   这将更新 `myVar` 结构体变量中的成员。

4. **传递结构体指针给函数：**

   您可以将结构体指针传递给函数，以便在函数内部修改结构体的值。这可以减少内存开销和提高性能，因为函数不需要复制整个结构体。

   ```c
   void modifyStruct(struct MyStruct *s) {
       s->a = 100;
       s->b = 5.67;
   }
   ```

   在调用函数时，传递结构体指针作为参数：

   ```c
   modifyStruct(ptr);
   ```

   这将修改 `myVar` 结构体变量的值。

结构体指针是C语言中用于处理复杂数据结构的强大工具，它允许您更有效地访问和修改结构体的成员。