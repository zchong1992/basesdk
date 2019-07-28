cmake_minimum_required(VERSION 2.5)
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


set(LIBS "")



if (WIN32)
set(LIBS "${LIBS} wsock32")
endif  (WIN32)


add_library(zSpace SHARED ${SRC} ${INC} )
add_library(baseservice_static STATIC ${SRC} ${INC} )
target_link_libraries(zSpace  ${LIBS})
target_link_libraries(baseservice_static  ${LIBS})

set_target_properties(baseservice_static PROPERTIES OUTPUT_NAME "zSpace")
set_target_properties(zSpace PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(baseservice_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#set_target_properties(zSpace PROPERTIES VERSION 1.0 SOVERSION 1)

#ADD_LIBRARY(zSpace STATIC ${SRC} ${INC})  

install(TARGETS  baseservice_static	    ARCHIVE DESTINATION ${outPutDir}/../lib/)
install(TARGETS  zSpace		    LIBRARY DESTINATION ${outPutDir}/../lib/)