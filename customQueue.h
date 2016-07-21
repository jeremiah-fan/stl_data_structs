// Templated singly linked list with head and tail pointer implementation of queue

template <typename Item>
class myQueue {
public:
	/* Constructor and Destructors */
	myQueue(); // Default and only constructor
	~myQueue(); // Default and only destructor

	/* Setter Methods */
	void push(Item item); // Push an item to the end of the queue
	Item pop(); // Return and remove the item at the front of the queue

	/* Getter Methods*/
	Item front(); // Return the item at the front of the queue
	Item back(); // Return the item at the end of the queue
	bool empty(); // Return true if the queue is empty, false otherwise
	int size(); // Return the number of items in the queue

private:
	struct Node {
		Item item;
		Node* next;
	};

	Node* m_front;
	Node* m_back;
	int m_size;
};

/* Constructor */

template <typename Item>
myQueue<Item>::myQueue() {
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

/* Destructor */

template <typename Item>
myQueue<Item>::~myQueue() {
	while (m_front->next != nullptr) {
		Node* temp = m_front;
		m_front = m_front->next;
		delete temp;
	}
	delete m_front;
}

/* Setter Methods */

template <typename Item>
void myQueue<Item>::push(Item item) {
	Node* node = new Node;
	node->item = item;
	node->next = nullptr;
	
	if (m_back == nullptr)
		m_front = node;
	else
		m_back->next = node;
	m_back = node;
	m_size++;
}

template <typename Item>
Item myQueue<Item>::pop() {
	try {
		if (empty())
			throw 2;
	}
	catch (int e) {
		cout << "ERROR (#" << e << "): method pop called on empty queue." << endl;
		exit(1);
	}

	Node* temp = m_front;
	Item ret = temp->item;
	m_front = m_front->next;
	delete temp;
	m_size--;
	return ret;
}

/* Getter Methods */

template <typename Item>
Item myQueue<Item>::front() {
	try {
		if (empty())
			throw 2;
	}
	catch (int e) {
		cout << "ERROR (#" << e << "): method front called on empty queue." << endl;
		exit(1);
	}
	return m_front->item;
}

template <typename Item>
Item myQueue<Item>::back() {
	try {
		if (empty())
			throw 2;
	}
	catch (int e) {
		cout << "ERROR (#" << e << "): method back called on empty queue." << endl;
		exit(1);
	}
	return m_back->item;
}

template <typename Item>
bool myQueue<Item>::empty() {
	return m_front == nullptr;
}

template <typename Item>
int myQueue<Item>::size() {
	return m_size;
}