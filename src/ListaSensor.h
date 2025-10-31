#ifndef LISTA_SENSOR_H
#define LISTA_SENSOR_H

#include <iostream>
#include <cstddef> // Para nullptr
#include <limits>  // Para std::numeric_limits

/**
 * @file ListaSensor.h
 * @brief Implementación de una Lista Enlazada Simple Genérica (template).
 * * Esta clase gestiona una lista enlazada de tipo T y cumple
 * con la Regla de los Tres para el manejo manual de memoria.
 */
template <typename T>
class ListaSensor {
private:
    /**
     * @struct Nodo
     * @brief Estructura interna anidada para los nodos de la lista.
     */
    struct Nodo {
        T dato;
        Nodo* siguiente;

        /**
         * @brief Constructor del Nodo.
         * @param d El dato de tipo T a almacenar.
         */
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    int tamano;

    /**
     * @brief Función auxiliar para copiar otra lista (deep copy).
     * @param otra La lista a copiar.
     */
    void copiar(const ListaSensor& otra) {
        cabeza = nullptr;
        tamano = 0;
        Nodo* temp = otra.cabeza;
        while (temp != nullptr) {
            insertarAlFinal(temp->dato);
            temp = temp->siguiente;
        }
    }

    /**
     * @brief Función auxiliar para limpiar (borrar) toda la lista.
     */
    void limpiar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* aBorrar = actual;
            actual = actual->siguiente;
            std::cout << "    [Log] Nodo<T> " << aBorrar->dato << " liberado." << std::endl;
            delete aBorrar;
        }
        cabeza = nullptr;
        tamano = 0;
    }

public:
    /**
     * @brief Constructor por defecto.
     */
    ListaSensor() : cabeza(nullptr), tamano(0) {}

    // --- Implementación de la Regla de los Tres ---

    /**
     * @brief 1. Destructor. Libera toda la memoria de los nodos.
     */
    ~ListaSensor() {
        limpiar();
    }

    /**
     * @brief 2. Constructor de Copia (Deep Copy).
     * @param otra La lista a copiar.
     */
    ListaSensor(const ListaSensor& otra) {
        copiar(otra);
    }

    /**
     * @brief 3. Operador de Asignación (Copy-and-Swap idiom).
     * @param otra La lista a asignar.
     * @return Referencia a esta lista (*this).
     */
    ListaSensor& operator=(const ListaSensor& otra) {
        if (this != &otra) { // Evitar auto-asignación
            limpiar(); // Limpiar datos antiguos
            copiar(otra); // Copiar nuevos datos
        }
        return *this;
    }

    /**
     * @brief Inserta un nuevo dato al final de la lista.
     * @param dato El dato de tipo T a insertar.
     */
    void insertarAlFinal(T dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
        tamano++;
    }

    /**
     * @brief Imprime todos los elementos de la lista.
     */
    void imprimir() const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }

    int getTamano() const { return tamano; }
    bool estaVacia() const { return cabeza == nullptr; }

    /**
     * @brief Calcula el promedio de todos los elementos en la lista.
     * @return El promedio (double), o 0 si la lista está vacía.
     */
    double calcularPromedio() const {
        if (estaVacia()) return 0.0;
        
        double suma = 0.0;
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            suma += static_cast<double>(temp->dato);
            temp = temp->siguiente;
        }
        return suma / tamano;
    }

    /**
     * @brief Encuentra el valor más bajo y lo elimina de la lista.
     * @return El valor mínimo que fue eliminado.
     */
    T encontrarYQuitarMinimo() {
        if (estaVacia()) {
            return T(); // Retorna valor por defecto (0, 0.0, etc.)
        }

        T minVal = cabeza->dato;
        Nodo* minNodoPrev = nullptr;
        Nodo* minNodo = cabeza;

        Nodo* prev = nullptr;
        Nodo* actual = cabeza;

        // Encontrar el mínimo
        while (actual != nullptr) {
            if (actual->dato < minVal) {
                minVal = actual->dato;
                minNodoPrev = prev;
                minNodo = actual;
            }
            prev = actual;
            actual = actual->siguiente;
        }

        // Eliminar el nodo mínimo
        if (minNodo == cabeza) { // El mínimo es la cabeza
            cabeza = minNodo->siguiente;
        } else { // El mínimo está en otro lugar
            minNodoPrev->siguiente = minNodo->siguiente;
        }

        std::cout << "    [Log] Nodo<T> " << minNodo->dato << " (min) eliminado." << std::endl;
        delete minNodo;
        tamano--;
        return minVal;
    }
};

#endif // LISTA_SENSOR_H