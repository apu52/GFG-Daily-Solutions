class Solution
{
    public:
        
        long long unsigned int decimalValue(Node *head)
        {
           
           long long unsigned int ans=0;
           int mod=1e9+7;
           Node*temp=head;
           while(temp){
               ans=ans*2+temp->data;
               temp=temp->next;
               ans=ans%mod;
           }
           return ans;
        }
};
