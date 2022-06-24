# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CCPlot_test_autogen"
  "CMakeFiles\\CCPlot_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CCPlot_test_autogen.dir\\ParseCache.txt"
  )
endif()
