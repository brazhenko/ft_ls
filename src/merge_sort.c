/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:27:02 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/01/22 16:20:26 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft_ls.h"

//struct s_file
//{
//	int data;
//	struct s_file *next, *prev;
//};

//static int 		data_comparator(t_file *left, t_file *right)
//{
//	if (left->data > right->data)
//		return (1);
//	else
//		return (0);
//}

struct s_file *split(struct s_file *head);

struct s_file *merge(struct s_file *first, struct s_file *second, int (*f)(t_file *, t_file *))
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (f(first, second))
	{
		first->next = merge(first->next,second, f);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first,second->next, f);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}



// A utility function to insert a new node at the
// beginning of doubly linked list
int insert(struct s_file **head, char *name, char *full_name, t_all *all)
{
	int		total;

	//тут был пункт temp->data = 5, убрал его нахуй, вообще не понимаю зачем он нужен был(
	struct s_file *temp =
			(struct s_file *)malloc(sizeof(struct s_file));
	temp->next = temp->prev = NULL;
	temp->name = name;
	stat(ft_strjoin(ft_strjoin(full_name, "/"), name), &temp->dir_stat);
	// <вычисление максимальной длинны>
	if (all->len_count_sym < ft_strlen(ft_itoa(temp->dir_stat.st_nlink)))
		all->len_count_sym = ft_strlen(ft_itoa(temp->dir_stat.st_nlink));
	if (all->len_name < ft_strlen(getpwuid(temp->dir_stat.st_uid)->pw_name))
		all->len_name = ft_strlen(getpwuid(temp->dir_stat.st_uid)->pw_name);
	// </вычисление максимальной длинны>
	if (temp->name[0] == '.' && !all->flags['a'])
		total = 0;
	else
		total = temp->dir_stat.st_blocks;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
	return total;
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
struct s_file *mergeSort(struct s_file *head, int (*f)(t_file *, t_file *))
{
	if (!head || !head->next)
		return head;
	struct s_file *second = split(head);

	// Recur for left and right halves
	head = mergeSort(head, f);
	second = mergeSort(second, f);

	// Merge the two sorted halves
	return merge(head,second, f);
}

 //Driver program

//int main(void)
//{
//	struct s_file *head = NULL;
//	insert(&head,30, NULL, NULL);
//	insert(&head,5, NULL, NULL);
//	insert(&head,20, NULL, NULL);
//	insert(&head,4, NULL, NULL);
//	insert(&head,3, NULL, NULL);
//	insert(&head,10, NULL, NULL);
//	insert(&head,30, NULL, NULL);
//	insert(&head,5, NULL, NULL);
//	insert(&head,20, NULL, NULL);
//	insert(&head,4, NULL, NULL);
//	insert(&head,3, NULL, NULL);
//	insert(&head,10, NULL, NULL);
//	insert(&head,30, NULL, NULL);
//	insert(&head,5, NULL, NULL);
//	insert(&head,20, NULL, NULL);
//	insert(&head,4, NULL, NULL);
//	insert(&head,3, NULL, NULL);
//	insert(&head,10, NULL, NULL);
//	insert(&head,30, NULL, NULL);
//	insert(&head,5, NULL, NULL);
//	insert(&head,20, NULL, NULL);
//	insert(&head,4, NULL, NULL);
//	insert(&head,3, NULL, NULL);
//	insert(&head,10, NULL, NULL);
//
//	print(head);
//	printf("\n___________________________");
//
//	head = mergeSort(head, &data_comparator);
//	printf("\n\nLinked List after sorting\n");
//	print(head);
//	return 0;
//}
