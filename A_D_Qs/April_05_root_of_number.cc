double root(double x, unsigned int n) 
{  
    double lowerLimit  = 0;
    double higherLimit = (x > 1) ? x : 1;
    double tempRoot = (lowerLimit + higherLimit) / 2;
  
    while (tempRoot - lowerLimit >= 0.001)
    {
       if (pow(tempRoot, n) > x)
         higherLimit = tempRoot;
       else if (pow(tempRoot, n) < x)
         lowerLimit = tempRoot;
       else
         break;
       tempRoot = (lowerLimit + higherLimit) / 2;
    }
  
  return tempRoot;   
}

