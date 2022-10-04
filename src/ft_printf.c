/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:50 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/04 16:32:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_percent_handler(char c, va_list ptr)
{
	int	chars_printed;

	chars_printed = 0;
	if (c == 'c')
		chars_printed += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		chars_printed += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		return (0);
	else if (c == 'd' || c == 'i')
		chars_printed += ft_putnbr_base(va_arg(ptr, long long), "0123456789");
	else if (c == 'u')
		return (0);
	else if (c == 'x')
		chars_printed += ft_putnbr_base(va_arg(ptr, long long), "0123456789abcdef");
	else if (c == 'X')
		chars_printed += ft_putnbr_base(va_arg(ptr, long long), "0123456789ABCDEF");
	else if (c == '%')
		return(write(1, "%", 1));
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
	while (str[i]) 
	{
		if (str[i] == '%')
		{
			count += ft_percent_handler(str[++i], ptr);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
