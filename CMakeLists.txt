cmake_minimum_required(VERSION 2.8.3)
project(semrec_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

find_package(catkin REQUIRED COMPONENTS designator_integration_cpp designator_integration_msgs roscpp roslib)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES semrec_client
  CATKIN_DEPENDS designator_integration_cpp designator_integration_msgs roscpp roslib)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
  src/semrec_client/BeliefstateClient.cpp
  src/semrec_client/Object.cpp
  src/semrec_client/Context.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES})

add_executable(ex1
  src/examples/ex1.cpp)

add_executable(ex_repeat_offset
  src/examples/ex_repeat_offset.cpp)

target_link_libraries(ex1
  ${catkin_LIBRARIES}
  ${PROJECT_NAME})

target_link_libraries(ex_repeat_offset
  ${catkin_LIBRARIES}
  ${PROJECT_NAME})
