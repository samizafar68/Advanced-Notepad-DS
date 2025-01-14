#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include"cursor.h"
using namespace std;
struct stack_node {
	char value;
	stack_node* next;
};
class stack {// Here in this class stack is implement
public:
	stack_node* top_val;
	void push(char v) {// function for push value in stack
		stack_node* n = new stack_node;
		n->value = v;
		if (top_val == NULL) {
			top_val = n;
			n->next = NULL;
		}
		else {
			n->next = top_val;
			top_val = n;
		}
	}
	char pop() {// function pop value from stack
		char ch;
		if (top_val == NULL) {
			return ' ';
		}
		else {
			stack_node* del = top_val;
			top_val = top_val->next;
			ch = del->value;
			delete del;
			del = NULL;
			return ch;
		}
	}
	void en(char h) {
		stack_node* n = new stack_node;
		n->value = h;
		if (top_val == NULL) {
			n->next = NULL;
			top_val = n;
		}
		else
		{
			stack_node* c = top_val;
			while (c->next != NULL) {
				c = c->next;
			}
			c->next = n;
			n->next = NULL;
		}
	}
	void Display() {
		stack_node* curr = top_val;
		while (curr != NULL) {
			cout << curr->value << " ";
			curr = curr->next;
		}
	}
};

class node// Class of Npode Which declare pointer of left,right,bottom,top of node type and data of character type
{
public:

	//--------------------------------------
	char data;
	node* left;
	node* right;
	node* top;
	node* bottom;
	node()
	{
		data = ' ';
		left = NULL;
		right = NULL;
		top = NULL;
		bottom = NULL;
	}

	//---------------------------------
};
class note_pad :public stack// here inherit stack class with note_pad class
{
public:
	node* head;
	node* Start;
	node* curr_line;
	node* curr_char;
	node* curr;
	node* temporary;
	char arr[1000];
	int size;
	//--------------------//
	note_pad()
	{
		Start = NULL;
		curr_line = NULL;
		curr_char = NULL;
		curr = NULL;
		head = NULL;
	}

	//--------------------------
	void ADD_TEXT(char ch, int& x, int& y);
	void display();
	void searchWord(string word);
	void deleteText();
	void find_and_Replace_Word();
	bool copy_Text(int startx, int starty, int endx, int endy);
	void count_word_In_notepad();
	void saveText();
	void pasteText(int &y);
	void undo_Text();
	void similarties_two_file();
};
            //---------------------------------------//
           //                                       //
          // Function For Display Data in Note Pad //
         //                                       //
        //---------------------------------------//
void note_pad::display()
{
	node* temp = Start;
	node* temp1 = Start;
	while (temp1 != NULL && temp != NULL)
	{

		if (temp->right == NULL)
		{
			cout << temp->data << endl;
			temp1 = temp1->bottom;
			temp = temp1;
		}
		else
		{
			cout << temp->data;
			temp = temp->right;
		}

	}
}
                               //---------------------------------------//
                              //                                       //
                             // Function For Add Text Data in Note Pad//
                            //                                       //
                           //---------------------------------------//

