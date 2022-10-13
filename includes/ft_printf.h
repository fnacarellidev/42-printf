/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:07:53 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/10 15:47:42 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

int				ft_putchar(char c);
int				ft_putstr(char *str);
size_t			ft_strlen(char *str);
int				ft_printf(const char *str, ...);
int				ft_put_address(unsigned long long nbr);
int				ft_putnbr_base(long long nbr, char *base);
int				ft_puthex(unsigned long long nbr, int use_uppercase);

#endif
