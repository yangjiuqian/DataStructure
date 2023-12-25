#include <iostream>
#include <cstring> // Instead of <string.h>

using namespace std;

void sub(char b[]) {
    strcpy(b, "world");
}

int main() {
   char a[10] = "hello";
   sub(a);
   cout << a << endl;
   return 0;
}
 
