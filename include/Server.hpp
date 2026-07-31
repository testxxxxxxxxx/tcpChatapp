#ifndef SERVER_HPP
#define SERVER_HPP
#include <netinet/in.h>
namespace SocketServer {
	class Server {
		int fd, port;
		public:
			Server(int port): port(port) {};
			virtual ~Server() = default;
			void init(int size);
			int acceptConnections(struct sockaddr_in* caddr);
			void closeSocket();
			void setnonblock(int fd);
	};
};
#endif
