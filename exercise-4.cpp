/*Exer-04
Nama: Rio Sapta Samudera
NPM : 14081080030
Desc: Multilist
*/
#include<iostream>
#include<string.h>
using namespace std;

struct Contact {
	char nama[10];
	char phone[12];
	Contact *next;
};
struct Index {
	char index;
	Index *next;
	Contact *nextContact;
};

void createList(Index* &head) {
	head = NULL;
}
void createIndex(Index* &newIndex, char index) {
	newIndex = new Index;
	newIndex->index = index;
	newIndex->next = NULL;
	newIndex->nextContact = NULL;
}
void createContact(Contact* &newContact) {
	newContact = new Contact;
	cout << "Nama\t: "; cin.ignore(); cin.getline(newContact->nama, 10);
	cout << "Nomor\t: "; cin >> newContact->phone;
	newContact->next = NULL;
}
void createListIndex(Index* &head) {
	Index *newIndex;
	createList(head);
	for (char index = 'A'; index != 'Z' + 1; index++) {
		createIndex(newIndex, index);
		insertLastIndex(head, newIndex);
	}
}
void insertFirstIndex(Index* &head, Index* newIndex) {
	if (head == NULL) {
		head = newIndex;
	}
	else {
		newIndex->next = head;
		head = head->next;
	}
}
void insertLastIndex(Index* &head, Index* newIndex) {
	if (head == NULL) {
		head = newIndex;
	}
	else {
		Index *last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newIndex;
	}
}
void insertContact(Index* &head, Contact* newContact) {
	Index *idxTrav = head;
	bool isFound = 0;
	int pil;
	while (idxTrav != NULL) {
		if (idxTrav->index == toupper(newContact->nama[0])) {
			break;
		}
		idxTrav = idxTrav->next;
	}
	if (idxTrav->nextContact != NULL) {
		cout << "1. Insert First Contact\n2. Insert Last Contact" << endl;
		do {
			cin >> pil;
		} while (pil != 1 && pil != 2);
		switch (pil) {
		case 1:
			insertFirstContact(idxTrav, newContact);
			break;
		case 2:
			insertLastContact(idxTrav, newContact);
			break;
		}
	}
	else {
		insertFirstContact(idxTrav, newContact);
	}
}
void insertFirstContact(Index* &index, Contact* newContact) {
	if (index->nextContact == NULL) {
		index->nextContact = newContact;
	}
	else {
		newContact->next = index->nextContact;
		index->nextContact = newContact;
	}
}
void insertLastContact(Index* &index, Contact* newContact) {
	if (index->nextContact == NULL) {
		index->nextContact = newContact;
	}
	else {
		Contact *last = index->nextContact;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newContact;
	}
}
void deleteContact(Index* &head, Contact* &delContact) {
	char nama[10];
	Index *idxSrc = head;
	bool isFound = 0;
	cout << "Nama Kontak yang ingin didelete : "; cin.ignore(); cin.getline(nama, 10);
	while (idxSrc != NULL && !isFound) {
		if (idxSrc->index == toupper(nama[0])) {
			isFound = 1;
			break;
		}
		idxSrc = idxSrc->next;
	}
	Contact *ctcSrc = idxSrc->nextContact;
	if (ctcSrc == NULL) {
		cout << "Nama tidak ditemukan!" << endl;
	}
	else {
		Contact *prev = NULL;
		while (ctcSrc != NULL) {
			if (strcmp(ctcSrc->nama, nama) == 0) {
				isFound = 1;
				if (ctcSrc == idxSrc->nextContact) {
					delContact = ctcSrc;
					idxSrc->nextContact = ctcSrc->next;
					delContact->next = NULL;
				}
				else if (ctcSrc->next == NULL) {
					prev->next = NULL;
				}
				else {
					delContact = ctcSrc;
					prev->next = ctcSrc->next;
					delContact->next = NULL;
				}
			}
			prev = ctcSrc;
			ctcSrc = ctcSrc->next;
		}
	}
	if (!isFound) {
		cout << "Nama tidak ditemukan!" << endl;
	}
	else {
		cout << "Delete berhasil!" << endl;
	}
}
void updateContact(Index* &head) {
	char nama[10];
	Index *idxSrc = head;
	bool isFound = 0;
	cout << "Nama Kontak yang ingin dipdate : "; cin.ignore(); cin.getline(nama, 10);
	while (idxSrc != NULL && !isFound) {
		if (idxSrc->index == toupper(nama[0])) {
			isFound = 1;
			break;
		}
		idxSrc = idxSrc->next;
	}
	Contact *ctcSrc = idxSrc->nextContact;
	if (ctcSrc == NULL) {
		cout << "Nama tidak ditemukan!" << endl;
	}
	else {
		while (ctcSrc != NULL) {
			if (strcmp(ctcSrc->nama, nama) == 0) {
				isFound = 1;
				cout << "Nomor Baru : ";
				cin >> ctcSrc->phone;
			}
			ctcSrc = ctcSrc->next;
		}
	}
	if (!isFound) {
		cout << "Nama tidak ditemukan!" << endl;
	}
	else {
		cout << "Update berhasil!" << endl;
	}
}
void traversal(Index* head) {
	Index *idxTrav = head;
	cout << endl;
	bool ada = 0;
	while (idxTrav != NULL) {
		Contact *ctcTrav = idxTrav->nextContact;
		if (idxTrav->nextContact != NULL) {
			cout << "|- " << idxTrav->index << endl;
			ada = 1;
		}
		while (ctcTrav != NULL) {
			cout << "\t|- " << ctcTrav->nama << " / " << ctcTrav->phone << endl;
			ctcTrav = ctcTrav->next;
		}
		idxTrav = idxTrav->next;
	}
	if (!ada) {
		cout << "Buku Telepon Kosong." << endl;
	}
}

int main() {
	Index *head = NULL;
	Contact *contact;
	int pil; char loop;
	createList(head);
	createListIndex(head);
	do {
		system("CLS");
		cout << "1. Insert Contact\t3. Update Contact"
			<< endl << "2. Delete Contact\t4. Traversal" << endl;
		do {
			cin >> pil;
		} while (pil < 1 || pil>4);
		switch (pil) {
		case 1:
			createContact(contact);
			insertContact(head, contact);
			break;
		case 2:
			deleteContact(head, contact);
			break;
		case 3:
			updateContact(head);
			break;
		case 4:
			traversal(head);
			break;
		}
		cout << endl << "Kembali ke menu? (Y/N) ";
		do {
			cin >> loop;
		} while (loop != 'Y'&&loop != 'y'&&loop != 'N'&&loop != 'n');
	} while (loop == 'Y' || loop == 'y');
}

