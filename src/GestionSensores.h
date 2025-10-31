#ifndef GESTION_SENSORES_H
#define GESTION_SENSORES_H

#include "SensorBase.h" // Almacena punteros a este tipo

/**
 * @class GestionSensores
 * @brief Implementa la lista enlazada principal NO genérica
 * para almacenar punteros polimórficos a SensorBase*.
 */
class GestionSensores {
private:
    /**
     * @struct NodoGestion
     * @brief Nodo para la lista de gestión. Almacena el puntero.
     */
    struct NodoGestion {
        SensorBase* sensor; // Puntero a la clase base
        NodoGestion* siguiente;

        NodoGestion(SensorBase* s) : sensor(s), siguiente(nullptr) {}
    };

    NodoGestion* cabeza;

public:
    GestionSensores();
    /**
     * @brief Destructor de la lista de gestión.
     * ¡CRÍTICO! Debe iterar y hacer 'delete' de cada puntero SensorBase*
     * para invocar la cadena de destructores virtuales.
     */
    ~GestionSensores();

    // Prohibir copia para evitar problemas de doble 'delete'
    GestionSensores(const GestionSensores&) = delete;
    GestionSensores& operator=(const GestionSensores&) = delete;

    /**
     * @brief Agrega un nuevo sensor (ya creado con 'new') a la lista.
     * @param nuevoSensor Puntero al sensor a agregar.
     */
    void agregarSensor(SensorBase* nuevoSensor);

    /**
     * @brief Busca un sensor por su nombre.
     * @param nombre El ID (nombre) del sensor a buscar.
     * @return Puntero al SensorBase* o nullptr si no se encuentra.
     */
    SensorBase* buscarSensor(const char* nombre);

    /**
     * @brief Itera sobre todos los sensores y llama a su método polimórfico.
     */
    void procesarTodos();
    
    /**
     * @brief Imprime la información de todos los sensores.
     */
    void imprimirTodos() const;
};

#endif // GESTION_SENSORES_H