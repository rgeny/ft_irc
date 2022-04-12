#include "includes/ircserv.hpp"

#ifndef PORT
# define PORT 6697
#endif

int main(int argc, char const *argv[])
{
	if (argc != 2)
		{
		std::cout << "\n Invalid argument: <port> \n" << std::endl;
		return -1;
	}
	int sock = 0;
	int	valread = 0;
	struct sockaddr_in serv_addr;
	std::string		hello;
	char buffer[512] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "\n Socket creation error \n" << std::endl;
		return -1;
	}

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
		std::cin >> hello;
		send(sock, hello.c_str(), hello.length(), 0);
		// std::cout << "Hello message sent" << std::endl;
		valread = recv(sock, buffer, 512, 0);
		buffer[valread] = '\0';
		// std::cout << buffer << std::endl;
	}
	return 0;
}
