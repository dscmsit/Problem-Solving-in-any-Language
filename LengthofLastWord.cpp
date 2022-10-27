class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==1){
            if(s[0]==' ') return 0;
            else return 1;
        }
        int i=s.size()-1;
        int j=i;
        while(i>0){
            if(s[i]==' ') 
            while(s[i]==' ' && i>0) i--;
            if(i==0) return !(s[i]==' ');
            j=i;
            while(s[i]!=' ' && i>0) i--;
            if(i!=0 || s[i]==' ') i++;
            break;
        }
        return j-i+1;
    }
};