cmake_minimum_required(VERSION 2.5)
project(baseservice)

add_definitions(-std=c++11)
set(incPath . .. ../inc)
INCLUDE_DIRECTORIES( ${incPath})
set(SRC aes.cpp 
	base64.cpp
	baseDataType.cpp
	config.cpp
	dir.cpp
	global.cpp
	img.cpp
	libbaseservice.cpp
	log.cpp
	zlibnet.cpp
	cThread.cpp
	msgTransport.cpp
	segmentfault.cpp)
set(INC 
	../inc/aes.h
	../inc/cThread.h
	../inc/msgTransport.h
	../inc/base64.h
	../inc/baseDataType.h
	../inc/config.h
	../inc/dir.h
	../inc/global.h
	../inc/img.h
	../inc/log.h
	../inc/segmentfault.h
	../inc/pointer.h
	../inc/zlibnet.h
	../libbaseservice.h)
#set(outPutDir ${PROJECT_BINARY_DIR})
set(outPutDir ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "Project Directory: ${outPutDir}")

add_library(baseservice SHARED ${SRC} ${INC})
add_library(baseservice_static STATIC ${SRC} ${INC})
 
set_target_properties(baseservice_static PROPERTIES OUTPUT_NAME "baseservice")
set_target_properties(baseservice PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(baseservice_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(baseservice PROPERTIES VERSION 1.0 SOVERSION 1)

#ADD_LIBRARY(baseservice STATIC ${SRC} ${INC})  


#install(FILES ../inc/aes.h 				DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/base64.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/baseDataType.h 	DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/config.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/dir.h 				DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/global.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/img.h 				DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/log.h 				DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/segmentfault.h 	DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/pointer.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/zlibnet.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/msgTransport.h 	DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../inc/cThread.h 			DESTINATION ${outPutDir}/../include/inc)
#install(FILES ../libbaseservice.h 		DESTINATION ${outPutDir}/../include/)
install(TARGETS  baseservice_static	    ARCHIVE DESTINATION ${outPutDir}/../lib/)
install(TARGETS  baseservice		    LIBRARY DESTINATION ${outPutDir}/../lib/)