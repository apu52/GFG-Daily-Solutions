
 
class Solution { 
public: 
    string convertToString(Node* head) 
    { 
        string s = ""; 
        bool l = 0; 
        while(head) 
        { 
            if(head->data != 0) 
                l = 1; 
            if(l) 
                s += ('0' + head->data); 
            head = head->next; 
        } 
        return s; 
    } 
    Node* subLinkedList(Node* head1, Node* head2) { 
        string s1 = convertToString(head1), s2 = convertToString(head2); 
        if(s1.size() < s2.size()) 
            swap(s1, s2); 
        else if((s1.size() == s2.size()) && s1 <= s2) 
            swap(s1, s2); 
        int n = s1.size(), m = s2.size(); 
        int carry = 0; 
        int j = m - 1; 
        for(int i = n - 1; i >= 0; i--) 
        { 
            int val = (s1[i] - '0') - carry - ((j >= 0) ? (s2[j] - '0') : 0); 
            if(val < 0) 
            { 
                carry = 1; 
                s1[i] = ('0' + 10 + val); 
            } 
            else 
            { 
                carry = 0; 
                s1[i] = ('0' + val); 
            } 
            j--; 
        } 
        int i = 0; 
        while(i < n && s1[i] == '0') 
            i++; 
        LinkedList* ans = new LinkedList(); 
        while(i < n) 
            ans->insert((s1[i++] - '0')); 
        if(ans->head == nullptr) 
            ans->insert(0); 
        return ans->head; 
    } 
};
