/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:53:07 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 13:58:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOMAIN_MAC_H__
#define __DOMAIN_MAC_H__

#include <stdint.h>

typedef struct s_mac
{
    uint8_t bytes[6];
} t_mac;

void print_mac(t_mac *mac);

#endif