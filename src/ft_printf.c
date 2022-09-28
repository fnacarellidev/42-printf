/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:50 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/28 16:11:55 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_percent_handler(char c, va_list ptr);

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
			ft_percent_handler(str[++i], ptr);
		}
		else
			ft_putchar(str[i]);
		i++;
		count++;
	}
	va_end(ptr);
	return (count);
}

void	ft_percent_handler(char c, va_list ptr)
{
	if (c == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		return ;
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ptr, long long), "0123456789");
	else if (c == 'u')
		return ;
	else if (c == 'x')
		ft_puthex(va_arg(ptr, long long), 'x');
	else if (c == 'X')
		ft_puthex(va_arg(ptr, long long), 'X');
	else if (c == '%')
		write(1, "%", 1);
}

int main()
{
	int x;
	int y;

	x = ft_printf("oi %d %x %X %%%%%%\n", 10, 2031123, 589466463);
	y = printf("oi %d %x %X %%%%%%\n", 10, 2031123,  589466463);
	printf("X = %d\n", x);
	printf("Y = %d\n", y);
	return (0);
}
