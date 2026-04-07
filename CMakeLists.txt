cmake_minimum_required(VERSION 3.19)
project(Lab1PasswordMng LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

set(OPENSSL_ROOT "C:/Qt/Tools/mingw1310_64/opt")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT}/include")
set(OPENSSL_LIBCRYPTO "${OPENSSL_ROOT}/lib/libcrypto.dll.a")

qt_standard_project_setup()

qt_add_executable(Lab1PasswordMng
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    account.h
    accounttablemodel.h
    accounttablemodel.cpp
    accountrepository.h accountrepository.cpp
)

target_link_libraries(Lab1PasswordMng
    PRIVATE
        Qt::Core
        Qt::Widgets
        "${OPENSSL_LIBCRYPTO}"
)

target_include_directories(Lab1PasswordMng PRIVATE
      src
      "${OPENSSL_INCLUDE_DIR}"
  )


install(TARGETS Lab1PasswordMng
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Lab1PasswordMng
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
