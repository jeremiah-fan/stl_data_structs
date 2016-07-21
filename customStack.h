// Templated singly linked list implementation of stack

template <typename Item>
class myStack {
public:
	myStack(); //Default and only constructor
	~myStack(); //Default and only destructor
	void push(Item item); //Adds an element to the top of the stack
	Item pop(); //Returns and removes the top of the stack
	Item top(); //Returns the top of the stack
	bool empty(); //Returns true if stack is empty, false otherwise
	int size(); //Returns number of items in the stack

private:
	struct Node {
		Item item;
		Node* next;
	};

	Node* m_top;
	int m_size;
};

// Constructor
template <typename Item>
myStack<Item>::myStack() {
	m_top = nullptr;
	m_size = 0;
}

// Destructor
template <typename Item>
myStack<Item>::~myStack() {
	while (m_top->next != nullptr) {
		Node* temp = m_top;
		m_top = m_top->next;
		delete temp;
	}
	delete m_top;
}

// Setter Methods
template <typename Item>
void myStack<Item>::push(Item item) {
	Node* node = new Node;
	node->item = item;
	node->next = m_top;
	m_top = node;
	m_size++;
}

template <typename Item>
Item myStack<Item>::pop() {
	try {
		if (empty())
			throw 2;
	}
	catch (int e) {
		cout << "ERROR (#" << e << "): method pop called on empty stack." << endl;
		exit(1);
	}

	Node* temp = m_top;
	Item ret = temp->item;

	m_top = m_top->next;
	delete temp;
	m_size--;
	return ret;
}

// Getter Methods
template <typename Item>
Item myStack<Item>::top() {
	try {
		if (empty())
			throw 2;
	}
	catch (int e) {
		cout << "ERROR (#" << e << "): method top called on empty stack." << endl;
		exit(1);
	}

	return m_top->item;
}

template <typename Item>
bool myStack<Item>::empty() {
	return m_top == nullptr;
}

template <typename Item>
int myStack<Item>::size() {
	return m_size;
}
