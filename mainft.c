/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:02:39 by lpatin            #+#    #+#             */
/*   Updated: 2024/11/07 17:09:44 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "others.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		return_value;

	va_start(arguments, format);
	i = 0;
	return_value = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			return_value += formatting(&format[i], arguments);
		}
		else
		{
			write(1, &format[i], 1);
			return_value++;
		}
		i++;
	}
	va_end(arguments);
	return (return_value);
}
#include <stdio.h>

int main(void)
{
	printf("%d", ft_printf("~%s~", "Hello, World !"));
	printf("%d", printf("~%s~", "Hello, World !"));
	return (0);
}