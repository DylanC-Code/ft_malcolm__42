/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 00:01:15 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_handler.h"
#include "core/arp_sender.h"
#include "core/arp_validator.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/log/logger.h"
#include "domain/mac_address.h"
#include "domain/ip_address.h"
#include <stdlib.h>

void log_success(t_arp_context *ctx)
{
	char * mac = mac_to_string(&ctx->arp_pkt.src_mac);
	char *ip = ip_to_string(ctx->arp_pkt.src_ip);

	if (!mac || !ip)
	{
		free(mac);
		free(ip);
		log_error("Failed to allocate memory for logging ARP request.");
		return ;
	}

	log_info("An ARP request has been broadcast.\n\t\tMAC address of request: %s\n\t\tIP address of request: %s", mac, ip);
	free(mac);
	free(ip);
}

bool	handle_arp_frame(t_arp_context *ctx)
{
	t_arp_frame_status	status;

	status = validate_arp_frame(&ctx->arp_pkt, ctx->config);
	if (status != ARP_FRAME_VALID)
	{
		log_warn(arp_frame_validation_strerror(status));
		return (false);
	}
	log_success(ctx);
	return send_arp_frame(ctx);
}
