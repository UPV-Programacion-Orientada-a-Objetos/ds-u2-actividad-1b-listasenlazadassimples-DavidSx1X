#include "SensorPresion.h"
#include <iostream>
#include <cstdlib> // Para atoi

SensorPresion::SensorPresion(const char* n) : SensorBase(n) {}

SensorPresion::~SensorPresion() {
    std::cout << "    [Log] Lista interna de " << nombre << " liberada por su destructor." << std::endl;
}

void SensorPresion::agregarLectura(const char* valor) {
    int val = atoi(valor); // Convertir string a int
    historial.insertarAlFinal(val);
    std::cout << "[Log] Insertando Nodo<int> " << val << " en " << nombre << "." << std::endl;
}

void SensorPresion::procesarLectura() {
    std::cout << "-> Procesando Sensor " << nombre << " (Presion)..." << std::endl;
    if (historial.estaVacia()) {
        std::cout << "   [Sensor Presion] No hay lecturas para procesar." << std::endl;
        return;
    }

    // Lógica: "calcular el promedio"
    double prom = historial.calcularPromedio();
    std::cout << "   [Sensor Presion] Promedio calculado sobre " << historial.getTamano() 
              << " lecturas: " << prom << "." << std::endl;
}

void SensorPresion::imprimirInfo() const {
    std::cout << "--- Info Sensor [" << nombre << "] (Presion, int) ---" << std::endl;
    historial.imprimir();
}