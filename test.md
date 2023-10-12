在C语言中，结构体（Structures）是一种用户定义的数据类型，允许您将不同类型的数据组合成一个单一的数据结构，以便更有效地表示复杂的数据。结构体是C语言中一种重要的数据组织机制，允许您在一个数据单元中存储多个相关的数据项，这些数据项可以是不同的数据类型。

下面是结构体的基本定义和用法：

1. **定义结构体：**

   结构体的定义使用`struct`关键字，通常放在全局作用域中或在函数内部定义。例如，以下是一个表示学生的结构体的定义：

   ```c
   struct Student {
       char name[50];
       int age;
       float gpa;
   };
   ```

   这个结构体定义了一个包含学生名字、年龄和GPA（平均绩点）的数据结构。

2. **创建结构体变量：**

   通过结构体定义，您可以创建结构体变量：

   ```c
   struct Student student1;
   ```

   或者，您可以在定义结构体的同时创建变量：

   ```c
   struct Student {
       char name[50];
       int age;
       float gpa;
   } student1;
   ```

3. **访问结构体成员：**

   您可以使用点操作符(`.`)来访问结构体变量的成员：

   ```c
   strcpy(student1.name, "John");
   student1.age = 20;
   student1.gpa = 3.7;
   ```

4. **使用结构体作为函数参数：**

   您可以将结构体作为参数传递给函数，以便在函数内部处理结构体数据：

   ```c
   void printStudent(struct Student s) {
       printf("Name: %s\n", s.name);
       printf("Age: %d\n", s.age);
       printf("GPA: %.2f\n", s.gpa);
   }
   ```

5. **结构体嵌套：**

   您可以在结构体内部嵌套其他结构体，以创建更复杂的数据结构。

   ```c
   struct Address {
       char street[100];
       char city[50];
       char state[20];
   };

   struct Person {
       char name[50];
       int age;
       struct Address address;
   };
   ```

   这里，`Person` 结构体内包含了一个嵌套的 `Address` 结构体。

结构体允许您组织和管理多个相关数据项，这对于表示复杂的数据对象非常有用，例如学生、员工、地址等。结构体是C语言中一种非常重要的数据结构，它使您能够更有效地处理和操作多个数据项。
