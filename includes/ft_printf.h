/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:23 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/30 15:26:47 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

typedef int t_bool;

typedef struct		s_flags
{
	t_bool		sharp;
	t_bool		zero;
	t_bool		dash;
	t_bool		space;
	t_bool		plus;
}					t_flags;

typedef struct		s_length
{
	int			l;
	int			h;
	int			j;
	int			z;
}					t_length;

typedef struct 		s_specifiers
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		identifier;
}					t_specifiers;

int			ft_printf(const char *format, ...);
void		get_format_specifications(char const **format, va_list ap,
												t_specifiers *specifiers);
char		*get_raw_data(va_list ap, t_specifiers specifiers);

void		get_flags(const char **format, t_specifiers *specifiers);
void		get_width(const char **format, t_specifiers *specifiers, va_list ap);
void		get_precision(const char **format, t_specifiers *specifiers, va_list ap);
void		get_length_specifier(char const **format, t_specifiers *specifiers);
void		get_identifier(const char **format, t_specifiers *specifiers);

char  		*unsigned_conv(va_list ap, t_specifiers specifiers);
char  		*signed_conv(va_list ap, t_specifiers specifiers);

char		*ft_itoa_base_lld(long long value, int base);
char		*ft_itoa_base_llu(unsigned long long value, int base);

t_bool		is_flag(const char c);
t_bool		is_length_specifier(char const c);
t_bool		is_identifier(char const c);
int			get_conv_base(char id);
void		initialize_specifiers(t_specifiers *specifiers);

#endif
