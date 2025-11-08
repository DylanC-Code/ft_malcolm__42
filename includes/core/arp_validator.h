/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:49 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 12:02:35 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_VALIDATOR_H
# define ARP_VALIDATOR_H

# include "domain/arp/arp_packet.h"
# include "domain/config.h"

typedef enum e_arp_packet_status
{
	ARP_PACKET_VALID,
	ARP_PACKET_UNSUPPORTED_OPERATION,
	ARP_PACKET_INVALID_SRC_MAC,
	ARP_PACKET_INVALID_TGT_MAC,
	ARP_PACKET_INVALID_SRC_IP,
	ARP_PACKET_INVALID_TGT_IP,
}					t_arp_packet_status;

t_arp_packet_status	validate_arp_packet(const t_arp_packet *pkt,
						const t_config *config);
char				*arp_packet_validation_strerror(t_arp_packet_status err);

#endif
