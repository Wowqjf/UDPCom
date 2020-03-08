CXX=g++
CXX_FLAG=-lpthread -std=c++11 -g
SRCS=main.cpp threadinit.cpp udp.cpp singleLinkList.cpp

main:$(SRCS)
	$(CXX) $^ -o $@ $(CXX_FLAG)
