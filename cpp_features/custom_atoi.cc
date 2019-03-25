// A simple atoi() function 
int myAtoi(char *str) 
{ 
  	int result = 0;
    while (*str)
    {
      result = result * 10 + (*str - '0');
      str++;
    }
  return result;
} 