void note_pad::ADD_TEXT(char ch, int& x, int& y)
{
	static int c = 0;
	static int r = 0;
	static int count = 0;
	if (ch == '<') {// for move left
		x--;
		int i = 0, j = 0;
		node* dd = Start;
		if (r != 0) {
			while (r != 0) {
				x--;
				r--;
			}
		}
		while (j < y) {
			dd = dd->bottom;
			++j;
		}
		while (i < x) {
			dd = dd->right;
			i++;
		}
		node* del = dd;
		del->left->right = del->right;
		delete del;
		return;
	}
	if (ch == ' ') {// for space 
		++x;
		++r;
		//return;
	}
	if (ch == 39) {// for right arrow
		x--;
		return;
	}
	if (ch == 8)
	{
		x = c - 1;
		y--;
	}
	if (ch == 13)// for enter asscci
	{
		++y;
		++count;
		c = x;
		x = 0;
		return;
	}
	else
	{
		static int c1 = 2;
		node* n = new node;
		if (Start == NULL)
		{
			n->data = ch;
			n->right = NULL;
			n->left = NULL;
			n->top = NULL;
			n->bottom = NULL;
			Start = n;
			curr_char = n;
			curr_line = n;
			head = n;
			x++;

		}
		else
		{
			if (count > 1)
			{
				int k = c;
				curr = curr_line;
				node* p = NULL;
				while (count != 0)
				{
					while (c != 0)
					{
						if (c > k - 1)
						{
							n->data = ' ';
							if (curr->bottom == NULL)
							{
								curr->bottom = n;
								n->top = curr;
								n->left = n->right = NULL;
								p = n;
								curr_line = n;
								curr = curr->right;
							}
						}
						else
						{
							if (curr == NULL)
							{
								curr->bottom = n;
								n->top = curr;
								p->right = n;
								n->left = p;
								n->right = NULL;
								p = n;
								curr = curr->right;
							}
						}
						c--;
					}
					count--;
				}
			}
			else
			{
				if (count == 1)
				{
					if (c1 == 2)
					{
						curr = Start;
						while (curr != NULL)
						{
							if (curr->bottom == NULL)
							{
								n->data = ch;
								curr->bottom = n;
								n->top = curr;
								n->left = n->right = NULL;
								curr_line = n;
								curr = curr->right;
								c1 = 0;
								++x;
								return;
							}
							curr = curr->bottom;

						}
					}
					if (c1 == 0)
					{
						node* tem = curr_line;
						while (tem->right != NULL)
						{
							tem = tem->right;
						}
						n->data = ch;
						if (curr != NULL)
						{
							curr->bottom = n;
							n->top = curr;
							tem->right = n;
							n->left = tem;
							n->right = NULL;
							curr = curr->right;
							++x;
							return;
						}
						else
						{
							tem->right = n;
							n->left = tem;
							n->bottom = n->top = n->right = NULL;
							++x;
							return;
						}
					}
				}
				else
				{
					node* t = curr_line;
					while (t->right != NULL)
					{
						t = t->right;
					}
					n->data = ch;
					t->right = n;
					n->left = t;
					n->bottom = n->top = n->right = NULL;
					x++;
					return;
				}
			}

		}
	}

}
           //---------------------------------------//
		  //                                       //
		 // Function For Save Data in Note Pad    //
		//                                       //
	   //---------------------------------------//
void note_pad::saveText() {
	node* temp = Start;
	node* temp1 = Start;
	string myfile;
	cout << "Enter a File Name:";
	cin >> myfile;
	ofstream file(myfile);
	if (!file.is_open()) {
		cout << "File Not Opened." << endl;
	}
	else {
		cout << "File Open Succefully." << endl;
	}
	while (temp1 != NULL && temp != NULL)
	{

		if (temp->right == NULL)
		{
			file << temp->data << endl;
			temp1 = temp1->bottom;
			temp = temp1;
		}
		else
		{
			file << temp->data;
			temp = temp->right;
		}

	}
	file.close();
}
           //---------------------------------------//
		  //                                       //
		 // Function For Search  Word in Note Pad //
		//                                       //
	   //---------------------------------------//
void note_pad::searchWord(string word)
{
	int n = word.length();
	node* temp = Start;
	node* temp1 = Start;
	int count = 0;
	int i = 0;
	int k = 0;
	while (temp1 != NULL && temp != NULL)
	{

		if (temp->right == NULL)
		{
			temp1 = temp1->bottom;
			temp = temp1;
		}
		else
		{
			i = 0;

			if (temp->data = word[0])
			{
				node* t = temp;
				while (t != NULL && t->data == word[i])
				{
					t = t->right;
					i++;
				}
				if (i == n)
				{
					++count;
				}
			}
			temp = temp->right;
		}

	}
	if (count > 0)
	{
		cout << "Ocurence Of Word " << word << " is " << count << " Times." << endl;
	}
	else
	{
		cout << "Word " << word << " Not Found." << endl;
	}
}

           //---------------------------------------//
		  //                                       //
		 // Function For Delete  Data in Note Pad //
		//                                       //
	   //---------------------------------------//
