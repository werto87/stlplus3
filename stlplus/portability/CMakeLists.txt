
target_sources(stlplus PUBLIC
        dprintf.cpp
        dynaload.cpp
        build.cpp
        debug.cpp
        file_system.cpp
        inf.cpp
        ip_sockets.cpp
        portability_fixes.cpp
        subprocesses.cpp
        tcp_sockets.cpp
        time.cpp
        udp_sockets.cpp
        version.cpp
        wildcard.cpp
)

install(FILES
        build.hpp
        debug.hpp
        dprintf.hpp
        dynaload.hpp
        file_system.hpp
        inf.hpp
        ip_sockets.hpp
        portability_exceptions.hpp
        portability_fixes.hpp
        portability.hpp
        subprocesses.hpp
        tcp_sockets.hpp
        time.hpp
        udp_sockets.hpp
        version.hpp
        wildcard.hpp
        DESTINATION include/stlplus/portability
)




