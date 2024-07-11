cmake_minimum_required(VERSION 2.8)

project(lexem_analyzer)

set(SOURCE_EXE main.cpp)  #объявление переменной 

set(SOURCE_LIB LexicalAnalyzer.cpp)	

add_library( LexicalAnalyzer STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main LexicalAnalyzer)	
