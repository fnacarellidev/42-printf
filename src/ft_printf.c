/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:50 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/05 19:12:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_percent_handler(char c, va_list ptr)
{
	int	chars_printed;

	chars_printed = 0;
	if (c == 'c')
		chars_printed += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		chars_printed += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		chars_printed += ft_put_address(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		chars_printed += ft_putnbr_base(va_arg(ptr, int), DEC_DIGITS);
	else if (c == 'u')
		chars_printed += ft_putnbr_base(va_arg(ptr, unsigned int), DEC_DIGITS);
	else if (c == 'x')
		chars_printed += ft_putnbr_base(va_arg(ptr, unsigned int), HEX_LOWCASE);
	else if (c == 'X')
		chars_printed += ft_putnbr_base(va_arg(ptr, unsigned int), HEX_UPCASE);
	else if (c == '%')
		return (write(1, "%", 1));
	return (chars_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ptr, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_percent_handler(str[++i], ptr);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
