/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:08:16 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/10 17:51:09 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h> // fuer size_t
#include <stdlib.h> // fuer malloc

typedef struct s_list
{
	int	content;
	struct s_list	*next;
}		t_list;

typedef struct Stack
{
	t_list	*data;
	int	size;
} 	stack;


void	operations(stack);

#endif
