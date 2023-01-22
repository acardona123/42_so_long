/*
clear && gcc -Werror -Wextra -Wall -g tests/test_garbage_collector.c -o test srcs/garbage_collector.c && valgrind --leak-check=full  ./test && rm test
*/

#include "../includes/so_long.h"

#include <stdio.h>

// int main(void)
// {
// 	int	*ptr1;
// 	int	*ptr2;
// 	int	*ptr3;
// 	t_list	*garbage;

// 	garbage = 0;
// 	ptr1 = 0;
// 	ptr2 = 0;
// 	ptr3 = 0;
// 	printf("Premier malloc : \n");
// 	ft_my_malloc(&garbage, (void **)&ptr1, sizeof(int));
// 	printf("\nDeuxieme malloc : \n");
// 	ft_my_malloc(&garbage, (void **)&ptr2, sizeof(int));
// 	printf("\nTroisieme malloc : \n");
// 	ft_my_malloc(&garbage, (void **)&ptr3, 2 * sizeof(int));

// 	*ptr1 = 3;
// 	*ptr2 = 4;
// 	*ptr3 = 4;

// 	printf("\nApres malloc :\nptr1 : %p\nptr2 : %p\n", ptr1, ptr2);
// 	printf("garbage : %p (content : %p)\ngarbage->next : %p (content : %p)\n", garbage, garbage->content, garbage->next, garbage->next->content);
// 	printf("Reste avant free one : %p, %p\n\n", garbage, garbage->next);

// 	// ft_garbage_free_one(&garbage, (void *)ptr1);
// 	// ft_garbage_free_one(&garbage, (void *)ptr2);
// 	ft_garbage_free_one(&garbage, (void *)ptr3);

// 	printf("Reste apres free one : %p, %p\n", garbage, NULL);
// 	ft_garbage_free(&garbage, 0);
// 	return (0);
// }


int main(void)
{
	t_global	gl;
	int	*ptr1;
	int	*ptr2;
	int	*ptr3;

	gl.garb_group = 0;
	ptr1 = 0;
	ptr2 = 0;
	ptr3 = 0;
	gl.garb_img = 0;
	gl.garb_win = 0;
	gl.garb_ptr = 0;
	gl.garb_img = ft_garbage_init(&gl.garb_group, free);
	gl.garb_win = ft_garbage_init(&gl.garb_group, free);
	gl.garb_ptr = ft_garbage_init(&gl.garb_group, free);

	printf("Premier malloc : \n");
	ft_my_malloc(gl.garb_img, (void **)&ptr1, sizeof(int));
	printf("\nDeuxieme malloc : \n");
	ft_my_malloc(gl.garb_img, (void **)&ptr2, sizeof(int));
	printf("\nTroisieme malloc : \n");
	ft_my_malloc(gl.garb_img, (void **)&ptr3, 2 * sizeof(int));

	*ptr1 = 3;
	*ptr2 = 4;
	*ptr3 = 4;

	// printf("\nApres malloc :\nptr1 : %p\nptr2 : %p\n", ptr1, ptr2);
	// printf("garbage : %p (content : %p)\ngarbage->next : %p (content : %p)\n", gl.garb_img, gl.garb_img->first->content, gl.garb_img->next, gl.garb_img->next->content);
	// printf("Reste avant free one : %p, %p\n\n", gl.garb_img, gl.garb_img->next);


	ft_garbage_group_free(&gl.garb_group, 0);
	// ft_garbage_free_one(&gl.garb_img, (void *)ptr1);
	// ft_garbage_free_one(&gl.garb_img, (void *)ptr2);
	//ft_garbage_free_one(gl.garb_img, (void *)ptr3);
	// printf("Reste apres free one : %p, %p\n", gl.garb_img, NULL);
	//ft_garbage_free(gl.garb_img, 0);
	return (0);
}
