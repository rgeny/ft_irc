/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:38:52 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/07 12:11:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "socket.hpp"
#include <iostream>
#include <netinet/in.h>
#include <string>

class server {

public:
  server(void);
  server(std::string hostname, std::string addr, int port_number);
  virtual ~server(void);
  // server(server const &src);
  void createSocket(void);
  int bindSocket(void);
  void listenSocket(void);
  int acceptConnection(void);
  // void sendMsg();
  int getClient();
  int getServer();
  void setServer(int new_socket);
  socklen_t& getSize();
  struct sockaddr_in &getServerAddr();

private:
  std::string _hostname;
  std::string _addr;
  struct sockaddr_in _server_addr;
  socklen_t _size;
  int _port_num;
  int _client;
  int _server;
};

#endif
