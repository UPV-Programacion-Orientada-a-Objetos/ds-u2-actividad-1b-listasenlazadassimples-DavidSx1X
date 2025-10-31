#include "SensorBase.h"
#include <cstring> // Para strncpy
#include <iostream>

SensorBase::SensorBase(const char* n) {
    // Copia segura de C-string
    strncpy(nombre, n, 49);
    nombre[49] = '\0'; // Asegurar terminación nula
}

// Aunque sea virtual y vacío, debe ser definido.
SensorBase::~SensorBase() {
    std::cout << "  [Destructor Sensor " << nombre << "] Limpiando..." << std::endl;
}

const char* SensorBase::getNombre() const {
    return nombre;
}