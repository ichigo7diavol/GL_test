TEMPLATE = app
CONFIG += c++11 c++14 #console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += "C:\Users\Arhon\Documents\m_bins_and_libs\glfw-3.2.1.bin.WIN32\include" \
               "C:\Users\Arhon\Documents\m_bins_and_libs\glew-2.1.0\include"

LIBS += -L"C:\Users\Arhon\Documents\m_bins_and_libs\glfw-3.2.1.bin.WIN32\lib-mingw" -lglfw3dll \
        -L"C:\Users\Arhon\Documents\m_bins_and_libs\glew-2.1.0\bin\Release\Win32" -lglew32 \
        -lopengl32 -lglu32

HEADERS += \
    linmath.h
