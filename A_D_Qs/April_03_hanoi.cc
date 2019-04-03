/*
 * tower(disk, source, inter, dest)
IF disk is equal 1, THEN
      move disk from source to destination
   ELSE
      tower(disk - 1, source, destination, intermediate)   // Step 1
      move disk from source to destination                 // Step 2
      tower(disk - 1, intermediate, destination, source)   // Step 3
   END IF
   
END
*/

void move(int n, int from, int to, int intermediate) {
  if (n == 1) {
    std::cout << "Move disk from pole " << from << " to pole " << to << std::endl;
  } else {
    move(n - 1, from, intermediate, to);
    move(1, from, to, intermediate);
    move(n - 1, intermediate, to, from);
  }
}
