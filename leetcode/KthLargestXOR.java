class KthLargestXOR {
    public int kthLargestValue(int[][] matrix, int k) {
        int[][] dp = new int[matrix.length][matrix[0].length];
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i=0;i<matrix.length;i++)
        {
            for (int j=0;j<matrix[0].length;j++)
            {
                int a = (i-1 < 0 ? 0 : dp[i-1][j]);
                int b = (j-1 < 0 ? 0 : dp[i][j-1]);
                int c = ((i-1 < 0 || j-1 < 0) ? 0 : dp[i-1][j-1]);
                
                dp[i][j] = a^b^c^matrix[i][j];
                pq.add(dp[i][j]);
            }
        }
        k--;
        while (k-- > 0) pq.remove(pq.peek());
        return pq.peek();
    }
}