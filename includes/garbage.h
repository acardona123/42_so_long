/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:56:53 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 01:41:03 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H
# include <stdlib.h>

typedef struct s_garb_list
{
	void				*content;
	struct s_garb_list	*next;
}	t_garb_list;

typedef struct s_garb_del_arg
{
	void	*arg1;
	void	*arg2;
	void	*arg3;
}	t_garb_del_arg;

typedef struct s_garbage
{
	t_garb_list		**parent_group;
	void			(*del_function)(t_garb_del_arg *, void *to_free);
	t_garb_del_arg	*del_arg;
	t_garb_list		*first;
}	t_garbage;

typedef struct s_garbage_resume
{
	t_garb_list		*gbgroup;
	t_garbage		*gbptr;
	t_garbage		*gbimg;
	t_garbage		*gbwin;
	t_garbage		*gbxvar;
}	t_garbage_resume;

/*
 garbage_collector_build0_groups */
void			ft_garbage_group_init(t_garbage_resume *garb_lst);
t_garb_del_arg	*ft_garbage_del_arg_init(t_garbage_resume *garb_lst, void *arg1,
					void *arg2, void *arg3);
void			ft_garbage_group_add_garb(t_garb_list **group, t_garbage *garb);
int				ft_garbage_group_free(t_garb_list **group, int error_exit);
/*
 garbage_collector_build1_units*/
t_garbage		*ft_garbage_special_init(t_garbage_resume *garb_lst,
					t_garb_del_arg *del_args,
					void (*del_function)(t_garb_del_arg *, void *to_free));
int				ft_garbage_free_one(t_garbage *garb, void *content_target);
int				ft_garbage_free(t_garbage *garb, int error_exit);
int				ft_garbage_add(t_garbage *garb, void *ptr);
int				ft_my_malloc(t_garbage *garb, void **dst, size_t size);
/*
 garbage_collector_free_ftn.c */
void			ft_garbage_del_gbptr(t_garb_del_arg *args, void *to_del);
void			ft_garbage_del_gbxvar(t_garb_del_arg *args, void *to_del);
void			ft_garbage_del_gbimg(t_garb_del_arg *args, void *to_del);
void			ft_garbage_del_gbwin(t_garb_del_arg *args, void *to_del);
/*
 garbage_collector_init.c 
 cf so_long.h*/

#endif

/*Process to inittialise and use the garbage :

*/
/* == INITIALISATION == */
/*1) include garbage_h*/
/*2) in garbage_h modify s_garbage_resume :*/
/*  - you must keep the gbgroup (will list all the garbages) and the garbage */
/*  gbptr (garbagefor simple pointers to free with free() )*/
/*  - add one t_garbage* for each different family of malloced pointer */
/*  (requiering differentfree functions).*/
/*3) Apply ft_garbage_group_init to this structure element. It will initilise */
/*  the garbage gbptr presented previously */
/*4) To crate a new garbage family :*/
/*   (will generate and complete a new t_garbage elem and add it to the*/
/*   garbagelist in s_garbage_resume)*/
/*  4.1) build the function used to free an element of the family in */
/*	 garbage_collector_2_free_ftn, it must be prototyped as following :*/
/*           void	ft_del(t_garb_del_arg *del_args, void *ptr_to_del); */
/*  4.2) Add the prototypes of these functions to this header file*/
/*	4.3) use ft_garbage_del_arg_init to build args, the structure element */
/*	     containing the missing parameters for ft_del. */
/*	4.4) use ft_garbage_special_init with previously builded parameters, */
/*		 the return correspond to the t_garbage* of this garbage in */
/*		 t_garbage_resume  

*/
/* == USES == */
/* /!\ Any pointer malloced before the use of the garbage has to be freed */
/* before the garbage usage (or leak in case of crash).*/
/* # To malloc a pointer : */
/*	If you will free it immediatly and before any other malloc : use */
/*	  malloc as usualy; if fail execute ft_garbage_group_free(..., 1).*/
/*	If you won't free it immediatly and want to save it for later free:*/
/*   - check what method will be requiered to free it (ex : special if struct)*/
/*     , deduce from it which garbage of t_garbage_resume it must go in.*/
/*	 - all garbages should be initialised at the begginning of the program but*/
/*	   if needed create a new garbage (cf initialisation 4.))*/
/*	 - use :
		ft_my_malloc(targeted_garbage, your_new_ptr, size_of_dest_new_ptr) */
/* # To add an existing element (malloced) to a garbage */
/*   Usefull if you want to save it for futur free*/
/*   - check what method will be requiered to free it (ex : special if struct)*/
/*     , deduce from it which garbage of t_garbage_resume it must go in.*/
/*	 - all garbages should be initialised at the begginning of the program but*/
/*	   if needed create a new garbage (cf initialisation 4.))*/
/*	 - use :
		ft_garbage_add */
/* # To free a saved pointer */
/*   Determine the corresponding garbage and use :
		ft_garbage_free_one(p_garbage, pointer_to_free) */
/* # To free all pointers from a given garbage */
/*	 Use :
		ft_garbage_free(p_garbage, error=0) */
/*	 If error != 0 => all garbages freed & program quit*/
/* # To free all */
/*	 Use :
		ft_garbage_group_free(...) */
/*	  /!\ program exit if error != 0 

*/
/*=== ERROR MANAGEMENT ===*/
/*In case of malloc error in garbage management all garbages will be flushed */
/*and the program exits with error.*/