//CREACIÓN DE LAS CONSTANTES
const int rele = 2; // rele que acciona la bomba
int trig = 12; // trig del sensor
int echo = 11; // echo del sensor
float distancia; // distancia de accionamiento del sensor
long duracion; // duración que se mantiene activa el sensor
int pot; // variable para definir el potenciometro de 0 a 1023
int cantidad; // variable para relacionar el potenciometro a la cantidad de alcohol


void setup() {
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(rele , OUTPUT);  //definir pin como salida
  pinMode(trig, OUTPUT); // trig salida
  pinMode(echo, INPUT); // echo entrada
}
 
void loop(){

  //Código para el potenciómetro
    pot = analogRead(A0); // lectura del potenciometro (va de 0 a 1023)
    cantidad = pot/10.23; // relación del potenciometro a la cantidad que se quiere (de 0  100)
    Serial.print("Cantidad es de = "); // se imprime el dialogo de cantidad
    Serial.println(cantidad); // se imprime la cantidad (duracion de la bomba en milisegundos)

  //Código del sensor
    digitalWrite(trig, LOW); // se apaga el sensor
    delayMicroseconds(2); // duración apagado ms
    digitalWrite(trig, HIGH); // se enciende el sensor
    delayMicroseconds(10); // duracion encendido en ms
    digitalWrite(trig, LOW); // se apaga el sensor
    duracion = pulseIn(echo, HIGH); // guarda el accionar del sensor
    distancia = duracion/57.8; // transforma el tiempo accionado en distancia 
    Serial.print(distancia); // se monitorea la distancia de accionado
    Serial.println("cm"); //// se monitorea la distancia de accionado


    //Código para el accionar de la bomba
    if(distancia <=15 && distancia>7){ // se define el rango de funcionamiento del sensor para la bomba
    delay(300) ; // demora para que se accion la bomba al activarse el sensor
    digitalWrite(rele, HIGH); // activar la bomba 
    delay(cantidad); // duración que debe durar la bomba activa, esto define la cantidad de alcohol 
    digitalWrite(rele, LOW); // se desactiva la bomba
    delay(10000); // demora para que vuelva a funcionar la bomba en caso de utilizarse seguido
  	}

    delay(100); // este delay es para reducir la cantidad de lecturas seguidas del sensor
  }