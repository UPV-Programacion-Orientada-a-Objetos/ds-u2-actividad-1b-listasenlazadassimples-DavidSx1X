#include "SensorTemperatura.h"
#include <iostream>
#include <cstdlib> // Para atof

SensorTemperatura::SensorTemperatura(const char* n) : SensorBase(n) {}

// El destructor de historial (ListaSensor<float>) se llamará automáticamente
SensorTemperatura::~SensorTemperatura() {
    std::cout << "    [Log] Lista interna de " << nombre << " liberada por su destructor." << std::endl;
}

void SensorTemperatura::agregarLectura(const char* valor) {
    float val = static_cast<float>(atof(valor)); // Convertir string a float
    historial.insertarAlFinal(val);
    std::cout << "[Log] Insertando Nodo<float> " << val << " en " << nombre << "." << std::endl;
}

void SensorTemperatura::procesarLectura() {
    std::cout << "-> Procesando Sensor " << nombre << " (Temperatura)..." << std::endl;
    if (historial.estaVacia()) {
        std::cout << "   [Sensor Temp] No hay lecturas para procesar." << std::endl;
        return;
    }
    
    // Lógica: "eliminar el valor más bajo"
    float minVal = historial.encontrarYQuitarMinimo();
    std::cout << "   [Sensor Temp] Lectura más baja (" << minVal << ") eliminada." << std::endl;
    
    // Lógica: "calcular promedio restante"
    double prom = historial.calcularPromedio();
    std::cout << "   [Sensor Temp] Promedio restante sobre " << historial.getTamano() 
              << " lecturas: " << prom << "." << std::endl;
}

void SensorTemperatura::imprimirInfo() const {
    std::cout << "--- Info Sensor [" << nombre << "] (Temperatura, float) ---" << std::endl;
    historial.imprimir();
}