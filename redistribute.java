class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;
        int[] freq = new int[26];
        for(int i=0;i<words.length;i++){
            String word =words[i];
            for(int j=0;j<word.length();j++){
                char c= word.charAt(j);
                freq[c-'a']++;
            }

        }for(int i=0;i<26;i++){
        if(freq[i]%n!=0){
            return false;
        }
        }
        return true;
        
    }
}