void note_pad::deleteText()
{
	string text;
	int k = 0;
	cout << "Enter text to delete: ";
	cin.ignore(); //Here  Ignore the newline character
	getline(cin, text);
	node* current = Start;
	node* t = Start;
	bool u = false;
	int z = 0;
	while (current != nullptr && t != NULL)
	{
		if (current->data == text[0])
		{
			node* match = current;
			int i = 0;
			while (match != nullptr && match->data == text[i])
			{
				match = match->right;

				i++;
			}
			if (text[i] == '\0')
			{
				// Here Match the word and  delete the nodes
				node* prev = current->left->left;
				node* next = match;
				if (z < 1) {
					en(current->left->data);
					++z;
				}
				while (current != next)
				{
					en(current->data);
					node* temp = current;
					current = current->right;
					if (prev != nullptr)
					{
						prev->right = current;
					}
					else
					{
						Start = current;
					}
					if (current != nullptr)
					{
						current->left = prev;
					}
					if (k < 1) {
						temporary = temp->left->left;
						++k;
					}
					delete temp;
					u = true;
				}
			}
		}
		current = current->right;
		if (current == NULL && t->bottom == NULL) {
			return;
		}
		if (current->right == NULL) {
			t = t->bottom;
			current = t;

		}
	}
	if (u == false) {
		cout << "Given Text Not found." << endl;
	}
}
           //---------------------------------------//
		  //                                       //
		 //   Function For Undo Data in Note Pad  //
		//                                       //
	   //---------------------------------------//
void note_pad::undo_Text() {
	while (top_val != NULL) {
		node* n = new node;
		n->data = pop();
		if (temporary->right == NULL) {
			temporary->right = n;
			n->left = temporary;
			n->right = NULL;
			temporary = n;
		}
		else {
			temporary->right->left = n;
			temporary->right->left->right = temporary->right;
			temporary->right = n;
			n->left = temporary;
			temporary = n;
		}

	}
}
           //---------------------------------------//
		  //                                       //
		 // Function For Replace Data in Note Pad //
		//                                       //
	   //---------------------------------------//
void note_pad::find_and_Replace_Word() {
	char str[100], str1[100];
	cout << "Enter a String which you Replace:";
	cin >> str;
	cout << "Enter a Replaceing String:";
	cin >> str1;
	node* temp = Start;
	node* temp1 = Start;
	int count = 0;
	int i = 0;
	while (temp1 != NULL && temp != NULL)
	{

		if (temp->right == NULL)
		{
			temp1 = temp1->bottom;
			temp = temp1;
		}
		else
		{
			i = 0;
			if (temp->data == str[i])
			{
				node* t = temp;
				while (t != NULL && t->data == str[i])
				{
					t->data = str1[i];
					t = t->right;
					i++;
				}
			}
			temp = temp->right;
		}
	}


}
           //---------------------------------------//
		  //                                       //
		 // Function For Copy  Data From Note Pad //
		//                                       //
	   //---------------------------------------//
bool note_pad::copy_Text(int startx, int starty, int endx, int endy)
{

	node* Y = Start;
	int positionY = 0;
	while (Y != NULL && positionY < starty)
	{
		Y = Y->bottom;
		positionY++;
	}
	if (Y == NULL)
	{
		return false;
	}
	node* X = Y;
	//for start  x
	int PositionX = 0;
	while (X != NULL && PositionX < startx)
	{
		X = X->right;
		PositionX++;

	}
	if (X == NULL)
	{
		cout << "Not found" << endl;
		return false;
	}
	int P1 = 0, P2 = 0;
	//--------------------------------//
	node* lin = Y;
	node* col = X;
	node* t = X;
	endy += 1;
	endx += 2;
	while (P1 < endy) {
		if (P1 == endy - 1) {
			while (P2 < endx && t != NULL) {
				arr[size] = t->data;
				t = t->right;
				++size;
				++P2;
			}
			break;
		}
		else {
			while (t != NULL) {
				//cout << t->data;
				arr[size] = t->data;
				t = t->right;
				++size;
			}
		}
		t = lin;
		t = t->bottom;
		lin = t;
		++P1;
	}
	for (int j = 0; j < size; ++j) {
		cout << arr[j];
	}cout << endl;
	return true;
}
           //---------------------------------------//
		  //                                       //
		 // Function For Paste Data in Note Pad   //
		//                                       //
	   //---------------------------------------//
void note_pad::pasteText(int &y) {
	int x, y1;
	cout << "Enter a position of x(row):";
	cin >> x;
	cout << "Enter a position of y(col):";
	cin >> y1;
	if (y1 > y) {
		do {
			cout << "Enter again Position pf y(col):";
			cin >> y1;
		} while (y1 > y);
	}
	node* temp = Start;
	node* temp1 = Start;
	int i = 0;
	while (i < y) {
		temp = temp->bottom;
		i++;
	}
	i = 0;
	while (i < x) {
		temp = temp->right;
		i++;
	}
	i = size;
	while (i  >= 0) {
		node* n = new node;
		n->data = arr[i];
		n->right = temp->right;
		temp->right->left = n;
		temp->right = n;
		n->left = temp;
		i--;
	}

}
           //---------------------------------------//
		  //                                       //
		 // Function For Count Word   in Note Pad //
		//                                       //
	   //---------------------------------------//
