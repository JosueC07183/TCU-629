## En esta carpeta encontrará el código que le da vida a la estructura de nuestro dispensador.
---
- En el archivo .ino se muestra la documentación del código.

```
const int rele = 2;
int trig = 12;
int echo = 11;
float distancia;
long duracion;
int pot;
int cantidad;
int led_rojo = 5;
int led_verde= 6;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(rele , OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_rojo, OUTPUT); 
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);   
}
 
void loop(){

    pot = analogRead(A0);
    cantidad = pot/10.23;
    Serial.print("Cantidad es de = ");
    Serial.println(cantidad);

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duracion = pulseIn(echo, HIGH);
    distancia = duracion/57.8;
    Serial.print(distancia);
    Serial.println("cm");

    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
    
    //Código para el accionar de la bomba
    if(distancia <=12 && distancia>7){ 
    delay(500) ; 
    digitalWrite(rele, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, HIGH); 
    delay(cantidad);
    digitalWrite(rele, LOW);
    
    analogWrite (buzzer,5000); 
    delay(3000); 
    analogWrite (buzzer,0);
  	}

    //delay(100); // este delay es para reducir la cantidad de lecturas seguidas del sensor
  }  ```

