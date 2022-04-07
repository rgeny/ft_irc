/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:39:31 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/07 12:11:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define EXIT_FAILURE 1

server::server()
    : _hostname(std::string()), _addr(std::string()), _port_num(), _client(),
      _server(){};

server::server(std::string hostname, std::string addr, int port_number)
    : _hostname(hostname), _addr(addr), _port_num(port_number), _client(),
      _server(){};

server::~server(){};

void server::createSocket() {

  /*
      The socket() function creates a new socket.
      It takes 3 arguments,
          a. AF_INET: address domain of the socket.
          b. SOCK_STREAM: Type of socket. a stream socket in
          which characters are read in a continuous stream (TCP)
          c. Third is a protocol argument: should always be 0. The
          OS will choose the most appropiate protocol.
          This will return a small integer and is used for all
          references to this socket. If the socket call fails,
          it returns -1.
  */
  /*
      The variable serv_addr is a structure of sockaddr_in.
      sin_family contains a code for the address family.
      It should always be set to AF_INET.
      INADDR_ANY contains the IP address of the host. For
      server code, this will always be the IP address of
      the machine on which the server is running.
      htons() converts the port number from host byte order
      to a port number in network byte order.
  */

  _client = socket(AF_INET, SOCK_STREAM, 0);

  if (_client < 0) {
    std::cout << "\nError establishing socket..." << std::endl;
    exit(EXIT_FAILURE);
  } else {
    std::cout << "\n=> Socket server has been created..." << std::endl;
  }

  int opt = true;
  //set master socket to allow multiple connections , this is just a good habit, it will work without this
    if( setsockopt(_client, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
  _server_addr.sin_family = AF_INET;
  _server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  _server_addr.sin_port = htons(_port_num);
}

int server::bindSocket() {

  _size = 0;
  if ((bind(_client, (struct sockaddr *)&_server_addr, sizeof(_server_addr))) <
      0) {
    std::cout << "=> Error binding connection, the socket has already been "
                 "established..."
              << std::endl;
    return (-1);
  } else
    std::cout << "=> Successful binding on port " << _port_num << std::endl;

  _size = sizeof(_server_addr);
  return (0);
  /*
      The bind() system call binds a socket to an address,
      in this case the address of the current host and port number
      on which the server will run. It takes three arguments,
      the socket file descriptor. The second argument is a pointer
      to a structure of type sockaddr, this must be cast
      the correct type.
  */
}

void server::listenSocket() {
  std::cout << "=> Looking for clients..." << std::endl;
  listen(_client, 5);

  /*
      The listen system call allows the process to listen
      on the socket for connections.
      The program will be stay idle here if there are no
      incomming connections.
      The first argument is the socket file descriptor,
      and the second is the size for the number of clients
      i.e the number of connections that the server can
      handle while the process is handling a particular
      connection. The maximum size permitted by most
      systems is 5.
  */
}

int server::acceptConnection(void) {

  _server = accept(_client, (struct sockaddr *)&_server_addr, &_size);
  /*
      The accept() system call causes the process to block
      until a client connects to the server. Thus, it wakes
      up the process when a connection from a client has been
      successfully established. It returns a new file descriptor,
      and all communication on this connection should be done
      using the new file descriptor. tmp_reply.length();ss of the client on the other
      end of the connection, and the third argument is the size
      of this structure.
  */
  // first check if it is valid or not
  if (_server < 0)
    std::cout << "=> Error on accepting..." << std::endl;
  return (_server);
}

int server::getClient() { return (_client); }
int server::getServer() { return (_server); }
void server::setServer(int new_socket) { _server = new_socket; }
socklen_t& server::getSize() { return (_size); }
struct sockaddr_in &server::getServerAddr() {
  return (_server_addr);
}
