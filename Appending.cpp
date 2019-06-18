void append(Node* head, int value){
    Node* n = new Node();
    n->data = value;
    n->next = NULL;
    
    Node* curr = head;
    
    while (curr->next != NULL){
        curr = curr->next;
    }
    
    curr->next = n;
}