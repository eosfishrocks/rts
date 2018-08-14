EOSIOCPP = eosiocpp

build : users token

token :
	$(EOSIOCPP) -o ./src/contracts/Token.wast ./src/contracts/Token.cpp


users :
	$(EOSIOCPP) -o ./src/contracts/Users.wast ./src/contracts/Users.cpp && \
		$(EOSIOCPP) -g ./src/contracts/Users.abi ./src/contracts/Users.cpp
		
clean :
	-find . -type f \( -name '*.wasm' -o -name '*.wast' -o -name '*.abi' -a ! -name Token.abi \) -exec rm {} +
