/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/19 06:09:42 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

struct s_file
{
	int data;
	struct s_file *next, *prev;
};

struct s_file *split(struct s_file *head);

struct s_file *merge(struct s_file *first, struct s_file *second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (first->data < second->data)
	{
		first->next = merge(first->next,second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first,second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}



// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct s_file **head, int data)
{
	struct s_file *temp =
			(struct s_file *)malloc(sizeof(struct s_file));
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// A utility function to print a doubly linked list in
// both forward and backward directions
void print(struct s_file *head)
{
	struct s_file *temp = head;
	printf("Forward Traversal using next poitner\n");
	while (head)
	{
		printf("%d ",head->data);
		temp = head;
		head = head->next;
	}
	printf("\nBackward Traversal using prev pointer\n");
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct s_file *split(struct s_file *head)
{
	struct s_file *fast = head,*slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	struct s_file *temp = slow->next;
	slow->next = NULL;
	return temp;
}

// Function to do merge sort
struct s_file *mergeSort(struct s_file *head)
{
	if (!head || !head->next)
		return head;
	struct s_file *second = split(head);

	// Recur for left and right halves
	head = mergeSort(head);
	second = mergeSort(second);

	// Merge the two sorted halves
	return merge(head,second);
}

// Driver program
int main(void)
{
	struct s_file *head = NULL;
	insert(&head,5);
	insert(&head,20);
	insert(&head,4);
	insert(&head,3);
	insert(&head,30);
	insert(&head,10);
	head = mergeSort(head);
	printf("\n\nLinked List after sorting\n");
	print(head);
	return 0;
}