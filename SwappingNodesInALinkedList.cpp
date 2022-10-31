class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0; //to count to size of linked list
        //temp pointing to the head of ll
        ListNode *temp=head;
        ListNode *temp2=head;
        //tranforming the linked list into array
        //creating a vector
        vector <int> v;
        //pushing back every element from ll to array
        while(temp)
        {
        v.push_back(temp->val);
        temp=temp->next;
        count++; //to get size of vector
        }
        //swapping the elemnt
        swap(k-1,count-k,v);
        //printing the entire linked list after swapping the elements
        int i=0;
        while(temp2)
        {
            //make use of vector while printing
            temp2->val=v[i];
            i++;
            temp2=temp2->next;
        }
        return head;
    }
    void swap(int i,int j,vector<int> &v)
    {
        int swappy=v[i];
        v[i]=v[j];
        v[j]=swappy;
        
    }
};
