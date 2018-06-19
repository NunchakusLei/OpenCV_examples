cmake_minimum_required(VERSION 2.8)

project( ModifyImage )
find_package( OpenCV REQUIRED )
add_executable( ColorToGrey ColorToGrey.cpp )
target_link_libraries( ColorToGrey ${OpenCV_LIBS} )

add_executable( SaveImage SaveImage.cpp )
target_link_libraries( SaveImage ${OpenCV_LIBS})

add_executable( SaveAndLoad32FC1Image SaveAndLoad32FC1Image.cpp )
target_link_libraries( SaveAndLoad32FC1Image ${OpenCV_LIBS})
