/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lia <Lia@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 21:14:03 by Lia               #+#    #+#             */
/*   Updated: 2020/03/31 14:53:07 by Lia              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	int	age = 21;
	char *name = "Lia";

	//ft_printf("\nMy name is Lia  and I am %d years old.\n", age);
	ft_printf("\nMy name is %s and I am %d years old.\n", name, age);
	return (0);
}