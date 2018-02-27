cmake_minimum_required(VERSION 3.4)
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
ADD_LIBRARY(baseservice STATIC ${SRC} ${INC})  