/**
 * @file Codigo dispensador. 
 *
 * @brief Este el código oficial que se usa para el dispensador alcohol.
 */

// CREACIÓN DE LAS CONSTANTES
const int rele = 2;        ///< Número del pin para el relé que acciona la bomba
int trig = 12;             ///< Número del pin para el pin de disparo (trig) del sensor ultrasónico
int echo = 11;             ///< Número del pin para el pin de eco (echo) del sensor ultrasónico
float distancia;           ///< Distancia de activación del sensor ultrasónico
long duracion;             ///< Duración en la que se mantiene activo el sensor ultrasónico
int pot;                   ///< Variable para leer el valor del potenciómetro (0 a 1023)
int cantidad;              ///< Variable para relacionar el valor del potenciómetro con la cantidad de alcohol
int led_rojo = 5;          ///< Número del pin para el LED rojo
int led_verde = 6;         ///< Número del pin para el LED verde
const int buzzer = 9;      ///< Número del pin para el zumbador

void setup() {
  Serial.begin(9600);             // Iniciar el puerto serie
  pinMode(rele, OUTPUT);          // Configurar el pin como salida para el relé
  pinMode(trig, OUTPUT);          // Configurar el pin de disparo (trig) como salida
  pinMode(echo, INPUT);           // Configurar el pin de eco (echo) como entrada
  pinMode(led_rojo, OUTPUT);      // Configurar el pin del LED rojo como salida
  pinMode(led_verde, OUTPUT);     // Configurar el pin del LED verde como salida
  pinMode(buzzer, OUTPUT);        // Configurar el pin del zumbador como salida
}

void loop() {
  // Código para leer el potenciómetro
  pot = analogRead(A0);            // Leer el valor del potenciómetro (va de 0 a 1023)
  cantidad = pot / 10.23;          // Relacionar el valor del potenciómetro con la cantidad de alcohol (de 0 a 100)
  Serial.print("Cantidad es de = "); // Imprimir mensaje sobre la cantidad de alcohol
  Serial.println(cantidad);        // Imprimir la cantidad de alcohol (duración de la bomba en milisegundos)

  // Código para el sensor ultrasónico
  digitalWrite(trig, LOW);        // Apagar el sensor ultrasónico
  delayMicroseconds(2);            // Esperar durante un breve tiempo
  digitalWrite(trig, HIGH);       // Encender el sensor ultrasónico
  delayMicroseconds(10);           // Esperar durante un breve tiempo
  digitalWrite(trig, LOW);        // Apagar el sensor ultrasónico
  duracion = pulseIn(echo, HIGH);  // Obtener la duración del eco del sensor ultrasónico
  distancia = duracion / 57.8;     // Convertir el tiempo en distancia (cm)
  Serial.print(distancia);         // Monitorear la distancia de activación
  Serial.println("cm");            // Monitorear la distancia de activación

  digitalWrite(led_rojo, LOW);
  digitalWrite(led_verde, HIGH);

    // Código para accionar la bomba
  if (distancia <= 12 && distancia > 7) { // Definir el rango de funcionamiento del sensor para la bomba
    delay(500);                       // Demora antes de activar la bomba después de que se active el sensor
    digitalWrite(rele, HIGH);         // Activar la bomba
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, HIGH);
    delay(cantidad);                   // Duración en la que la bomba debe estar activa (define la cantidad de alcohol)
    digitalWrite(rele, LOW);          // Desactivar la bomba

    analogWrite(buzzer, 5000);
    delay(3000);                       // Demora antes de que la bomba pueda funcionar nuevamente si se utiliza continuamente
    analogWrite(buzzer, 0);
  }

  //delay(100); // Este delay es para reducir la cantidad de lecturas consecutivas del sensor
}