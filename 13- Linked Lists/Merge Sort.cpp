node* split(node* head){
    node* hare=head;
    node* tortoise=head;
    while(hare->next !=NULL && hare->next->next!=NULL){
        hare=hare->next->next;
        tortoise=tortoise->next;
    }
    if(hare->next==NULL){
        node* r=tortoise->next;
        tortoise->next=NULL;
        return r;
    }
    else{
        node* r=tortoise->next;
        tortoise->next=NULL;
        return r;
    }
}
node* converge(node* head1,node* head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    if(head1->data<=head2->data){
        head1->next=converge(head1->next,head2);
        return head1;
    }
    else{
        head2->next=converge(head1,head2->next);
        return head2;
    }
}
node* mergeSort(node* head){
    if(!head || head->next==NULL){
        return head;
    }
    return converge(mergeSort(split(head)),mergeSort(head));
}
