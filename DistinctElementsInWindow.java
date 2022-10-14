public class DistinctElementsInWindow {
    public static ArrayList<Integer> countDistinct(int A[], int n, int k)
    {
         
        ArrayList<Integer> res = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();

        for(int i = 0; i < k; i++) {
            map.put(A[i],map.getOrDefault(A[i],0) + 1);
            
        }
        res.add(map.size());
        int h = k, l = 0;
        while(l < n-k) {        // Total no. of sliding windows in n-k+1
            map.put(A[h],map.getOrDefault(A[h],0) + 1);
            if(map.get(A[l]) > 1)   map.put(A[l],map.get(A[l])-1);
            else map.remove(A[l]);
            res.add(map.size());
            
            l++;
            h++;
        }
        
        return res;
    }
}
