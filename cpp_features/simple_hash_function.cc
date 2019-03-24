// The reason why prime numbers are used is to minimize collisions 
// when the data exhibits some particular patterns
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

size_t hashStr(const char* s)
{
   size_t h = FIRSTH;
   while (*s) 
   {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h; // or return h % C;
}

// size_t -> a type able to represent the size of any object in bytes
