/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:56:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/08 16:11:51 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** main part of the string formatting function
*/

static char	*get_formated_string(const char **format, va_list ap,
									int *size, int n)
{
	t_specifiers	specifiers;
	char			*s;

	initialize_specifiers(&specifiers);
	get_format_specifications(format, ap, &specifiers);
	s = get_raw_data(ap, specifiers, size, n);
	process_data(&s, size, specifiers);
	return (s);
}

/*
** main part of the function
*/

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	int		size;
	int		n;

	n = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			n++;
		}
		else
		{
			format++;
			s = get_formated_string(&format, ap, &size, n);
			write(1, s, size);
			n = n + size;
			free(s);
		}
	}
	va_end(ap);
	return (n);
}
