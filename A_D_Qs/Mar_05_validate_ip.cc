bool validateIP(const string& ip)
{
	// your code goes here
  // string temp = ""; 
  int temp = 0;
  int numOfX = 0;
  for (int i = 0; i < ip.size(); i++)
  {      
     if (isdigit(ip[i]))
        temp += temp * 10 + (ip[i] - '0');
     else if (ip[i] == '.' && i > 0 && ip[i-1] != '.') 
     {        
         numOfX++;
         if (temp > 255)
           return false;
         temp = 0;
     }
    else 
      return false;
  } 
  return (++numOfX > 4 || temp > 255) ? false : true;
}

