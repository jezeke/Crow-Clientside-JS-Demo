cmake_minimum_required(VERSION 2.8)
project (example)

add_executable(example example.cpp)
target_link_libraries(example ${Boost_LIBRARIES})
target_link_libraries(example ${CMAKE_THREAD_LIBS_INIT})

if (Tcmalloc_FOUND)
	target_link_libraries(example ${Tcmalloc_LIBRARIES})
endif(Tcmalloc_FOUND)

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -pg" )
#SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g -pg" )
