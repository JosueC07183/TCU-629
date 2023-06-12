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


void setup() {
  Serial.begin(9600);
  pinMode(rele , OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
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


    if(distancia <=15 && distancia>7){ 
    delay(300);
    digitalWrite(rele, HIGH);
    delay(cantidad);
    digitalWrite(rele, LOW);
    delay(10000);
  	}

    delay(100);
  }
  ```

