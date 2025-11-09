/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 20:01:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_handler.h"
#include "core/arp_sender.h"
#include "core/arp_validator.h"
#include "domain/ip_address.h"
#include "domain/mac_address.h"
#include "infrastructure/log/logger.h"
#include "infrastructure/net/arp_printer.h"
#include <stdlib.h>

void	log_success(t_arp_context *ctx)
{
	char	ip_str[16];
	char	mac_str[18];

	mac_to_string(&ctx->arp_pkt.src_mac, mac_str);
	ip_to_string(ctx->arp_pkt.src_ip, ip_str);
	log_info("Received valid ARP request: %s is at %s", ip_str, mac_str);
	if (ctx->config->verbose)
		return (print_arp_frame(&ctx->arp_pkt));
}

bool	error_strategy(t_arp_frame_status status, t_arp_context *ctx)
{
	log_warn(arp_frame_validation_strerror(status));
	if (ctx->config->verbose)
		print_arp_frame(&ctx->arp_pkt);
	return (false);
}

bool	handle_arp_frame(t_arp_context *ctx)
{
	t_arp_frame_status	status;

	status = validate_arp_frame(&ctx->arp_pkt, ctx->config);
	if (status != ARP_FRAME_VALID)
		return (error_strategy(status, ctx));
	log_success(ctx);
	return (send_arp_frame(ctx));
}
