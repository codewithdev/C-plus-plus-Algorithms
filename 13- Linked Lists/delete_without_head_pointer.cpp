void deleteNode(Node*node){
	*node= *(node->next);
}