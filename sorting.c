#include "sorting.h"

static void free_node(List to_remove)
{
	to_remove->prev = NULL;
	to_remove->next = NULL;
	to_remove->data = 0;
	to_remove->used = 0;
}

List create_empty_list(void)
{
	return NULL;
}

static Node* get_node()
{
	static int init = 0; 		//eftersom init ar statisk sa kommer den bara fa startvardet 0 vid forsta anropet av get_node, detta upprepas inte vid senare anrop
	static Node list[LIST_LEN];

	if (init == 0)					//kors forsta gangen get_node anropas for att "nollstalla" samtliga noder
	{
		for (int i = 0; i < LIST_LEN; i++)
		{
			free_node(&list[i]);
		}
		init = 1;
	}

	for (int i = 0; i < LIST_LEN; i++)
	{
		if (list[i].used == 0)
		{
			list[i].used = 1;
			return &list[i];
		}
	}

	return NULL;
}

static Node* create_list_node(const Data data)
{
	static Node* newNode;
	newNode = get_node();
	if (newNode != NULL)
	{
		newNode->data = data;
		return newNode;
	}
	else {
		// Do something about it.
	}
}

int is_empty(const List list)
{
	for (int i = 0; i < LIST_LEN; i++)
	{
		if (list[i].used == 0)
		{
			return 1;
		}
		else {
			break;
		}
		return 0;
	}
}

void add_first(List* list, const Data data)
{
	static Node* newNode;
	newNode = create_list_node(data);
	if (*list != NULL && newNode != NULL)
	{
		newNode->next = *list;
		newNode->next->prev = newNode;
		*list = newNode;
	}
	else if (*list == NULL && newNode != NULL)
	{
		*list = newNode;
	}
}

void print_list(const List list)
{
	List temp = list;
	if (list == NULL)
	{
		printf("The list is empty\n");
	}
	else if (temp->next == NULL) {
		printf("%d\n", temp->data);
		//nrfx_uarte_tx(&instance, temp->data, sizeof(temp->data), 0);
	}
	else {
		printf("%d\n", temp->data);
		//nrfx_uarte_tx(&instance, temp->data, sizeof(temp->data), 0);
		print_list(temp->next);
	}

}

int is_sorted_list(const List list)
{
	if (list != NULL)
	{
		if (list->next != NULL && list->data <= list->next->data)
		{
			is_sorted_list(list->next);
		}
		else if (list->next == NULL)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
}

int is_sorted_array(int* array)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] > array[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

void random_list(List* list)
{
	for (int i = 0; i < LIST_LEN; i++)
	{
		add_first(list, rand() % UPPER_RAND);
	}
}

void random_array(int* array)
{
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % UPPER_RAND;
	}
}

void bubble_sort(List* list)
{
	while (is_sorted_list(*list) == 0)
	{
		List temp = *list;
		for (int i = 0; i < LIST_LEN; i++)
		{
			if(temp->next != NULL)
			{

				if (temp->data > temp->next->data)
				{
					swap_nodes(&(*list), temp, temp->next);
				}
				if(temp->next != NULL)
				{ 
					temp = temp->next;
				}
			}
			else {
				break;
			}
		}
	}
}

void swap_nodes(List* list, List node1, List node2) 
{
	if (node1->prev == NULL && node1->next != NULL && node1->next->next != NULL) // Swap first and second in list, theres a third node
	{
		node1->next = node2->next;
		node2->prev = NULL;
		node1->prev = node2;
		node2->next = node1;
		node1->next->prev = node1;
		*list = node2;
	}
	else if (node1->prev == NULL && node1->next != NULL && node2->next == NULL) // Swap first and second in list, only two nodes
	{
		node1->next = NULL;
		node2->prev = NULL;
		node1->prev = node2;
		node2->next = node1;
		*list = node2;
	}
	else if (node1->prev != NULL && node1->next != NULL && node2->next != NULL) // Swap two nodes in middle of list
	{
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;

		node1->next->prev = node1;
		node2->prev->next = node2;
	}
	else if (node1->prev != NULL && node1->next != NULL && node2->next == NULL) // Swap last two nodes 
	{
		node1->next = NULL;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;

		node2->prev->next = node2;
	}
}

void print_array(int array[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\n", array[i]);
	}
}

void merge_sort(int array[], int start, int end)
{
	if (start < end)
	{
		int middle = 1 + (end - 1) / 2;

		merge_sort(array, start, middle);
		merge_sort(array, middle + 1, end);

		merge(&array, start, middle, end);
	}
	
}

void merge(int* array, int start, int middle, int end)
{
	int left_length = middle - start + 1;
	int right_length = end - middle;

	//int left_array[left_length];
}

void quick_sort(int* array, int low, int high) // Low is first index and high is last index
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		quick_sort(array, low, pivot - 1); // Sorts side to the left of pivot
		quick_sort(array, pivot + 1, high); // Sorts side to the right of pivot
	}
}

static void swap_numbers(int* num1, int* num2)
{
	int temp_num;
	temp_num = *num1;
	*num1 = *num2;
	*num2 = temp_num;
}

static int partition(int array[], int low, int high) // Low is first index and high is last index
{
	int pivot = array[high];

	int i = (low - 1);

	for (int j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_numbers(&array[i], &array[j]);
		}
	}
	swap_numbers(&array[i + 1], &array[high]);
	return (i + 1);
}