cmake_minimum_required(VERSION 3.5.0)   

set(PROJECT_NAME main)   #변수세팅 PROJECT_NAME을 main라고 그냥 설정 
set(CMAKE_CXX_STANDARD 17)  #cmake로 시작하는 값을 어떻게 세팅하냐에 따라 달라짐 cxx=c++, -> c++ 17 이런느낌 

project(main VERSION 0.1.0 LANGUAGES C CXX)   #main이라는 프로젝트로 0.1.0버전이며 c,c++사용
add_executable(main main.cpp) #main이라는 실행파일이 main.cpp로부터 만들어짐

#cmake -Bbuild . -DCMAKE_BUILD_TYPE=Debug  configure하는법  기본적인방법임
#cmake --build build --config Debug  build하는법

# ExternalProject 관련 명령어 셋 추가
include(ExternalProject)

# Dependency 관련 변수 설정
set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

# spdlog: fast logger library
ExternalProject_Add(
    dep-spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
    TEST_COMMAND ""
)
# Dependency 리스트 및 라이브러리 파일 리스트 추가
set(DEP_LIST ${DEP_LIST} dep-spdlog)
set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>)

# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})