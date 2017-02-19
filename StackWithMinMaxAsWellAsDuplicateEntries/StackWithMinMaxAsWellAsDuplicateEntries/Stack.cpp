#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	number_of_elements_in_stack = 0;
	number_of_unique_elements_in_stack = 0;
	max = 0;
	min = 0;

	Initialize_Arrays();
}

void Stack::Initialize_Arrays()
{
	for(int i = 0; i < STACK_SIZE; i++)
	{
		values_array[i] = 0;
		unique_elements_array[i] = 0;
		number_of_unique_elemets_array[i] = 0;
	}
}

void Stack::Push(unsigned int element)
{
	Determine_Max_Min(element);

	if(Is_Element_Unique(element))
		Update_Unique_Elements_Array_Push(element);

	values_array[number_of_elements_in_stack] = element;
	number_of_elements_in_stack++;
}

void Stack::Determine_Max_Min(unsigned int element)
{
	if(number_of_elements_in_stack == 0)
	{
		max = element;
		min = element;
	}

	if(element > max)
		max = element;

	if(element < min)
		min = element;
}

bool Stack::Is_Element_Unique(unsigned int element)
{
	bool isNew = true;
	for(int i = 0; i < number_of_unique_elements_in_stack; i++)
	{
		if(unique_elements_array[i] == element)
		{
			isNew = false;
			number_of_unique_elemets_array[i]++;
			return isNew;
		}
	}

	return isNew;
}

void Stack::Update_Unique_Elements_Array_Push(unsigned int element)
{
	unique_elements_array[number_of_unique_elements_in_stack] = element;
	number_of_unique_elemets_array[number_of_unique_elements_in_stack]++;
	number_of_unique_elements_in_stack++;
}

void Stack::Pop()
{
	unsigned int element_to_be_poped = values_array[number_of_elements_in_stack - 1];

	unsigned int occurance_of_element_to_be_poped = Occurance_Of_Element(element_to_be_poped);

	if(occurance_of_element_to_be_poped == 1)
	{
		Update_Unique_Elements_Array_Pop(element_to_be_poped);
		Update_Max_Min();
	}

	else
	{
		for(int i = 0; i < number_of_unique_elements_in_stack; i++)
		{
			if(unique_elements_array[i] == element_to_be_poped)
				number_of_unique_elemets_array[i] -- ;
		}
	}

	values_array[number_of_elements_in_stack -1] = 0;
	number_of_elements_in_stack--;
}

unsigned int Stack::Occurance_Of_Element(unsigned int element)
{
	int occurance = 0;
	for(int i = 0; i < number_of_unique_elements_in_stack; i++)
	{
		if(unique_elements_array[i] == element)
		{
			occurance = number_of_unique_elemets_array[i];
			break;
		}
	}

	return occurance;
}

void Stack::Update_Max_Min()
{
	if(number_of_unique_elements_in_stack == 0)
	{
		max = 0;
		min = 0;
		return;
	}

	unsigned int current_min = unique_elements_array[0];
	unsigned int current_max = unique_elements_array[0];

	for(int i = 0; i < number_of_unique_elements_in_stack; i ++)
	{
		if(current_min > unique_elements_array[i])
			current_min = unique_elements_array[i];

		if(current_max < unique_elements_array[i])
			current_max = unique_elements_array[i];
	}

	min = current_min;
	max = current_max;
}

void Stack::Update_Unique_Elements_Array_Pop(unsigned int element)
{
	for(int i = 0; i < number_of_unique_elements_in_stack; i ++)
	{
		if(unique_elements_array[i] == element)
		{
			unique_elements_array[i] = unique_elements_array[number_of_unique_elements_in_stack-1];
			number_of_unique_elemets_array[i] = number_of_unique_elemets_array[number_of_unique_elements_in_stack-1];
			number_of_unique_elements_in_stack --;
			break;
		}
	}
}