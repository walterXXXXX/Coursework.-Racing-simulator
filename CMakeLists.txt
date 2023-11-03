cmake_minimum_required(VERSION 3.22.0)

project(RacingSimulator)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(RS_Classes SHARED \ 
"RS_Classes/vehicle.h" "RS_Classes/vehicle.cpp" \ 
"RS_Classes/groundvehicle.h" "RS_Classes/groundvehicle.cpp" \ 
"RS_Classes/airvehicle.h" "RS_Classes/airvehicle.cpp" \ 
"RS_Classes/camel.h" "RS_Classes/camel.cpp" \ 
"RS_Classes/hs_camel.h" "RS_Classes/hs_camel.cpp" \ 
"RS_Classes/centaur.h" "RS_Classes/centaur.cpp" \ 
"RS_Classes/at_boots.h" "RS_Classes/at_boots.cpp" \ 
"RS_Classes/carpetplane.h" "RS_Classes/carpetplane.cpp" \ 
"RS_Classes/eagle.h" "RS_Classes/eagle.cpp" \ 
"RS_Classes/broom.h" "RS_Classes/broom.cpp" \ 
"RS_Classes/anyrace.h" "RS_Classes/anyrace.cpp" \ 
"RS_Classes/groundrace.h" "RS_Classes/groundrace.cpp" \ 
"RS_Classes/airrace.h" "RS_Classes/airrace.cpp")

add_executable(RacingSimulator main.cpp)

target_link_libraries(RacingSimulator RS_Classes)
