cmake_minimum_required(VERSION 2.8.9)
project (otla)

set(CMAKE_CXX_FLAGS "--std=gnu++98")

add_executable(otla 
	81files.cpp loaders.cpp sbb.cpp wav2.cpp 
	funciones.cpp signaltest.cpp  zxfiles.cpp 
	cpcfiles.cpp msxfiles.cpp main.cpp)

install(TARGETS otla DESTINATION bin)
