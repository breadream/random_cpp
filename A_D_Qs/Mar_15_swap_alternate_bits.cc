
#include <iostream>
using namespace std; 
  
unsigned int swapBitsInPair(unsigned int x) 
{ 
    // Extract high bit, and shift it to low  bit  position
	// Extract low  bit, and shift it to high bit position
    return ((x & 0b10101010) >> 1)   
          |((x & 0b01010101) << 1);     
} 
  
/* Driver function to test above function */
int main() 
{ 
    unsigned int x = 4;  
    cout << swapBitsInPair(x);     
    return 0; 
} 
