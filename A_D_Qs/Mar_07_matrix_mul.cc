   public int[][] productMatrix(int[][] A, int[][] B) {
        int[][] answer = new int[A.length][B[0].length];
        for(int i=0; i<answer.length;i++){
            for(int j=0; j<answer[0].length;j++){
               for(int k=0; k<A[0].length;k++){
                    answer[i][j] += A[i][k]*B[k][j];
                }
            }
        }
