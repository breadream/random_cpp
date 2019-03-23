/*   Inline functions are parsed by the compiler.	
 * Macros are expanded by the preprocessor. 
 * Macros are hard to debug, can't see the function name on call stack
 * isn't able to set breakpoint 
 * doesn't follow scope */
/
/*
 * when you call function, 
 * 1. push the variables to stack
 * 2. jump to function address
 * 3. execute the funtion
 * 4. go back to caller function
 * 5. pop the step 1
 * -> slow, might not be optimal to CPU cache 
 */

