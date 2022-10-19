class Solution{

    //Function to insert elements of array in the hashTable avoiding collisions.
    public ArrayList<ArrayList<Integer>> separateChaining(int arr[], int n, int hashSize)
    {
        ArrayList<ArrayList<Integer>> hash_table = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < hashSize; i++){
            hash_table.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < arr.length; i++){
            int slot_to_insert = arr[i] % hashSize;
            hash_table.get(slot_to_insert).add(arr[i]);
        }
        
        return hash_table;
        
    }
}
