cmake_minimum_required(VERSION 2.5)
project(baseservice)

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
	segmentfault.cpp)
set(INC 
	../inc/aes.h
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
set(outPutDir ${PROJECT_BINARY_DIR})
#set(outPutDir ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "Project Directory: ${outPutDir}") 
ADD_LIBRARY(baseservice STATIC ${SRC} ${INC})  


install(FILES inc/aes.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/base64.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/baseDataType.h 		DESTINATION ${outPutDir}/include/inc)
install(FILES inc/config.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/dir.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/global.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/img.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/log.h 				DESTINATION ${outPutDir}/include/inc)
install(FILES inc/segmentfault.h 		DESTINATION ${outPutDir}/include/inc)
install(FILES inc/pointer.h 			DESTINATION ${outPutDir}/include/inc)
install(FILES inc/zlibnet.h 			DESTINATION ${outPutDir}/include/inc)
install(FILES ../libbaseservice.h 		DESTINATION ${outPutDir}/include/)
install(TARGETS  baseservice		    ARCHIVE DESTINATION ${outPutDir}/lib/)