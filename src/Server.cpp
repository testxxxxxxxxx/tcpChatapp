#include "../include/Server.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <cerrno>
#include <cstdlib>
#include <unistd.h>

void ChatApp::SocketServer::Server::init(int size) {
	int opt = 1;
	if((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket error!\n");
		exit(1);
	}
	setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in saddr;

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(this->port);

	if(bind(this->fd, (struct sockaddr*)&saddr, sizeof(saddr)) == -1) {
		perror("Bind error!\n");
		exit(1);
	}
	if(listen(this->fd, size) == -1) {
		perror("Listen error!\n");
		exit(1);
	}
	this->setnonblock(this->fd);
}
int ChatApp::SocketServer::Server::acceptConnections(struct sockaddr_in* caddr) {
	socklen_t caddrSize = sizeof(caddr);
	int cfd = accept(this->fd, (struct sockaddr*)&caddr, &caddrSize);

	if(cfd == -1) {
		if(errno == -1 || errno == EWOULDBLOCK)
			return -1;
		perror("Accept error!\n");
		return -1;
	}
	return cfd;
}
void ChatApp::SocketServer::Server::closeSocket() {
	close(this->fd);
}
void ChatApp::SocketServer::Server::setnonblock(int fd) {
	int flags = fcntl(fd, F_GETFL);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
