class Node
{
	public:
		int data;
		Node* next;
                
		//Constructor that to built new node wiht given data
	        Node(int value);
};

class Stack
{
      public:
	        Node* m_top;
	        int m_size;
	      
	        //Constructor
	        Stack();
		
		//Destructor
		~Stack();
		
		//Return the size of the stack
		int get_size();
		
		//Check that stack is empty
		bool is_empty();

	
		//Add an element to the top of the stack
		void push(int value);

		//Remove and return the top element from the stack
		int pop();

		//Return the top element in the stack without removing it
		int top();
};
