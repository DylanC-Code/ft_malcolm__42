/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:19:25 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:42 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_HANDLER_H
# define ARP_HANDLER_H

# include "core/arp_service.h"

bool	handle_arp_frame(t_arp_context *ctx);

#endif
