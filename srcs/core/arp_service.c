/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:46 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 12:09:28 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_handler.h"
#include "core/arp_receiver.h"
#include "core/arp_service.h"
#include "domain/arp/arp_parser.h"
#include "infrastructure/iface/iface_open.h"
#include "infrastructure/log/logger.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/shared.h"
#include <unistd.h>

/// @brief Listens for ARP requests and replies accordingly
/// @param config Pointer to the configuration struct
/// @return true on success, false on failure
bool	listen_arp_request_and_reply(t_config *config)
{
	t_arp_context	arp_context;
	t_iface_status	iface_status;

	arp_context.config = config;
	iface_status = iface_open(&arp_context.iface);
	if (iface_status != IFACE_OPENING_SUCCESS)
	{
		log_error(iface_strerror(iface_status));
		return (false);
	}
	while (!config->once && !g_exiting)
	{
		if (!receive_arp_frame(&arp_context))
			continue ;
		if (!handle_arp_frame(&arp_context))
			continue ;
	}
	iface_close(arp_context.iface);
	log_info("Exiting ARP process.");
	return (true);
}
