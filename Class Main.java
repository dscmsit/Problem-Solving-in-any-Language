Class Main
{
    // Naive function to find the maximum difference between two elements in
    // an array such that the smaller element appears before the larger element
    public static int getMaxDiff(int[] A)
    {
        int diff = Integer.MIN_VALUE;
 
        int n = A.length;
        if (n == 0) {
            return diff;
        }
 
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++) {
                if (A[j] > A[i]) {
                    diff = Integer.max(diff, A[j] - A[i]);
                }
            }
        }
 
        return diff;
    }
 
    public static void main(String[] args)
    {
        int[] A = { 2, 7, 9, 5, 1, 3, 5 };
 
        int diff = getMaxDiff(A);
        if (diff != Integer.MIN_VALUE) {
            System.out.print("The maximum difference is " + diff);
        }
    }
}