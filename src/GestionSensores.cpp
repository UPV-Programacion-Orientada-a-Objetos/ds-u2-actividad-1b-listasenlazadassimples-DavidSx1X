#include "GestionSensores.h"
#include <iostream>
#include <cstring> // Para strcmp

GestionSensores::GestionSensores() : cabeza(nullptr) {}

GestionSensores::~GestionSensores() {
    std::cout << "\n--- Liberación de Memoria en Cascada ---" << std::endl;
    NodoGestion* actual = cabeza;
    while (actual != nullptr) {
        NodoGestion* aBorrar = actual;
        actual = actual->siguiente;

        std::cout << "[Destructor General] Liberando Nodo: " << aBorrar->sensor->getNombre() << "." << std::endl;
        
        // ¡Aquí ocurre la magia!
        // 1. Se llama a delete en un puntero SensorBase*.
        // 2. Gracias al destructor VIRTUAL, se invoca al ~SensorPresion() o ~SensorTemperatura().
        // 3. El destructor de la derivada se ejecuta (imprime su log).
        // 4. El destructor de la derivada termina.
        // 5. Se invoca al destructor de la base ~SensorBase().
        // 6. El destructor de ListaSensor<T> (miembro de la derivada) se invoca, liberando la lista interna.
        delete aBorrar->sensor; // Llama al destructor virtual
        
        delete aBorrar; // Libera el nodo de la lista de gestión
    }
    std::cout << "Sistema cerrado. Memoria limpia." << std::endl;
}

void GestionSensores::agregarSensor(SensorBase* nuevoSensor) {
    NodoGestion* nuevoNodo = new NodoGestion(nuevoSensor);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        NodoGestion* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    std::cout << "Sensor '" << nuevoSensor->getNombre() << "' creado e insertado en la lista de gestión." << std::endl;
}

SensorBase* GestionSensores::buscarSensor(const char* nombre) {
    NodoGestion* temp = cabeza;
    while (temp != nullptr) {
        if (strcmp(temp->sensor->getNombre(), nombre) == 0) {
            return temp->sensor;
        }
        temp = temp->siguiente;
    }
    return nullptr; // No encontrado
}

void GestionSensores::procesarTodos() {
    std::cout << "\n--- Ejecutando Procesamiento Polimórfico ---" << std::endl;
    NodoGestion* temp = cabeza;
    if (temp == nullptr) {
        std::cout << "No hay sensores en el sistema." << std::endl;
        return;
    }
    while (temp != nullptr) {
        temp->sensor->procesarLectura(); // ¡Polimorfismo en acción!
        temp = temp->siguiente;
    }
}

void GestionSensores::imprimirTodos() const {
    std::cout << "\n--- Estado Actual de Sensores ---" << std::endl;
    NodoGestion* temp = cabeza;
     if (temp == nullptr) {
        std::cout << "No hay sensores en el sistema." << std::endl;
        return;
    }
    while (temp != nullptr) {
        temp->sensor->imprimirInfo();
        temp = temp->siguiente;
    }
}