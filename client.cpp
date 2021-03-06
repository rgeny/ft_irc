/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:56:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/20 00:47:26 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"

#ifndef PORT
# define PORT 6697
#endif

int main(int argc, char const *argv[])
{
	if (argc < 2)
		{
		std::cout << "\n Invalid argument: <port> \n" << std::endl;
		return -1;
	}
	int sock = 0;
	int	valread = 0;
	struct sockaddr_in serv_addr;
	char buffer[512] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "\n Socket creation error \n" << std::endl;
		return -1;
	}
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
    	error("setsockopt(SO_REUSEADDR) failed");
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse)) < 0) 
			perror("setsockopt(SO_REUSEPORT) failed");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_aton("127.0.0.1", &serv_addr.sin_addr) <= 0) 
	{
		std::cout << "\nInvalid address/ Address not supported \n" << std::endl;
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		std::cout << "\nConnection Failed \n" << std::endl;
		return -1;
	}
	while (true)
	{
		std::string input;
		getline(std::cin, input);
		input += "\r\n";
		send(sock, input.c_str(), input.length(), 0);
		valread = recv(sock, buffer, 512, 0);
		buffer[valread] = '\0';
		std::cout << buffer << std::endl;
	}
	return 0;
}
