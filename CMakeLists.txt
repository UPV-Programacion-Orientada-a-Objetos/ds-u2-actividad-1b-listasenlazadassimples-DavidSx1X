# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SistemaSensores CXX)

# Usar C++11 o superior
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- ¡AQUÍ ESTÁ LA AGREGACIÓN! ---
# Soluciona el 'choque silencioso' en Windows con MinGW
# Incrusta las librerías C++ para que el .exe sea independiente
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

# Definir el ejecutable y sus archivos fuente
add_executable(GestorSensores
    src/main.cpp
    src/SensorBase.cpp
    src/SensorTemperatura.cpp
    src/SensorPresion.cpp
    src/GestionSensores.cpp
)

# ------- Integración con Doxygen (Opcional pero requerido) -------

# Encontrar el paquete de Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
    # Definir dónde está el archivo de configuración de Doxygen (Doxyfile)
    # (Necesitarás crear uno: 'doxygen -g Doxyfile')
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc)

    # Crear un target de CMake para generar la documentación
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generando documentación con Doxygen..."
        VERBATIM
    )
else()
    message(WARNING "Doxygen no encontrado. El target 'doc' no estará disponible.")
endif()