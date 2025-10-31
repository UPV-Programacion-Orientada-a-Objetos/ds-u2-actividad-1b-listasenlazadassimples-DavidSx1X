/**
 * Simulador.ino
 *
 * Este sketch simula el envío de datos de dos sensores (T-001 y P-105)
 * a través del puerto serial.
 *
 * El programa C++ en la PC debería leer este puerto.
 */

void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
  while (!Serial) {
    ; // Esperar a que el puerto serial se conecte
  }
  Serial.println("Simulador de Sensores Arduino INICIADO");
}

void loop() {
  // Simular lecturas de T-001 (float)
  float tempVal = random(400, 480) / 10.0; // Valor entre 40.0 y 47.9
  Serial.print("T-001:");
  Serial.println(tempVal);
  delay(2000); // Esperar 2 segundos

  // Simular lecturas de P-105 (int)
  int presVal = random(80, 90); // Valor entre 80 y 89
  Serial.print("P-105:");
  Serial.println(presVal);
  delay(2000);

  // Simular otra lectura de T-001
  tempVal = random(400, 480) / 10.0;
  Serial.print("T-001:");
  Serial.println(tempVal);
  delay(2000);
  
  // Simular otra lectura de P-105
  presVal = random(80, 90);
  Serial.print("P-105:");
  Serial.println(presVal);
  delay(2000);
}