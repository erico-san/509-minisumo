
// es con ESP32 Devkit
#include "driver/mcpwm.h"
#include "BluetoothSerial.h"
String Nombre = "509";
BluetoothSerial BT;

// motores
#define a_black 18
#define a_red 5
#define b_red 16
#define b_black 19

unsigned char estado = 0;

//sobre 100, no sobre 255
int Speed = 30; 
int Speed_max = 100;
int diag = 20;

void setup(){
  BT.begin(Nombre); // mod para esp32

  // Configuración de pines de los motores como salidas
  config_motor();

  Serial.begin(9600);   // Configuramos el serial 
}

int cont=0;
void loop()
{
  estado = 0; // no guardar el último valor
  if (BT.available()) // mod para esp32
  {
    estado = BT.read(); // mod para esp32
    botonex();
  }
}

void botonex() // Función que procesa los comandos recibidos
{
  switch (estado){
   case 'F': // Adelante
    motor(Speed, Speed);
    break;

  case 'B': // Atrás
    motor(-Speed, -Speed);
    break;

  case 'L': // Izquierda
    motor(-Speed, Speed);
    break;

  case 'R': // Derecha
    motor(Speed, -Speed);
    break;

  case 'G': // Adelante izquierda 
    motor(Speed - diag, Speed + diag); //180
    break; 

  case 'I': // Adelante derecha 
    motor(Speed + diag, Speed - diag);
    break;

  case 'H': // Atrás izquierda 
    motor(-Speed + diag, -Speed - diag); //180
    break;    
 
  case 'J': // Atrás derecha }
    motor(-Speed - diag, -Speed + diag);
    break;
    
  case 'S': // Stop: Se activa frenado dinámico
    motor(0, 0);
    break;
    
  case '0':
    Speed = 0.1*Speed_max;
    break;
  case '1':
    Speed = 0.2*Speed_max;
    break;
  case '2':
    Speed = 0.3*Speed_max;
    break;
  case '3':
    Speed = 0.4*Speed_max;
    break;
  case '4':
    Speed = 0.5*Speed_max;
    break;
  case '5':
    Speed = 0.6*Speed_max;
    break;
  case '6':
    Speed = 0.7*Speed_max;
    break;
  case '7':
    Speed = 0.8*Speed_max;
    break;
  case '8':
    Speed = 0.9*Speed_max;
    break;
  case '9':
    Speed = 1.0*Speed_max;
    break;
  } 
}

