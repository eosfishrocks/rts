EOSIOCPP = eosiocpp

build : users token

token :
	$(EOSIOCPP) -o ./contracts/Token.wast ./contracts/Token.cpp

reputation :
	$(EOSIOCPP) -o ./contracts/Reputation.wast ./contracts/Reputation.cpp && \
		$(EOSIOCPP) -g ./contracts/Reputation.abi ./contracts/Reputation.cpp
		
clean :
	-find . -type f \( -name '*.wasm' -o -name '*.wast' -o -name '*.abi' -a ! -name Token.abi \) -exec rm {} +
