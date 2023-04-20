class Stack
{
	private:
		int m_capacity;
		int m_index;
		int* array;
       public:
		//Constructor
		Stack(int size);
		
		//Destructor
		~Stack();
		
		//Return the size of the stack
		int get_size();
		
		//Check that stack is empty
		bool is_empty();

		//Check that stack is full
		bool is_full();
                
		//Add an element to the top of the stack
		void push(int item);

		//Remove and return the top element from the stack
		int pop();

		//Return the top element in the stack without removing it
		int top();

};
