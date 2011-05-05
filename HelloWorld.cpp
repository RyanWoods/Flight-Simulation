/* Lines beginning with a hash sign (#) are directives for the preprocessor. They are not regular code lines 
** with expressions but indications for the compilers's preprocessor. In this case, the directive #include
** <iostream> tells the preprocessor to include the iostream standard file. This specific file (iostream)
** includes the declarations of the basic standard input-output library in C++, and it is included because 
** its functionality is going to be used later in the program. 
*/
#include <iostream>

/* All the elements of the standard C++ library are declared within what is called a namespace, the namepsace 
** with the name std. So, in order to access its functionality, we declared with this expression that we will
** be using these entities. This line is very frequent in C++ programs that use the standard library.
*/
using namespace std;

/* This lines corresponds to the beginning of the definition of the main function. The main function is the 
** point by where all C++ programs start their execution, independently of its location within the source
** code. It does not matter whether there are other functions with other names defined before or after it -
** the instructions contained within this function's definition will always be the fist ones to be executed 
** in any C++ program. For that same reason, it is essential that all C++ programs have a main function.
**
** THe word 'main' is followed in the code by a pair of parentheses (()). THat is because it is a function
** declaration: In C++, what differentiates a function declaration from what other types of expressions are 
** these parentheses that follow its name. Optionally, these parentheses may enclose a list of paremeters
** within them. 
**
** Right after these parentheses, we can find the body of the main function enclosed in braces ({}). What is 
** contained within these braces is what the function does when it is executed.
*/
int main()
{
	/* 'cout' is declared in the iostream standard file within the std namespace,
	** so that's why we needed to include that specific file and to declare that
	** we were going to use this specific namespace earlier in our code.
	*/
	cout << "Hello, world!" << endl;

	/* The return statement causes the main function to finish. 'return' may be
	** followed by a return code (ours is 0). A return code of 0 for the main
	** function is general interpreted as the program worked as expected without
	** any errors during its execution.
	*/
	return 0;
}