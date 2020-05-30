cmake_minimum_required(VERSION 3.10)
project(LoRDeck__)

set(CMAKE_CXX_STANDARD 14)

include_directories(cppcodec)
add_executable(LoRDeck__ main.cpp utils.cpp utils.h LoRDeck.cpp LoRDeck.h LoRCard.cpp LoRCard.h)