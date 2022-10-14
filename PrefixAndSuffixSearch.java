// 745. Leetcode [Hash Table]

import java.util.*;

class WordFilter {
    HashMap<String, List<Integer>> prefixMap = new HashMap<>();
    HashMap<String, List<Integer>> suffixMap = new HashMap<>();

    public WordFilter(String[] words) {

        for (int w = 0; w < words.length; w++) {
            for (int i = 0; i <= 10 && i <= words[w].length(); i++) {
                String s = words[w].substring(0, i);
                if (!prefixMap.containsKey(s))
                    prefixMap.put(s, new ArrayList<>());
                prefixMap.get(s).add(w);
            }
            for (int i = 0; i <= 10 && i <= words[w].length(); i++) {
                String s = words[w].substring(words[w].length() - i);
                if (!suffixMap.containsKey(s))
                    suffixMap.put(s, new ArrayList<>());
                suffixMap.get(s).add(w);
            }
        }
    }

    public int f(String prefix, String suffix) {
        if (!prefixMap.containsKey(prefix) || !suffixMap.containsKey(suffix))
            return -1;
        List<Integer> pIndexes = prefixMap.get(prefix);
        List<Integer> sIndexes = suffixMap.get(suffix);
        int i = pIndexes.size() - 1, j = sIndexes.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pIndexes.get(i) < sIndexes.get(j))
                j--;
            else if (pIndexes.get(i) > sIndexes.get(j))
                i--;
            else
                return pIndexes.get(i);
        }
        return -1;
    }

    public static void main(String[] args) {
        String[] words = { "hello", "hellow" };
        String prefix = "he", suffix = "w";
        WordFilter obj = new WordFilter(words);
        int param_1 = obj.f(prefix, suffix);
        System.out.println(param_1);
    }
}