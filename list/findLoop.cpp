#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int value;
	Node* next;

	Node(int val) : value(val), next(nullptr) {}
};

// Declaration of Map to keep
// mark of visited Node
map<Node*, bool> vis;
bool flag = 0;
 
bool tortoiseAndHare(Node* head)
{
    if (head == nullptr)
	{
        return false;
    }
	
	bool isFirstEntry = true;
	Node* tortoise = head;
	Node* hare = head;
	while(tortoise != hare || isFirstEntry)
	{
		if(isFirstEntry)
		{
			isFirstEntry = false;
		}

		tortoise = tortoise->next;
		if(tortoise == nullptr)
		{
			return false;
		}

		hare = hare->next;
		if(hare == nullptr)
		{
			return false;
		}
		else
		{
			hare = hare->next;
			if(hare == nullptr)
			{
				return false;
			}
		}
	}

//	std::cout << "INFO: Tortoise and hare met at node with value " << tortoise->value << std::endl;
	return true;
}

int main()
{
	int n;
	std::cin >> n;	// Set list size

	std::cout << "Should there be a loop? (Type Y or N for Yes and No, respectively) " << std::endl;
	char tmpChar;
	cin >> tmpChar;
	bool addLoop = (tmpChar == 'Y');

	srand(time(0));
	vector<int> values;
    Node* head = new Node(rand());
	values.push_back(head->value);

    Node* tail = head;
	for(int i=1; i < n; ++i)
	{
		int newVal = rand();
		values.push_back(newVal);
		tail->next = new Node(newVal);
		tail = tail->next;
	}

	if(addLoop)
	{
		int indexToLoopNodeDestination = rand() % values.size();
		Node *tmp = head;
		while(tmp && tmp->value != values[indexToLoopNodeDestination])
		{
			tmp = tmp->next;
		}
//		std::cout << "INFO: Adding loop node from tail to value " << values[indexToLoopNodeDestination] << std::endl;
		tail->next = tmp;
	}
 
    // Function that detect cycle in
    // Linked List
	bool result = tortoiseAndHare(head);

    if (result)
        cout << "Loop detected.";
    else
        cout << "No loop was found.";
    cout << endl;
 
    return 0;
}
