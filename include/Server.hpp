#ifndef SERVER_HPP
#define SERVER_HPP
#include <netinet/in.h>
namespace ChatApp::SocketServer {
	class ServerI {
		virtual void init(int size) = 0;
		virtual int acceptConnections(struct sockaddr_in* caddr, socklen_t* caddrSize) = 0;
		virtual void closeSocket() = 0;
		virtual void setnonblock(int fd) = 0;
		virtual int getSfd() = 0;
	};
	class Server : public ServerI {
		int fd, port;
		public:
			Server(int port): port(port) {};
			virtual ~Server() = default;
			void init(int size) override;
			int acceptConnections(struct sockaddr_in* caddr, socklen_t* caddrSize) override;
			void closeSocket() override;
			void setnonblock(int fd) override;
			int getSfd() override;
	};
};
#endif
