#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZE 9
#define LIST_LEN 10
#define UPPER_RAND 100

typedef int Data;

typedef struct node
{
	Data data;
	struct node* next;
	struct node* prev;
	char used; 
}Node;

typedef Node* List;

int is_empty(const List list);

void add_first(List* list, const Data data);

int is_sorted_list(const List list);

void print_list(const List list);

void random_list(List* list);

void random_array(int* array);

void bubble_sort(List* list);

List create_empty_list(void);

void swap_nodes(List* list, List node1, List node2);

void merge_sort(int array[], int start, int end);

void print_array(int array[]);

void merge(int* array, int start, int middle, int end);

void quick_sort(int* array, int low, int high);



#endif