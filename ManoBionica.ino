////****SERVOMOTORES PARA EL CONTROL DE MANO ROBOTICA***////
#include <Servo.h> //libreria servo
Servo servo1;   //objeto servo EXTRA PULGAR
int pos = 0;    //posicion del servo
Servo servo2;   //objeto servo PULGAR
int pos2 = 0;   //posicion del servo
Servo servo3;   //objeto servo INDICE
int pos3 = 0;   //posicion del servo
Servo servo4;   //objeto servo MEDIO
int pos4 = 0;   //posicion del servo
Servo servo5;   //objeto servo ANULAR
int pos5 = 0;   //posicion del servo
Servo servo6;   //objeto servo MEÑIQUE
int pos6 = 0;   //posicion del servo

///******5 POTENCIONETROS DEL EXOESQUELETO***////
int sensor = A1;
int lecturaSensor = 0;
int sensor2 = A2;
int lecturaSensor2 = 0;
int sensor3 = A3;
int lecturaSensor3 = 0;
int sensor4 = A4;
int lecturaSensor4 = 0;
int sensor5 = A5;
int lecturaSensor5 = 0;


void setup() {
  Serial.begin(9600);
  ///****PINES PWM DE CONEXION DE LOS SERVOS****///
  servo1.attach(2); //servo conectado en el pin 3
  servo2.attach(3); //servo conectado en el pin 3
  servo3.attach(4); //servo conectado en el pin 3
  servo4.attach(5); //servo conectado en el pin 3
  servo5.attach(6); //servo conectado en el pin 3
  servo6.attach(7); //servo conectado en el pin 3
  ///*****POSICION INICIAL DE SERVOS****////
  servo1.write(160);
  servo2.write(160);
  servo3.write(160);
  servo4.write(160);
  servo5.write(160);
  servo6.write(160);
}

void loop() 
{
  ////****LECTURA****////
  lecturaSensor  = analogRead(sensor);
  lecturaSensor2 = analogRead(sensor2);
  lecturaSensor3 = analogRead(sensor3);
  lecturaSensor4 = analogRead(sensor4);
  lecturaSensor5 = analogRead(sensor5);

  Serial.print(lecturaSensor);
  Serial.print(",");
  Serial.print(lecturaSensor2);
  Serial.print(",");
  Serial.print(lecturaSensor3);
  Serial.print(",");
  Serial.print(lecturaSensor4);
  Serial.print(",");
  Serial.print(lecturaSensor5);

  ///***MAPEO DE SEÑAL POT-SERVO****////
  ///****posiciones PULGAR***////
  pos = map(lecturaSensor, 800, 700, 160, 50); //0=0°y 1023 = 180°
  servo1.write(pos);  //escribe la posicion del pot en el servo
  servo6.write(pos);

  //****posiciones INDICE****///
  pos2 = map(lecturaSensor2, 850, 750, 160, 50);
  servo2.write(pos2);

  //****posiciones MEDIO***///
  pos3 = map(lectiraSensor3, 520, 420, 160, 50);
  servo3.write(pos3);

  //****posiciones ANULAR***///
  pos4 = map(lectiraSensor4, 900, 800, 160, 50);
  servo4.write(pos4);

  //****posiciones MEÑIQUE***///
  pos5 = map(lectiraSensor5, 900, 800, 160, 50);
  servo5.write(pos5);
}
