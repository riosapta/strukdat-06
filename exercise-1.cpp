void createNode(node* &newNode) {
	newNode = new node;
	cout << "data : "; cin >> newNode->data;
	newNode->next = NULL;
}
void insertFirst(node* &head, node* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	cout << endl << "insertFirst berhasil!" << endl;
}
void insertLast(node* &head, node* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		node *last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode;
	}
	cout << endl << "insertLast berhasil!" << endl;
}
void deleteFirst(node* &head, node* &delNode) {
	delNode = head;
	if (head == NULL) {
		delNode = NULL;
	}
	else {
		head = head->next;
		delNode->next = NULL;
		delNode = NULL;
		cout << endl << "deleteFirst berhasil!" << endl;
	}
}
void deleteLast(node* &head, node* &delNode) {
	delNode = head;
	if (head == NULL) {
		delNode = NULL;
	}
	else {
		node *prevLast;
		while (delNode->next != NULL) {
			prevLast = delNode;
			delNode = delNode->next;
		}
		prevLast->next = NULL;
		delNode = NULL;
		cout << endl << "deleteLast berhasil!" << endl;
	}
}
void traversal(node* head) {
	if (head != NULL) {
		node *trav = head;
		while (trav != NULL) {
			cout << "'" << trav->data << "'";
			if (trav->next != NULL) {
				cout << "->";
			}
			trav = trav->next;
		}
	}
	else {
		cout << "List Kosong!" << endl;
	}
}