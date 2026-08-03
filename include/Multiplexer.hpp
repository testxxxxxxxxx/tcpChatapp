#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP
namespace ChatApp::SocketServer {
	class Server;
};

namespace ChatApp::Multiplexing {
	class MultiplexerI {
		public:
			virtual void init() = 0;
			virtual void loopEvent() = 0;
			virtual void notifyWritable(int fd) = 0;
	};
	class Multiplexer : public MultiplexerI {
		int efd, maxEvents;
		ChatApp::SocketServer::Server* s;

		public:
			Multiplexer(ChatApp::SocketServer::Server* s, int maxEvents): s(s), maxEvents(maxEvents) {}
			~Multiplexer() {
				delete s;
			}

			void init() override;
		        void loopEvent() override;
			void notifyWritable(int fd) override;	
	};
};
#endif
