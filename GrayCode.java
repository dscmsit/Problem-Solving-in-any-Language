class Solution {
    public List<Integer> grayCode(int n) {
        List<String> ans=sol(n);
        List<Integer> ans1=new ArrayList<>();
        for(int i=0;i<ans.size();i++){
            ans1.add(Integer.parseInt(ans.get(i),2));
        }
        return ans1;
    }
    public List<String> sol(int n){
        if(n==1){
            List<String> list=Arrays.asList("0","1");
            return list;
        }

        List<String> rres=sol(n-1);
        List<String> ans=new ArrayList<>();

        for(int i=0;i<rres.size();i++){
            ans.add("0"+rres.get(i));
        }
        for(int i=rres.size()-1;i>=0;i--){
            ans.add("1"+rres.get(i));
        }
        return ans;
    }
}
