/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:43:10 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:32:30 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/log/logger.h"
#include "infrastructure/net/ip_parser.h"
#include "libft.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>

bool	parse_str_ip_address(char *src, t_ip *dst)
{
	struct addrinfo		*res;
	struct sockaddr_in	*addr_in;
	int					getaddrinfo_result;

	if (inet_pton(AF_INET, src, &dst->addr) == 1)
		return (true);
	getaddrinfo_result = getaddrinfo(src, NULL, NULL, &res);
	if (getaddrinfo_result != 0)
	{
		log_error(gai_strerror(getaddrinfo_result));
		return (false);
	}
	addr_in = (struct sockaddr_in *)res->ai_addr;
	ft_memcpy(&dst->addr, &addr_in->sin_addr, sizeof(struct in_addr));
	log_info("Resolved hostname '%s' to IP: %s", src, inet_ntoa(dst->addr));
	freeaddrinfo(res);
	return (true);
}
