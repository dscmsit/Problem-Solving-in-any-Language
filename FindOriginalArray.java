class FindOriginalArray {
    public int[] findOriginalArray(int[] changed) {
        int[] result = new int[changed.length/2];
    Queue<Integer> queue = new LinkedList<Integer>();
    Arrays.sort(changed);
    
    int idx = 0;
    
    for(int change : changed) {
        if(queue.isEmpty() == false && queue.peek() == change) {
            result[idx++] = queue.poll()/2;
        }
        
        else queue.add(change * 2);
    }
    
    if(queue.size() > 0) return new int[0];
    
return result;
    }
}
