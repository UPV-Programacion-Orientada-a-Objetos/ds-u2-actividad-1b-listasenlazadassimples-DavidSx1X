#include <iostream>
#include "GestionSensores.h"
#include "SensorTemperatura.h"
#include "SensorPresion.h"

// Función auxiliar para leer líneas de forma segura sin std::string
void leerLinea(char* buffer, int tam) {
    std::cin.getline(buffer, tam);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void mostrarMenu() {
    std::cout << "\n--- Sistema IoT de Monitoreo Polimórfico ---" << std::endl;
    std::cout << "1. Crear Sensor (Tipo Temp - FLOAT)" << std::endl;
    std::cout << "2. Crear Sensor (Tipo Presion - INT)" << std::endl;
    std::cout << "3. Registrar Lectura" << std::endl;
    std::cout << "4. Ejecutar Procesamiento Polimórfico" << std::endl;
    std::cout << "5. Imprimir Estado de Sensores" << std::endl;
    std::cout << "6. Salir (Liberar Memoria)" << std::endl;
    std::cout << "Opcion: ";
}

int main() {
    GestionSensores sistema;
    bool salir = false;
    char opcion[10];
    char idSensor[50];
    char valorLectura[20];

    while (!salir) {
        mostrarMenu();
        leerLinea(opcion, 10);
        int op = atoi(opcion);

        switch (op) {
            case 1: // Crear Sensor Temp
                std::cout << "ID para nuevo sensor de Temp: ";
                leerLinea(idSensor, 50);
                // Usamos 'new' para crear el objeto en el heap
                sistema.agregarSensor(new SensorTemperatura(idSensor));
                break;
            
            case 2: // Crear Sensor Presion
                std::cout << "ID para nuevo sensor de Presion: ";
                leerLinea(idSensor, 50);
                sistema.agregarSensor(new SensorPresion(idSensor));
                break;

            case 3: { // Registrar Lectura
                std::cout << "ID del sensor para registrar: ";
                leerLinea(idSensor, 50);
                SensorBase* sensor = sistema.buscarSensor(idSensor);
                if (sensor != nullptr) {
                    std::cout << "Valor de la lectura: ";
                    leerLinea(valorLectura, 20);
                    sensor->agregarLectura(valorLectura); // Polimorfismo
                } else {
                    std::cout << "Error: Sensor con ID '" << idSensor << "' no encontrado." << std::endl;
                }
                break;
            }

            case 4: // Procesamiento Polimórfico
                sistema.procesarTodos();
                break;

            case 5: // Imprimir Estado
                sistema.imprimirTodos();
                break;

            case 6: // Salir
                salir = true;
                std::cout << "Cerrando sistema..." << std::endl;
                break;

            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    }

    // Al salir del main, la variable 'sistema' (GestionSensores)
    // sale del scope, y su destructor (~GestionSensores) es invocado,
    // comenzando la liberación en cascada.
    return 0;
}