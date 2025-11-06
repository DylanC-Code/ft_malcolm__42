/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:41:51 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 13:12:43 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEX_UTILS_H__
#define __HEX_UTILS_H__

#include <stdint.h>
#include "libft.h"

void u8_to_hex_pair(uint8_t src, char dst[2]);
uint8_t hex_pair_to_u8(char str[2]);

#endif