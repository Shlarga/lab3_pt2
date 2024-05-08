#include "sorting.h"

int main()
{
	srand(time(NULL));
	List head = create_empty_list();
	int array[SIZE];

	// Bubble sorting List code

	/*random_list(&head);
	print_list(head);
	printf("Head: %d\n", head->data);
	bubble_sort(&head);
	printf("\nBubble sorting\n");
	printf("\nHead: %d\n\n", head->data);
	print_list(head);*/

	// Merge sorting Array code

	/*random_array(&array);
	print_array(&array);
	const int length = strlen(&array);
	merge_sort(&array, 0, length);*/

	// Quick sorting Array code

	random_array(array);
	print_array(array);
	int n = sizeof(array) / sizeof(array[0]);
	quick_sort(array, 0, n-1); // n-1 because element of array
	printf("\n");
	printf("Quick sorting");
	printf("\n\n");
	print_array(array);

	
}