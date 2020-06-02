cmake_minimum_required(VERSION 3.5)
project(LoRDeck__)

set(CMAKE_CXX_STANDARD 14)

include_directories(cppcodec)
add_executable(LoRDeck__ src/main.cpp src/utils.cpp include/utils.h src/LoRDeck.cpp include/LoRDeck.h src/LoRCard.cpp include/LoRCard.h)