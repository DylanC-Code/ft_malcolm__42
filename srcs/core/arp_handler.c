/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:08 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/arp_handler.h"
#include "core/arp_sender.h"
#include "core/arp_validator.h"
#include "infrastructure/net/arp_printer.h"
#include "infrastructure/shared.h"

bool	handle_arp_frame(t_arp_context *ctx)
{
	t_arp_frame_status	status;

	status = validate_arp_frame(&ctx->arp_pkt, ctx->config);
	if (status != ARP_FRAME_VALID)
	{
		ft_error(arp_frame_validation_strerror(status));
		print_arp_frame(&ctx->arp_pkt);
		return (false);
	}
	print_arp_frame(&ctx->arp_pkt);
	send_arp_frame(ctx);
	return (true);
}
