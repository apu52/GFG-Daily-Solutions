struct Node *insert(struct Node *head, int data) {
    Node* newnode=new Node(data);
    newnode->npx=XOR(NULL,head);
    if(head!=NULL){
        Node* temp=XOR(head->npx,NULL);
        head->npx=XOR(temp,newnode);
    }
    head=newnode;
    return head;
}

vector<int> getList(struct Node *head) {
    vector<int>ans;
    Node* prev=NULL;
    while(head!=NULL){
        ans.push_back(head->data);
        Node* temp=head;
        head=XOR(prev,head->npx);
        prev=temp;
    }
    return ans;
}
