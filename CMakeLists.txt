cmake_minimum_required(VERSION 3.5.0)   

set(PROJECT_NAME main)   #변수세팅 PROJECT_NAME을 main라고 그냥 설정 
set(CMAKE_CXX_STANDARD 17)  #cmake로 시작하는 값을 어떻게 세팅하냐에 따라 달라짐 cxx=c++, -> c++ 17 이런느낌 

project(main VERSION 0.1.0 LANGUAGES C CXX)   #main이라는 프로젝트로 0.1.0버전이며 c,c++사용
add_executable(main main.cpp) #main이라는 실행파일이 main.cpp로부터 만들어짐

#cmake -Bbuild . -DCMAKE_BUILD_TYPE=Debug  configure하는법  기본적인방법임
#cmake --build build --config Debug  build하는법