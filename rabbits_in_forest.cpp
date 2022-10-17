class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        if (answers.size() == 0)
            return 0;
        unordered_map<int, int> m;
        int ans = 0;
        for (int it : answers)
        {
            if (it == 0)
                ans++; // unique raabit color
            else
            {
                if (m[it] == 0)
                    ans += (it + 1); // if someone is saying 3 that means 4 rabbits are there at least which is added to the answer
                m[it]++;             // marking it in map
                if (m[it] == it + 1)
                    m[it] = 0; // clearing the freq to zero...as it means that new group of rabbits are there
            }
        }
        return ans;
    }
};