#include<iostream>
#include<functional>

//declaration of all the funtions used 

static void display(int* array, int size);

void displayText(char* string);

std::tuple<int*, int> newArray();

int* enterDataToArray(int* array, int size);

static int selection();

int* quickSort(int* array, int size,int p, int q);

int* swap(int* array,int p, int q);

void main()	//the main funtion
{
	int size;		//stores the size of the array
	int select;			//the selection variable 
	int* array = nullptr;		//the main array 
	bool exit = false;

	while (!exit)
	{
		select = selection();
		
		switch (select)
		{
		case 1:
		{
			std::tuple<int*, int> sources = newArray();		//tuple is used to receve the data from the funtion
			array = std::get<0>(sources);		//extraction of the data from the tuple 
			size = std::get<1>(sources);
			display(array, size);

			break;
		}
		case 2:
		{
			
			array = quickSort(array, size, 0, size - 1);

			display(array, size);
			
			break;
		}
		case 3:
			exit = true;
			break;
		default:
			break;
		}
	}
}

static int selection()		//does the selection
{
	int select;

	displayText("Enter your choice");
	displayText("New Array -----> 1");
	displayText("Sort Array ----> 2");
	displayText("Exit ----------> 3");

	std::cin >> select;

	return (select);
}

int* quickSort(int* array, int size,int p,int q)
{
	int flag = 0;
	int* temparrayofindex = new int[size];
	memset(temparrayofindex, -1, size);
	int count = 0;
	int exit = 0;
	int beg = 0;
	int end = size-1;
	while (!exit)
	{
		for (int i = 0; i < size; i++)
		{
			if (q == temparrayofindex[i])
			{
				if (p < q)
				{
					q--;
				}
				else
				{
					q++;
				}
				flag = 1;
			}
			if (p == temparrayofindex[i])
			{
				p++;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			continue;
		}
		if (p == q)			//the traversal for that particular item is over 
		{
			temparrayofindex[count] = p;
			p = beg;
			q = end;
			count++;
			if (count == size)	//if all the items are in there respective positions 
			{
				return(array);
			}
			continue;
		}
		if ((p - q)*(array[p] - array[q]) < 0)		//if array[p] and array[q] are opposite to there value and possition
		{
			array = swap(array, p, q);
			if (p < q)
			{
				int temp = q;
				q = p + 1;
				p = temp;
			}
			else
			{
				int temp = q;
				q = p - 1;
				p = temp;
			}
			continue;
		}
		if (p < q)	//if nothing changed in the loop
		{
			q--;
		}
		else
		{
			q++;
		}
	}
}

int* swap(int* array, int p, int q)	//swaps the elements at p and q in the array
{
	int temp = array[p];
	array[p] = array[q];
	array[q] = temp;
	return(array);
}

std::tuple<int*,int> newArray()		//creates an array and returns the array and its size 
{
	int size;

	std::cout << "Enter the size of the array:";
	std::cin >> size;

	int* array = new int[size];
	memset(array, 0, size);
	
	array = enterDataToArray(array, size);
	
	return std::make_pair(array, size);
}

int* enterDataToArray(int* array, int size)		//allows the user to input the values to the array
{
	std::cout << "Enter the array:";
	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}
	return(array);
}

static void display(int* array, int size) //displays the array
{
	if (array)		//if array is not a nullptr
	{
		int i = 0;
		std::cout << "[";
		for (; i < size; i++)
		{
			std::cout << array[i]<<" ";
		}
		std::cout << "]";
		std::cout << std::endl;
	}
}

void displayText(char* string)	//displaying the text 
{
	std::cout << string <<std::endl;
}
