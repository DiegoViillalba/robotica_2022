//DECLARAMOS VARIABLES QUE SE OCUPARÁN ola de saludo 

/// Comentario de version
//prueba de ola


int motor; //Declaramos la variable motores del tipo entero
int sensor; //Declaramos la variable sensor del tipo entero
int i; //Declaramos la variable i del tipo entero
int potencia; //Declaramos la variable i del tipo entero
char memoria; //Variable de memoria para el caso donde esta en blanco
bool s1 = 0;
bool s2 = 0;
bool s3 = 0;
bool sentido = 0;

void setup() 
{
  Serial.begin(9600);//Inicializamos comunicación serial
  pinMode(A2, INPUT);//Declaramos A2 como salida al sensor Derecho
  pinMode(A3, INPUT);//Declaramos A3 como salida al sensor Centro
  pinMode(A4, INPUT);//Declaramos A4 como salida al sensor Izquierda
  pinMode(6, OUTPUT);//Declaramos A2 como salida al Motor Derecha
  pinMode(5, OUTPUT);//Declaramos A2 como salida al Motor Izquierda
}

//DEFINIMOS FUNCIONES DE NUESTROS MOTORES

// Definimos la funciones de nuestrs motorores
 void Motor1(int i, int potencia)
  {
    analogWrite(5,potencia); //Se habilita el motor 1 
  }

// Definimos funcion del motor 2
void Motor2(int i, int potencia)
  {
    analogWrite(6,potencia); //Se habilita el motor 1 
  }
  
//Definimos una funcion que indique el movimiento de nuestro carro, Hacia adelante
void adelante(){
    Motor1(i=0, potencia = 255);
    Motor2(i=0, potencia = 255);
  }
//Definimos una funcion que indique el movimiento de nuestro carro, Hacia atras
void atras(){
    Motor1(i=1, potencia = 255);
    Motor2(i=1, potencia = 255);
  }
//Definimos una funcion que indique el movimiento de nuestro carro, Hacia la derecha
void derecha(){
    Motor1(i=0, potencia = 255);
    Motor2(i=0, potencia = 100);
    // Imprimimos potencia del motor resultante
  Serial.println("Potencia del motor: 255");
  }
//Definimos una funcion que indique el movimiento de nuestro carro, Hacia la izquierda 
void izquierda(){
    Motor1(i=0, potencia = 100);
    Motor2(i=0, potencia = 255);
    Serial.println("Potencia del motor: 255");
  }
//Definimos una funcion que indique el movimiento de nuestro carro, Deniene el movimiento
void alto(){
    Motor1(i=2, potencia = 255);
    Motor2(i=2, potencia = 255);
  }

void loop() {
  
  //DECLARAMOS VARIABLES
  s1 = digitalRead(A4);//Declaramos las variables de lectura para un sensor tipo boolena
  s2 = digitalRead(A3);//Declaramos las variables de lectura para un sensor tipo boolena
  s3 = digitalRead(A2);//Declaramos las variables de lectura para un sensor tipo boolena
  //1=Negro       0=blanco

  //IMPRIMIMOS EN PANTALLA LO QUE LEEN NUESTROS SENSORERES
  Serial.println("Sensor izquierda    Sensor Centro     Sensor Derecha");//Imprimimos en pantalla
  Serial.print(s1);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.print(s2);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.println(s3);//Imprimimos valor en pantalla

  

  //HACEMOS LOS CASOS PARA EL MOVIMIENTO DE NUESTRO CARRO
  if((s1==0) && (s2==0) && (s3==0)){
    alto();
    memoria='0';
  }else if((s1==1) && (s2==0) && (s3==1)){
    adelante();
    memoria='1'; 
  }else if((s1==0) && (s2==0) && (s3==1)){
    izquierda();
    memoria='2';
  }else if((s1==1) && (s2==0) && (s3==0)){
    derecha();
    memoria='3';
  }
  else if ((s1==0) && (s2==1) && (s3==1)){
    izquierda();
   memoria='2';
  }
   else if ((s1==1) && (s2==1) && (s3==0)){
   derecha();
   memoria='3';
  }
}
