/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifications_parser.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:33:30 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/30 10:33:33 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_format_specifications(char const **format, va_list ap,
											t_specifiers *specifiers)
{
	while (is_flag(**format) || ft_isdigit(**format) || **format == '*' ||
		**format == '.' || **format == ' ')
	{
		if (is_flag(**format))
			get_flags(format, specifiers);
		else if (ft_isdigit(**format) || **format == '*')
			get_width(format, specifiers, ap);
		else if (**format == '.')
			get_precision(format, specifiers, ap);
		else if (**format == ' ')
			(*format)++;
	}
	get_identifier(format, specifiers);
}
