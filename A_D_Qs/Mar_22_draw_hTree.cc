void drawHTree (int x, int y, int length, the depth)
{
  int x0 = x - length/2
  int x1 = x + length/2
  int y0 = y - length/2
  int y1 = y + length/2
   
  drawLine (x0, y1, x0, y0);
  drawLine (x1, y1, x1, y0);
  drawLine (x0, y,  x1, y );
  //reducing (dividing) the length of the line segments drawn at each stage by √2.
  length /= math.sqrt(2);
  
  drawHTree(x0, y1, length, depth-1);
  drawHTree(x1, y1, length, depth-1);
  drawHTree(x0, y0, length, depth-1);
  drawHTree(x1, y0, length, depth-1);
  
}
