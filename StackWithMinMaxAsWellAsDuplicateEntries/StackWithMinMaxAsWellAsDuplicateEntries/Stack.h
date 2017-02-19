#define STACK_SIZE 50

class Stack
{
	unsigned int values_array[STACK_SIZE];
	unsigned int unique_elements_array[STACK_SIZE];
	unsigned int number_of_unique_elemets_array[STACK_SIZE];

	unsigned int number_of_elements_in_stack;
	unsigned int number_of_unique_elements_in_stack;

	unsigned int max;
	unsigned int min;

public:
	Stack();
	void Push(unsigned int element);
	void Pop();

	unsigned int Get_Max(){return max;};
	unsigned int Get_Min(){return min;};
	unsigned int Get_Stack_Count(){return number_of_elements_in_stack;};
	unsigned int Get_Unique_Count(){return number_of_unique_elements_in_stack;};

private:
	void Initialize_Arrays();
	void Determine_Max_Min(unsigned int element);
	bool Is_Element_Unique(unsigned int element);
	void Update_Unique_Elements_Array_Push(unsigned int element);

	unsigned int Occurance_Of_Element(unsigned int element);
	void Update_Max_Min();
	void Update_Unique_Elements_Array_Pop(unsigned int element);
};