void note_pad::count_word_In_notepad()
{
	int count = 0;
	node* temp = Start;
	node* temp1 = Start;
	while (temp1 != NULL && temp != NULL)
	{

		if (temp->right == NULL)
		{
			count++;
			cout << temp->data << endl;
			temp1 = temp1->bottom;
			temp = temp1;
		}
		else
		{
			count++;
			cout << temp->data;
			temp = temp->right;
		}

	}

	cout << "Total Charcter or Word in Notepad is:" << count << endl;
}
           //-----------------------------------------//
		  //                                         //
		 // Function For Simliar File Check Note Pad//
		//                                         //
	   //-----------------------------------------//
void note_pad::similarties_two_file() {
	string myfile,myfile1;
	cout << "Enter a First File Name:";
	cin >> myfile;
	ifstream file(myfile);
	if (!file.is_open()) {
		cout << "File Not Opened." << endl;
	}
	else {
		cout << "File Open Succefully." << endl;
	}

	cout << "Enter a File Two Name:";
	cin >> myfile1;
	ifstream file1(myfile1);
	if (!file1.is_open()) {
		cout << "File Not Opened." << endl;
	}
	else {
		cout << "File Open Succefully." << endl;
	}
	char array[100], array1[100];
	int i = 0,counter=0;
	while (file >> array[i]) {
		++counter;
		++i;
	}
	i = 0;
	while (file1 >> array1[i]) {
		++i;
	}
	cout << "File " << myfile << " have total character:" << counter << endl;
	cout << "File " << myfile1 << " have total character:" << i << endl;
	cout << "Common Character:" << endl << endl;
}
struct TrieNode {
	TrieNode* children[26]; // Here crete Child Node Array which store character from a to z
	bool isEndOfWord;

	TrieNode() {
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
		isEndOfWord = false;
	}
};
class WordSuggestion:public note_pad {// here inherit note pad class with wordsuggestion
private:
	TrieNode* root;

public:
	WordSuggestion() {
		root = new TrieNode();// here node are creted in construtor
	}

	~WordSuggestion() {// Destructor
		deleteTrie(root); // Here Deallocate the Trie nodes
	}

