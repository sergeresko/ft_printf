/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:45 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 13:47:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write in ft_print_integer

int		ft_print_string(const t_fmt *a_fmt, const char *str)
{
	int		n_characters;

	n_characters = ft_strlen(str);
	if (0 <= a_fmt->precision && a_fmt->precision < n_characters)
		n_characters = a_fmt->precision;
	if (!a_fmt->left_align)
		ft_putnchar((a_fmt->zero_padding) ? '0' : ' ', a_fmt->width - n_characters);
	write(1, str, n_characters);	// here write is used
	if (a_fmt->left_align)
		ft_putnchar(' ', a_fmt->width - n_characters);
	return ((a_fmt->width > n_characters) ? a_fmt->width : n_characters);
}
