#ifndef SENSOR_BASE_H
#define SENSOR_BASE_H

/**
 * @file SensorBase.h
 * @brief Clase Base Abstracta para todos los sensores.
 * * Define la interfaz común polimórfica.
 */
class SensorBase {
protected:
    char nombre[50];

public:
    /**
     * @brief Constructor.
     * @param n Nombre del sensor (se copiará).
     */
    SensorBase(const char* n);

    /**
     * @brief Destructor Virtual.
     * ¡CRÍTICO! Asegura que se llame al destructor de la clase derivada
     * correcta al hacer delete de un puntero SensorBase*.
     */
    virtual ~SensorBase();

    // --- Métodos Virtuales Puros (Interfaz) ---

    /**
     * @brief Procesa las lecturas almacenadas (lógica específica del sensor).
     */
    virtual void procesarLectura() = 0;

    /**
     * @brief Imprime la información y estado actual del sensor.
     */
    virtual void imprimirInfo() const = 0;

    /**
     * @brief Agrega una nueva lectura (como string) para ser parseada.
     * @param valor La lectura en formato de cadena de texto.
     */
    virtual void agregarLectura(const char* valor) = 0;

    /**
     * @brief Obtiene el nombre del sensor.
     * @return const char* al nombre.
     */
    const char* getNombre() const;
};

#endif // SENSOR_BASE_H