/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:29:37 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 17:19:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"

void	check_sockfd(int arg)
{
	try
	{
		if (arg < 0)
		{
			throw error_opening_socket();
		}
	}
	catch(const error_opening_socket& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	check_bind_return(int arg)
{
	try
	{
		if (arg < 0)
		{
			throw error_bind_failed();
		}
	}
	catch(const error_bind_failed& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE); 
	}
}


void	ircserv(int port, std::string const & password)
{
	print_variable(YELLOW, "PORT: ", port, RESET);
	print_variable(GREEN, "PASSWORD: ", password, RESET);


	int					server_fd;
	int					new_socket;
	int					valread;
	struct sockaddr_in	address;
	// int					opt = 1;
	int					addrlen = sizeof(address);
	char				buffer[1024] = {0};
	char 				hello[23] = "Welcome to the Server\n";

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	check_sockfd(server_fd);
	
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = INADDR_ANY;

	int	bind_ret = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	
	check_bind_return(bind_ret);

	if (listen(server_fd, 3) < 0)
	{
		// perror("listen");
		exit(EXIT_FAILURE);
	}
	new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if (new_socket < 0)
	{
		// perror("accept");
		exit(EXIT_FAILURE);
	}


	valread = 0;
	// ssize_t recv(int sockfd, void *buf, size_t len, int flags);
	while (true)
	{
		valread = recv(new_socket, buffer, 512, 0);
		// std::cout << "valread: " << valread << std::endl;
		buffer[valread] = '\0';
		std::cout << buffer << std::endl;
		send(new_socket, hello , std::string(hello).length(), 0);
		// std::cout << "Hello message sent" << std::endl;
	}
}
