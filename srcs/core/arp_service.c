/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:46 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 23:16:26 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_service.h"
#include "domain/arp/arp_parser.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/shared.h"
#include <unistd.h>

/// @brief Listens for ARP requests and replies accordingly
/// @param config Pointer to the configuration struct
/// @return true on success, false on failure
bool	listen_arp_request_and_reply(t_config *config)
{
	t_iface			*iface;
	t_iface_status	iface_status;
	unsigned char	buffer[65536];
	ssize_t			bytes_read;
	t_arp_packet	arp_packet;

	iface_status = iface_open(&iface);
	bytes_read = 0;
	if (iface_status != IFACE_OPENING_SUCCESS)
		return (ft_error(iface_strerror(iface_status)), false);
	while (!config->once)
	{
		sleep(1);
		iface_status = iface_recv(iface, buffer, sizeof(buffer), &bytes_read);
		if (iface_status != IFACE_RECV_SUCCESS)
		{
			ft_error(iface_strerror(iface_status));
			/* TODO: handle which error will made quit the program. */
			continue ;
		}
		if (parse_arp_request(buffer, bytes_read,
				&arp_packet) != ARP_PARSING_SUCCESS)
			continue ;
		print_arp_packet(&arp_packet);
	}
	iface_close(iface);
	__builtin_printf("iface close correctly\n");
	return (true);
}
