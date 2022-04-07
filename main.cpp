/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:24:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/07 15:00:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include "socket.hpp"
#include "utils.hpp"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
using namespace std;

int main() {
  
  /* ---------- INITIALIZING VARIABLES ---------- */
  string hostname = "irc.majinboo.com";
  string server_address = "127.0.0.1";
  int port_num = generateRandPortNum();
  server serv(hostname, server_address, port_num);
  std::cout << "port_num: " << port_num << std::endl;
  int bufsize = 512;
  char buffer[bufsize];
  char reply[bufsize];
  vector<wstring> commands;
  initialize_commands_list(commands);

  /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
  /* --------------- socket() function ------------------*/

  serv.createSocket();

  /* ---------- BINDING THE SOCKET ---------- */
  /* ---------------- bind() ---------------- */

  if (serv.bindSocket() < 0)
    return (-1);

  /* ------------- LISTENING CALL ------------- */
  /* ---------------- listen() ---------------- */

  serv.listenSocket();

  /*
  fd_set
  An fd_set is a set of sockets to "monitor" for some activity. There are four useful macros : FD_CLR, FD_ISSET, FD_SET, FD_ZERO for dealing with an fd_set.

  FD_ZERO - Clear an fd_set
  FD_ISSET - Check if a descriptor is in an fd_set
  FD_SET - Add a descriptor to an fd_set
  FD_CLR - Remove a descriptor from an fd_set
  */

  fd_set readfds;
  int activity, sd, max_sd, new_socket;

  int max_clients = 30;
  int client_socket[max_clients];

  //initialise all client_socket[] to 0 so not checked
  for ( int i = 0; i < max_clients; i++) 
  {
      client_socket[i] = 0;
  }

  // /* ------------- SELECT - ADD SD TO SD_SET  ------------- */
  // /* ----------------- select() ------------------- */

  while(true) 
  {
      //clear the socket set
      FD_ZERO(&readfds);

      //add server socket to set
      FD_SET(serv.getClient(), &readfds);
      max_sd = serv.getClient();
  
      //add child sockets to set
      for ( int i = 0 ; i < max_clients ; i++) 
      {
          //socket descriptor
        sd = client_socket[i];
          
        //if valid socket descriptor then add to read list
        if (sd > 0)
          FD_SET( sd , &readfds);
            
        //highest file descriptor number, need it for the select function
        if(sd > max_sd)
          max_sd = sd;
      }

      //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
      activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
  
      if ((activity < 0) && (errno!=EINTR)) 
      {
          printf("select error");
      }
        
      //If something happened on the master socket , then its an incoming connection
      if (FD_ISSET(serv.getClient(), &readfds)) 
      {
          if ((new_socket = accept(serv.getClient(), (struct sockaddr *)&serv.getServerAddr(), (socklen_t*)&serv.getSize()))<0)
          {
              perror("accept");
              exit(EXIT_FAILURE);
          }
          serv.setServer(new_socket);
          //inform user of socket number - used in send and receive commands
          printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(serv.getServerAddr().sin_addr), ntohs(serv.getServerAddr().sin_port));
          
          // std::string message = "Welcome to IRC Majinboo ";
          // //send new connection greeting message
          // int bytes_sent = send(new_socket, message.c_str(), message.length(), 0);
          // size_t b_sent;
          // if (bytes_sent >= 0)
          //   b_sent = bytes_sent;
          // if( bytes_sent < 0 || b_sent != message.length() ) 
          // {
          //     perror("send");
          // }
            
          // puts("Welcome message sent successfully");
            
          //add new socket to array of sockets
          for (int i = 0; i < max_clients; i++) 
          {
              //if position is empty
              if( client_socket[i] == 0 )
              {
                  client_socket[i] = new_socket;
                  printf("Adding to list of sockets as %d\n" , i);
                  break;
              }
          }
      }
      for (int i = 0; i < max_clients; i++) 
      {
        int bytes_received = 0;
        int flag = 1;
        std::string tmp;

        if (FD_ISSET(client_socket[i], &readfds))
          bytes_received = recv(client_socket[i], buffer, bufsize, 0);
        // if (bytes_received == 0)
        //   exit(0);
        if (i < 3 && bytes_received > 0)
          std::cout << "pre-recv : "
                    << i
                    << " : "
                    << bytes_received
                    << std::endl;
        if (bytes_received > 0) {
          std::cout << "bytes received: " << bytes_received << std::endl;
          buffer[bytes_received] = '\0';
          std::string s(buffer);
          // tmp = tmp + s;
          std::cout << "tmp: " << tmp << std::endl;
          string command = "NICK";
          string space = "\n";
          int nick_pos = tmp.find(command);
          // std::cout << "nick_pos: " << nick_pos << std::endl;
          if (nick_pos != -1) {
            int pos_next_space = tmp.find(space, nick_pos + 5) - nick_pos - 6;
            // std::cout << "position of the next space: " << pos_next_space << std::endl;
            string nickname = tmp.substr(nick_pos + 5, pos_next_space);
            // std::cout << "NICK tag detected: [" << nickname << "]\n";
            string tmp_reply;
            string reply_code = "001";
            tmp_reply = ":" + hostname + " " + reply_code + " " + nickname + " " +
                        ":Welcome to IRC Majinboo " + nickname + "!" + nickname +
                        "@127.0.0.1\r\n";
            // tmp_reply = " :Welcome to MajinBoo IRC - Realm of DBZ Lovers " +
            // nickname +

            int bytes_sent = tmp_reply.length();
            // std::cout << "tmp_reply: " << tmp_reply << std::endl;
            // tmp_reply = ":" + hostname + reply_code + " * " + nickname +
            //            "Nickname is already in use.";
            if (!tmp_reply.empty() && flag) {
              std::cout << "sending back a reply to IRC client\n";
              strcpy(reply, tmp_reply.c_str());
              // strcat(reply, "\r\n\0");
              // printf("reply: %s", reply);
              send(new_socket, reply, bytes_sent, 0);
              tmp_reply = "";
              flag = 0;
            }
          }  
        }
      }

    // int bytes_received = 0;
    // int flag = 1;

    // std::string tmp;
    // do {
    //   bytes_received = recv(server, buffer, bufsize, 0);
    //   if (bytes_received > 0) {
    //     std::cout << "bytes received: " << bytes_received << std::endl;
    //     buffer[bytes_received] = '\0';
    //     std::string s(buffer);
    //     tmp = tmp + s;
    //     std::cout << "tmp: " << tmp << std::endl;
    //     string command = "NICK";
    //     string space = "\n";
    //     int nick_pos = tmp.find(command);
    //     // std::cout << "nick_pos: " << nick_pos << std::endl;
    //     if (nick_pos != -1) {
    //       int pos_next_space = tmp.find(space, nick_pos + 5) - nick_pos - 6;
    //       // std::cout << "position of the next space: " << pos_next_space << std::endl;
    //       string nickname = tmp.substr(nick_pos + 5, pos_next_space);
    //       // std::cout << "NICK tag detected: [" << nickname << "]\n";
    //       string tmp_reply;
    //       string reply_code = "001";
    //       tmp_reply = ":" + hostname + " " + reply_code + " " + nickname + " " +
    //                   ":Welcome to IRC Majinboo " + nickname + "!" + nickname +
    //                   "@127.0.0.1\r\n";
    //       // tmp_reply = " :Welcome to MajinBoo IRC - Realm of DBZ Lovers " +
    //       // nickname +

    //       int bytes_sent = tmp_reply.length();
    //       // std::cout << "tmp_reply: " << tmp_reply << std::endl;
    //       // tmp_reply = ":" + hostname + reply_code + " * " + nickname +
    //       //            "Nickname is already in use.";
    //       if (!tmp_reply.empty() && flag) {
    //         std::cout << "sending back a reply to IRC client\n";
    //         strcpy(reply, tmp_reply.c_str());
    //         // strcat(reply, "\r\n\0");
    //         // printf("reply: %s", reply);
    //         send(server, reply, bytes_sent, 0);
    //         tmp_reply = "";
    //         flag = 0;
    //       }
    //     }
    // //   }
    // } while (true);

    /* ---------------- CLOSE CALL ------------- */
    /* ----------------- close() --------------- */

    /*
        Once the server presses # to end the connection,
        the loop will break and it will close the server
        socket connection and the client connection.
    */
  }
    // inet_ntoa converts packet data to IP, which was taken from client
    std::cout << "\n\n=> Connection terminated with IP "
         << inet_ntoa(serv.getServerAddr().sin_addr);
    close(serv.getServer());
    std::cout << "\nGoodbye..." << std::endl;
    // isExit = false;
    exit(1);

  close(serv.getClient());
  return 0;
}
