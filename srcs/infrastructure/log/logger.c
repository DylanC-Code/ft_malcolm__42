/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:12:14 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 23:15:21 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/log/logger.h"
#include <stdarg.h>
#include <stdio.h>

void	log_error(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	printf("\033[1;31m[ERROR]\033[0m ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

void	log_warn(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	printf("\033[1;33m[WARN]\033[0m ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

void	log_info(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	printf("\033[1;32m[INFO]\033[0m ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

void	log_debug(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	printf("\033[1;36m[DEBUG]\033[0m ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}
