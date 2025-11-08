/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 13:16:47 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_handler.h"
#include "core/arp_validator.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/shared.h"

bool	handle_arp_packet(t_arp_context *ctx)
{
	t_arp_packet_status	status;

	status = validate_arp_packet(&ctx->arp_pkt, ctx->config);
	if (status != ARP_PACKET_VALID)
	{
		ft_error(arp_packet_validation_strerror(status));
	print_arp_packet(&ctx->arp_pkt);

		return (false);
	}
	print_arp_packet(&ctx->arp_pkt);
	return (true);
}
