win32:CONFIG(debug, debug | release) {
    QMAKE_CXXFLAGS += /Zi /MP10 /MDd
}
