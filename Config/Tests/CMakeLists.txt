include_directories(SYSTEM ${DOCTEST_INCLUDE_PATH})
file(GLOB source_files ${ROVER_SOURCE_PATH}/Tests/*.cpp)
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()
add_executable(rover_tester ${source_files})
if(UNIX)
  target_link_libraries(rover_tester pthread)
endif()
add_custom_command(TARGET rover_tester POST_BUILD COMMAND rover_tester)
install(TARGETS rover_tester CONFIGURATIONS Debug
  DESTINATION ${TEST_INSTALL_DIRECTORY}/Debug)
install(TARGETS rover_tester CONFIGURATIONS Release RelWithDebInfo
  DESTINATION ${TEST_INSTALL_DIRECTORY}/Release)
