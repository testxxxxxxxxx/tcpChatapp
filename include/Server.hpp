#ifndef SERVER_HPP
#define SERVER_HPP
#include <netinet/in.h>
#include <openssl/ssl.h>
namespace ChatApp::SocketServer {
	class ServerI {
		virtual void init(int size) = 0;
		virtual void initSSL() = 0;
		virtual int acceptConnections(struct sockaddr_in* caddr, socklen_t* caddrSize) = 0;
		virtual void closeSocket() = 0;
		virtual void setnonblock(int fd) = 0;
		virtual int getSfd() = 0;
		virtual SSL_CTX* getCTX() = 0;
	};
	class Server : public ServerI {
		int fd, port;
		SSL_CTX* ctx;
		public:
			Server(int port): port(port) {};
			virtual ~Server() = default;
			void init(int size) override;
			void initSSL() override;
			int acceptConnections(struct sockaddr_in* caddr, socklen_t* caddrSize) override;
			void closeSocket() override;
			void setnonblock(int fd) override;
			int getSfd() override;
			SSL_CTX* getCTX() override;
	};
};
#endif
