#ifndef RESPONSE_PROVIDER_HPP
#define RESPONSE_PROVIDER_HPP
#include <string>
namespace ChatApp::Commands {
	class Command;
};
namespace ChatApp::ResponseManagement {
	class ResponseProviderI {
		public:
			virtual std::string getText(ChatApp::Commands::Command* c) = 0;	
	};
	class ResponseProvider : public ResponseProviderI {
		public:
			ResponseProvider() {};
			virtual ~ResponseProvider() = default;

			std::string getText(ChatApp::Commands::Command* c) override;
	};	
};
#endif
