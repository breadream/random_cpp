string decrypt( const string& word ) 
{
   int len = word.size(); 
   string res(len, '0');
   res[0] = int(word[0]);
   for(int i = 1; i < len; i++)
   {
     int temp = (int)word[i] - (int)word[i-1];
     while (temp < 97)
     {
        temp += 26;       
     } 
     res[i] = temp ;
   }
   res[0] = (int)word[0] - 1;
   return res; 
}

int main() {
  std::cout << decrypt("dnotq") << std::endl;
  return 0;
}
