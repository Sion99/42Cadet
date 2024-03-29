/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:21:07 by sishin            #+#    #+#             */
/*   Updated: 2023/10/06 16:46:52 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_data g_data;

void ft_putnbr(int n)
{
	long nbr;
	char c;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

void reset_data(void)
{
	g_data.i = 0;
	g_data.x = 0;
	g_data.client_pid = 0;
}

void handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig -= SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		reset_data();
	g_data.x = g_data.x << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		write(1, &g_data.x, 1);
		reset_data();
	}
	g_data.client_pid = info->si_pid;
}

int main(void)
{
	struct sigaction sa;

	reset_data();
	write(1, "pid :    ", 10);
	ft_putnbr(getpid());
	write(1, "\n", 2);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}