/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:03:03 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 23:12:30 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

void	log_error(const char *fmt, ...);
void	log_warn(const char *fmt, ...);
void	log_info(const char *fmt, ...);
void	log_debug(const char *fmt, ...);

#endif
