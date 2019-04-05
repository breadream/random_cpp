// x ; non-negative, n = positive 
double root(double x, unsigned int n) 
{  
  if (x == 0)
    return 0;
  
  double lowerBound = 0;
  double upperBound = (x > 1) ? x : 1; // in case if it is less than 1 
  double approxRoot = (lowerBound + upperBound) / 2; 
  // 0     9 
  // 4.5 ^ 
  while (approxRoot - lowerBound >= 0.001) 
  {
    if (pow(approxRoot, n) > x)
      upperBound = approxRoot;
    else if (pow(approxRoot, n) < x)
      lowerBound = approxRoot;
    else
      break;
    
    approxRoot = (upperBound + lowerBound) / 2;
  }
  return approxRoot;
}

