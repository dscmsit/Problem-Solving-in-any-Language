class Solution {
public:
    vector<pair<int, string>> arr ={{1000000000, "Billion "}, {1000000, "Million "}, 
    {1000, "Thousand "}, {100, "Hundred "}, {90, "Ninety "}, {80, "Eighty "}, {70, "Seventy "},
    {60, "Sixty "}, {50, "Fifty "}, {40, "Forty "}, {30, "Thirty "}, {20, "Twenty "}, {19, "Nineteen "}, 
    {18, "Eighteen "}, {17, "Seventeen "}, {16, "Sixteen "}, {15, "Fifteen "}, {14, "Fourteen "}, 
    {13, "Thirteen "}, {12, "Twelve "}, {11, "Eleven "}, {10, "Ten "}, {9, "Nine "}, {8, "Eight "}, 
    {7, "Seven "}, {6, "Six "}, {5, "Five "}, {4, "Four "}, {3, "Three "}, {2, "Two "}, {1, "One "}};
    
    string solve(int num){
        //base case
        if(num == 0){
            return "Zero ";
        }
        
        for(auto i:arr){
            if(num>=i.first){
                string first = (num>=100 ? solve(num/i.first) : "");
                string second = (i.second);
                string third = (num%i.first == 0 ? "" : solve(num%i.first));
                    
                return first+second+third;
    
            }
                
        }
        return "";
    }
    
    string numberToWords(int num) {
        string ans = solve(num);
        
        //to pop out last substring
        ans.pop_back();
        return ans;
    }
};
