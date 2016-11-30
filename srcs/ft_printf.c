/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:56:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/29 17:33:04 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* main part of the string formatting function */

static char		*get_formated_string(const char **format, va_list ap)
{
	t_specifiers	specifiers;
	char				*str;

	initialize_specifiers(&specifiers);
	get_format_specifications(format, ap, &specifiers);
	str = get_raw_data(ap, specifiers);
	//process_data(str, specifiers);
	return (str);
}

/* main part of the function */

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	int			n;

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
			s = get_formated_string(&format, ap);
			ft_putstr(s);
			n = n + ft_strlen(s);
			free(s);
		}
	}
	va_end(ap);
	return (n);
}
