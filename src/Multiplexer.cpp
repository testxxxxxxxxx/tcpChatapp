#include "../include/Multiplexer.hpp"
#include "../include/Server.hpp"
#include "../include/Command.hpp"
#include <iostream>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/crypto.h>

void ChatApp::Multiplexing::Multiplexer::init() {
	this->efd = epoll_create1(0);
	if(this->efd == -1) {
		perror("epoll_create1");
		exit(1);
	}
}
void ChatApp::Multiplexing::Multiplexer::loopEvent() {
	int fd = this->s->getSfd();
	struct epoll_event event, events[this->maxEvents];
	event.events = EPOLLIN;
	event.data.fd = fd;
	epoll_ctl(this->efd, EPOLL_CTL_ADD, fd, &event);
	struct sockaddr_in caddr;
	socklen_t caddrSize = sizeof(caddr);
	SSL* ssl;

	while(1) {
		int countReady = epoll_wait(this->efd, events, this->maxEvents, -1);

		for(int i = 0; i < countReady; i++) {
			if(events[i].data.fd == fd) {
				int cfd = this->s->acceptConnections(&caddr, &caddrSize);
				ssl = SSL_new(this->s->getCTX());
				SSL_set_fd(ssl, cfd);
				SSL_accept(ssl);
				this->s->setnonblock(cfd);
				event.events = EPOLLIN | EPOLLOUT;
				event.data.fd = cfd;
				epoll_ctl(this->efd, EPOLL_CTL_ADD, cfd, &event);
			} 
			else {
				if(events[i].events & EPOLLIN) {
					char buffer[1024] = {};
					int rc = SSL_read(ssl, buffer, sizeof(buffer));
				}
				if(events[i].events & EPOLLOUT) {

				}
			}
		}
	}
}
void ChatApp::Multiplexing::Multiplexer::notifyWritable(int fd) {

}
