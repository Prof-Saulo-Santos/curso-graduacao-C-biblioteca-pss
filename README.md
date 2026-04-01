![image](image/prof-saulo-santos-pss-c.png)

# pss-library
This is a C library developed to optimize the reading of character strings, integer numbers, and floating-point numbers. The functions prevent unexpected behaviors, read errors, overflow, and buffer overflow.

Reading via standard input is available for the following data types: 

int, long int, float, double, long double, char, and char[].

## 1) Usage Examples:

	char c         = input_c("Enter a char: ");                 
	int  d         = input_d("Enter an integer: ");              
	long int ld    = input_ld("Enter a long integer: ");       
	float    f     = input_f("Enter a float: ");                
	double lf      = input_lf("Enter a double: ");              
	long double Lf = input_Lf("Enter a long double: "); 
	char s[10];      input_s("Enter a string: ", s, sizeof(s)); 

## 2) If overflow occurs, the types will return:

	printf("int         %d   \n", INT_MAX);
	printf("long int    %ld  \n", LONG_MAX);
	printf("float       %f   \n", FLT_MAX);
	printf("double      %lf  \n", DBL_MAX);
	printf("long double %Lf  \n", LDBL_MAX);

## 3) The library features functions to: 

- Block invalid readings of integer and floating-point numbers
- Correctly clear the keyboard buffer
- Prevent buffer overflow when reading character strings.

## 4) How to use:

Copy and paste the `pss.c` and `pss.h` files into the root folder of your project.
Insert `#include "pss.h"` at the beginning of the file that will use the functions.
Example:

```c
#include <stdio.h>
#include "pss.h"

int main(){

	double salary = input_lf("Enter a salary: ");  // You no longer need to add a printf() before reading.

	printf("%lf", salary);

	return 0;
}
```
---
If you are using DEV-C++, include the files in your project following these steps:
- Go to "Project -> Add to Project" and include the `pss.c` and `pss.h` files.
- Compile using the option: F12		

If you are using Code::Blocks, include the files in your project following these steps:
- Go to "Project -> Add Files" and include the `pss.c` and `pss.h` files.
- Compile using the option: Ctrl+F9

If you are using the terminal:
- compile with: `gcc main.c pss.c pss.h -o test.exe`
- execute with: `./test.exe`	



## 7) Contributions are welcome!

Feel free to contribute with improvements, bug fixes, or new features for this library. Just fork the repository, make the changes, and submit a pull request.

## 8) License:

This project is distributed under the BSD 3-Clause License. See the `LICENSE.md` file for more information.
