cmake_minimum_required(VERSION 2.5)
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}") 
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 message("use linux platform")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
 message("use Windows platform")
endif(CMAKE_SYSTEM_NAME MATCHES "Linux")

project(zSpace)

if (UNIX)
add_definitions(-std=c++11)
add_definitions(-g -O0)
endif  (UNIX)

set(incPath . .. ../inc img config crypto event net log thread theadSafa)
INCLUDE_DIRECTORIES( ${incPath})
set(SRC crypto/aes.cpp 
		crypto/base64.cpp
		config/config.cpp 
		event/msgTransport.cpp
		img/img.cpp
		log/log.cpp
		log/segmentfault.cpp
		net/zlibnet.cpp
		thread/cThread.cpp
		threadSafe/baseDataType.cpp
		global.cpp
		libbaseservice.cpp)
 
#set(outPutDir ${PROJECT_BINARY_DIR})
set(outPutDir ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "Project Directory: ${outPutDir}")
 

if (WIN32)
set(LIBS ${LIBS}  "wsock32")
endif  (WIN32)


add_library(zSpace SHARED ${SRC} ${INC} )
add_library(zSpace_static STATIC ${SRC} ${INC} )
target_link_libraries(zSpace  ${LIBS})
target_link_libraries(zSpace_static  ${LIBS})

set_target_properties(zSpace_static PROPERTIES OUTPUT_NAME "zSpace_static")

set_target_properties(zSpace PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(zSpace_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#set_target_properties(zSpace PROPERTIES VERSION 1.0 SOVERSION 1)

#ADD_LIBRARY(zSpace STATIC ${SRC} ${INC})  

install(TARGETS zSpace_static ARCHIVE DESTINATION ${outPutDir}/../lib/)

install(TARGETS zSpace DESTINATION ${outPutDir}/../lib/)