	void insertSuggestion(const string& suggestion) {// Function for Insert Suggestion which read from file 
		TrieNode* curr = root;
		if (suggestion[0] > 90) {
			for (char c : suggestion) {// execute for length of string
				int index = c - 'a'; // Map the character to an array index

				if (!curr->children[index]) {
					curr->children[index] = new TrieNode();
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = true;
		}
		else {
			for (char c : suggestion) {
				int index = c - 'A'; // Map the character to an array index

				if (!curr->children[index]) {
					curr->children[index] = new TrieNode();
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = true;
		}
	}

	void updateSuggestion(const string& suggestion) {// function for insert new suggestion in note pad
		TrieNode* curr = root;
		if (suggestion[0] > 90) {
			for (char c : suggestion) {
				int index = c - 'a';

				if (!curr->children[index]) {
					curr->children[index] = new TrieNode();
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = true;
		}
		else {
			for (char c : suggestion) {
				int index = c - 'A';

				if (!curr->children[index]) {
					curr->children[index] = new TrieNode();
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = true;
		}
	}

	void deleteSuggestion(const string& suggestion) {// function for delete suggesttion in Notepad
		TrieNode* curr = root;
		if (suggestion[0] > 90) {
			for (char c : suggestion) {
				int index = c - 'a';

				if (!curr->children[index]) {// Suggestion is Not Found
					cout << "Suggestion of this Word is Not Found" << endl;
					return;
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = false;
		}
		else {
			for (char c : suggestion) {
				int index = c - 'A';

				if (!curr->children[index]) {// Suggestion is Not Found
					cout << "Suggestion of this Word is Not Found" << endl;
					return;
				}
				curr = curr->children[index];
			}

			curr->isEndOfWord = false;
		}
	}

	string searchSuggestion(const string& suggestion) {// function for insert and find suggestion in Note Pad
		TrieNode* curr = root;
		int c1 = 0;
		if (suggestion[0] > 90) {
			for (char c : suggestion) {
				int index = c - 'a';
				++c1;
				if (!curr->children[index]) {
					//  suggestion can Not Found
					cout << "Suggestion Not Found" << endl;
					return " ";
				}
				curr = curr->children[index];
			}
			char *arr;
			int d = suggestion.length();
			arr = new char[d];
			for (int i = 0; i < c1; ++i) {
				arr[i] = suggestion[i];

			}
		}
		else {
			for (char c : suggestion) {
				int index = c - 'A';
				++c1;
				if (!curr->children[index]) {
					// suggestion can not found
					cout << "Suggestion Not Found" << endl;
					return " ";
				}
				curr = curr->children[index];
			}
			char *arr;
			int d = suggestion.length();
			arr = new char[d];
			for (int i = 0; i < c1; ++i) {
				arr[i] = suggestion[i];
				//note_pad::ADD_TEXT(ch,x,y);

			}
		}
		return suggestion;
	}

	void displaySuggestionsUtil(TrieNode* node, string& prefix) {// function display suggestion and find
		if (node->isEndOfWord) {
			std::cout << "- " << prefix << endl;
			system("COLOR 09");
		}
		if (prefix[0] > 90) {
			for (int i = 0; i < 26; i++) {
				if (node->children[i]) {
					char c = 'a' + i;
					prefix.push_back(c);
					displaySuggestionsUtil(node->children[i], prefix);
					prefix.pop_back();
				}
			}
		}
		else {
			for (int i = 0; i < 26; i++) {
				if (node->children[i]) {
					char c = 'A' + i;
					prefix.push_back(c);
					displaySuggestionsUtil(node->children[i], prefix);
					prefix.pop_back();
				}
			}
		}
	}

	void displaySuggestions(const string& prefix) {// function display suggestion
		TrieNode* curr = root;
		if (prefix[0] > 90) {
			for (char c : prefix) {
				int index = c - 'a';

				if (!curr->children[index]) {// Word Not exist in Suggestion
					cout << "Word " << prefix << " is Not Found." << endl;
					return;
				}
				curr = curr->children[index];
			}

			string suggestionPrefix = prefix;
			displaySuggestionsUtil(curr, suggestionPrefix);
		}
		else {
			for (char c : prefix) {
				int index = c - 'A';

				if (!curr->children[index]) {// Word Not exist in Suggestion
					cout << "Word " << prefix << " is Not Found." << endl;
					return;
				}
				curr = curr->children[index];
			}

			string suggestionPrefix = prefix;
			displaySuggestionsUtil(curr, suggestionPrefix);
		}
	}

	void deleteTrie(TrieNode* node) {// function delete all nodes
		if (node == nullptr) {
			return;
		}

		for (int i = 0; i < 26; i++) {
			deleteTrie(node->children[i]);
		}

		delete node;
	}
};
int  main()
{
	char ch;
	int x1, y1, x2, y2;
	string search;
	int choice;
	note_pad obj;
	WordSuggestion ttree;
	string ss = " ";
	ifstream wrote("outfile.txt");// here read data from file and insert 
	while (wrote >> ss)
	{
		ttree.insertSuggestion(ss);
	}
	wrote.close();
	bool flag = true;
	int a = 0;
	string str = "";
	system("color 0E");
	cout << "                        /////////////////////////////////////////////////////" << endl;
	cout << "                       ///                                               ///" << endl;
	cout << "                      ///     ------------------------------------      ///" << endl;
	cout << "                     ///     |     Welcome to Advance Note Pad    |    ///" << endl;
	cout << "                    ///       ------------------------------------    ///" << endl;
	cout << "                   ///                                               ///" << endl;
	cout << "                  /////////////////////////////////////////////////////" << endl;
	Sleep(4000);
	cout << endl;
	static int x = 0;
	static int y = 0;
	static int i = 0;
	do {
		system("COLOR 05");
		cout << "Press 1 For Add Text" << endl;
		cout << "Press 2 For Delete Text" << endl;
		cout << "Press 3 For Search Words" << endl;
		cout << "Press 4 For Copt Text" << endl;
		cout << "Press 5 For Paste Text" << endl;
		cout << "Press 6 For Replace a Words" << endl;
		cout << "Press 7 For Undo Text" << endl;
		cout << "Press 8 For Counts Total words" << endl;
		cout << "Press 9 For Word Suggestion" << endl;
		cout << "Press 10 For Save Text" << endl;
		cout << "Press 11 For Similarity Files" << endl;
		cout << "Press 12 For Display Text in NotePad" << endl;
		cout << "Press 13 For Exit...!" << endl;
		//Sleep(10000);
		cout << "Enter a Choice:";
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter Again:";
			cin >> choice;
		}
		system("cls");
		int k = 0;
		if (choice == 1) {
			system("COLOR 04");
			do
			{
				gotoxy(x, y);
				ch = _getche();

				if (ch == '~')
				{
					break;
				}
				obj.ADD_TEXT(ch, x, y);
			} while (true);
			system("cls");
		}
		else if (choice == 2) {
			obj.deleteText();
		}
		else if (choice == 3) {
			cout << "Enter a Word For Search:";
			cin >> search;
			obj.searchWord(search);
		}
		else if (choice == 4) {
			cout << "Enter a Start Position of X and Y (Row and Col):";
			cin >> x1 >> y1;
			if (x1 > x || y1 > y) {
				do {
					cout << "Enter Again Start Position of X and Y (Row and Col):";
					cin >> x1 >> y1;
				} while (x1 > x || y1 > y);
			}
			cout << "Enter a End Position of X and Y (Row and Col):";
			cin >> x2 >> y2;
			if (x2 > x || y2 > y) {
				do {
					cout << "Enter Again Start Position of X and Y (Row and Col):";
					cin >> x2 >> y2;
				} while (x2 > x || y2 > y);
			}
			obj.copy_Text(x1, y1, x2, y2);
		}
		else if (choice == 5) {
			obj.pasteText(y);
		}
		else if (choice == 6) {
			obj.find_and_Replace_Word();
		}
		else if (choice == 7) {
			obj.undo_Text();
		}
		else if (choice == 8) {
			obj.count_word_In_notepad();
		}
		else if (choice == 9) {
			int ch;
			string prefix;
			do {
				cout << "Press 1 For Find Suggestion of Any word" << endl;
				cout << "Press 2 For Update Suggestions" << endl;
				cout << "Press 3 for Delete Suggestion " << endl;
				cout << "Press 4 For Insert Suggestion in Note pad" << endl;
				cout << "Press 5 For Exit Suggestion Function" << endl;
				cout << "Enter a choice:";
				cin >> ch;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Enter Again:";
					cin >> ch;
				}
				system("COLOR 04");
				if (ch == 1) {
					cout << "Enter a Word For Suggestion:";
					cin >> prefix;
					bool r = false;
					int d = prefix.length();
					for (int i = 0; i < d; ++i) {
						if (prefix[i] > 64 && prefix[i] < 123) {
							r = false;
						}
						else {
							r = true;
							cout << "Only Word Suggestion you Can Find " << endl;
							break;
						}
					}
					if (r != true) {
						cout << "Suggestions of Given word" << prefix << " is:" << endl;
						ttree.displaySuggestions(prefix);
						cout << endl;
					}
				}
				else if (ch == 2) {
					cout << "Enter a Word:";
					cin >> prefix;
					bool r = false;
					int d = prefix.length();
					for (int i = 0; i < d; ++i) {
						if (prefix[i] > 64 && prefix[i] < 123) {
							r = false;
						}
						else {
							r = true;
							cout << "Only Word Suggestion you Can Update " << endl;
							break;
						}
					}
					if (r != true) {
						ttree.updateSuggestion(prefix);
					}
				}
				else if (ch == 3) {
					cout << "Enter a Word Which You Want to Delete from Suggestion:";
					cin >>prefix;
					ttree.deleteSuggestion(prefix);
				}
				else if (ch == 4) {
					cout << "Enter a Word Which You insert in Note Pad from Suggestion:";
					cin >> prefix;
					string s=ttree.searchSuggestion(prefix);
					cout << s << endl;
					int z = s.length();
					obj.ADD_TEXT(' ', x, y);
					for (int i = 0; i < z; ++i) {
						obj.ADD_TEXT(s[i], x, y);
					}
				}
				else if (ch == 5) {
					break;
				}
				else {
					cout << "Invalid Input..!" << endl;
				}
			} while (true);
			system("cls");
		}
		else if (choice == 10) {
			obj.saveText();
		}
		else if (choice == 11) {
		obj.similarties_two_file();
		}
		else if (choice == 12) {
			cout << "     Text in Not Pad is   " << endl;
			system("COLOR 09");
			obj.display();
			Sleep(5000);
			system("cls");
		}
		else if (choice == 13) {
			cout << "Succesfully Exit...!" << endl;
		}
		else {
			cout << "Invalid Choice...!" << endl;
		}
	} while (choice != 13);
	cout << endl;
	system("pause");
	return 0;
}