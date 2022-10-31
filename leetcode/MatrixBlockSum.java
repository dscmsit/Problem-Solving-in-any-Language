class MatrixBlockSum {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int[][] sums = new int[mat.length+1][mat[0].length+1];
        for (int i=0;i<mat.length;i++)
        {
            for (int j=0;j<mat[0].length;j++)
            {
                sums[i+1][j+1] = sums[i+1][j] + sums[i][j+1] - sums[i][j] + mat[i][j];
            }
        }
        //System.out.println(cols[0] + " " + cols[1]);
        int[][] ans = new int[mat.length][mat[0].length];
        for (int i=0;i<mat.length;i++)
        {
            for (int j=0;j<mat[0].length;j++)
            {
                int r1 = Math.max(0,i-k), r2 = Math.min(i+k+1,mat.length), c1 = Math.max(0,j-k), c2 = Math.min(j+k+1, mat[0].length);
                ans[i][j] = sums[r2][c2] + sums[r1][c1] - sums[r1][c2] - sums[r2][c1];
            }
        }
        return ans;
    }
}