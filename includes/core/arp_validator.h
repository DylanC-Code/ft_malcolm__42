/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:20:49 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_VALIDATOR_H
# define ARP_VALIDATOR_H

# include "domain/arp/arp_frame.h"
# include "domain/config.h"

typedef enum e_arp_frame_status
{
	ARP_FRAME_VALID,
	ARP_FRAME_UNSUPPORTED_OPERATION,
	ARP_FRAME_INVALID_SRC_MAC,
	ARP_FRAME_INVALID_TGT_MAC,
	ARP_FRAME_INVALID_SRC_IP,
	ARP_FRAME_INVALID_TGT_IP,
}					t_arp_frame_status;

t_arp_frame_status	validate_arp_frame(const t_arp_frame *pkt,
						const t_config *config);
char				*arp_frame_validation_strerror(t_arp_frame_status err);

#endif
