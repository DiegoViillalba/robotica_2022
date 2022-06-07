/*
--------------------------------------------- AUTORES ---------------------------------------------
                              Hernández Cuevas Jonathan Alexis 
                               Villalba Gónzalez Diego Antonio
*/

/*-------------------------DECLARAMOS VARIABLES NECESARIAS PARA EL CÓDIGO-------------------------*/
int motor; //Declaramos la variable motores del tipo entero 
int sensor; //Declaramos la variable sensor del tipo entero 
int i; //Declaramos la variable i del tipo entero para asignar los pines establecidos
int potencia; //Declaramos la variable potencia del tipo entero para la velocidad de los motores
char memoria; //Declaramos la variable memoria del tipo entero para el caso donde esta en blanco (Guardar)
bool s1 = 0; //Declaramos la variable s1 para la lectura de valores 
bool s2 = 0; //Declaramos la variable s2 para la lectura de valores
bool s3 = 0; //Declaramos la variable s3 para la lectura de valores
bool sentido = 0;

/*-------------------------DECLARAMOS ASPECTOS DEL CÓDIGO-------------------------*/
void setup() 
{
  Serial.begin(9600); //Inicializamos comunicación serial
  pinMode(A2, INPUT); //Declaramos A2 como salida al sensor Derecho
  pinMode(A3, INPUT); //Declaramos A3 como salida al sensor Centro
  pinMode(A4, INPUT); //Declaramos A4 como salida al sensor Izquierda
  pinMode(6, OUTPUT); //Declaramos A2 como salida al Motor Derecha
  pinMode(5, OUTPUT); //Declaramos A2 como salida al Motor Izquierda
}

/*-------------------------DEFINIMOS LA FUNCION PARA NUESTROS MOTORES-------------------------*/

//MOTOR 1
 void Motor1(int i, int potencia)
  {
    analogWrite(5,potencia); //Se habilita el motor 1 
  }

//MOTOR 2
void Motor2(int i, int potencia)
  {
    analogWrite(6,potencia); //Se habilita el motor 1 
  }
  
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: ADELANTE
void adelante(){
    Motor1(i=0, potencia = 255);
    Motor2(i=0, potencia = 255);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: ATRÁS
void atras(){
    Motor1(i=1, potencia = 255);
    Motor2(i=1, potencia = 255);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: DERECHA
void derecha(){
    Motor1(i=0, potencia = 255);
    Motor2(i=0, potencia = 100);
    // Imprimimos potencia del motor resultante
  Serial.println("Potencia del motor: 255");
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: IZQUIERDA
void izquierda(){
    Motor1(i=0, potencia = 100);
    Motor2(i=0, potencia = 255);
    Serial.println("Potencia del motor: 255");
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: DETENIDO
void alto(){
    Motor1(i=2, potencia = 255);
    Motor2(i=2, potencia = 255);
  }

//DECLARAMOS INSTRUCCIONES DEL CÓDIGO
void loop() {
  
  //ASIGNAMOS VALORES A NUESTRAS VARIABLES
  s1 = digitalRead(A4); //Asignamos a la variable s1 la lectura del sensor reflexivo conectado al pin A4
  s2 = digitalRead(A3); //Asignamos a la variable s2 la lectura del sensor reflexivo conectado al pin A3
  s3 = digitalRead(A2); //Asignamos a la variable s3 la lectura del sensor reflexivo conectado al pin A2

  /*
                                  REGISTRO DE LECTURA DE LOS SENSORES
                                      1=Negro       0=blanco
  */

  //IMPRIMIMOS EN PANTALLA LO QUE LEEN NUESTROS SENSORERES
  Serial.println("Sensor izquierda    Sensor Centro     Sensor Derecha");//Imprimimos texto en pantalla
  Serial.print(s1);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.print(s2);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.println(s3);//Imprimimos valor en pantalla


  //HACEMOS LOS CASOS PARA EL MOVIMIENTO DE NUESTRO CARRO
  if((s1==0) && (s2==0) && (s3==0))
  {
    alto();//Llamamos a la funcion 
    memoria='0';//Guardamos los valores en la variable para que asosie al movimieto
  }else if((s1==1) && (s2==0) && (s3==1))
  {
    adelante();//Llamamos a la funcion 
    memoria='1'; //Guardamos los valores en la variable para que asosie al movimieto
  }else if((s1==0) && (s2==0) && (s3==1))
  {
    izquierda();//Llamamos a la funcion 
    memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
  }else if((s1==1) && (s2==0) && (s3==0))
  {
    derecha();//Llamamos a la funcion 
    memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
  }
  else if ((s1==0) && (s2==1) && (s3==1))
  {
    izquierda();//Llamamos a la funcion 
   memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
  }
   else if ((s1==1) && (s2==1) && (s3==0))
   {
   derecha();//Llamamos a la funcion 
   memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
  }
}

/*
                    IDEA DOS PARA EL CODIGO DEL SEGUIDOR DE LINEA (CAMBIA SOLO EL LOOP)
//Si se lleva acabo la segunda idea es necesario declarar dos variables globales extra llamadas:
//int bandera1 = 0;
//int bandera2 = 1;

//Para la segunda idea se necesita redefiinir las funciones de los motores de la siguiente manera

-------------------------DEFINIMOS LA FUNCION PARA NUESTROS MOTORES-------------------------

//MOTOR 1
 void Motor1(int i, int potencia)
  {
    analogWrite(5,potencia); //Se habilita el motor 1 
  }

//MOTOR 2
void Motor2(int i, int potencia)
  {
    analogWrite(6,potencia); //Se habilita el motor 1 
  }
  
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: ADELANTE
void adelante(int potencia){
    Motor1(i=0, potencia);
    Motor2(i=0, potencia);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: ATRÁS
void atras(){
    Motor1(i=1, potencia);
    Motor2(i=1, potencia);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: DERECHA
void derecha(){
    Motor1(i=0, potencia);
    Motor2(i=0, potencia);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: IZQUIERDA
void izquierda(){
    Motor1(i=0, potencia);
    Motor2(i=0, potencia;
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: DETENIDO
void alto(){
    Motor1(i=2, potencia);
    Motor2(i=2, potencia);
  }

void loop() {
  
  //ASIGNAMOS VALORES A NUESTRAS VARIABLES
  s1 = digitalRead(A4); //Asignamos a la variable s1 la lectura del sensor reflexivo conectado al pin A4
  s2 = digitalRead(A3); //Asignamos a la variable s2 la lectura del sensor reflexivo conectado al pin A3
  s3 = digitalRead(A2); //Asignamos a la variable s3 la lectura del sensor reflexivo conectado al pin A2

  
  //                                REGISTRO DE LECTURA DE LOS SENSORES
  //                                    1=Negro       0=blanco
  

  //IMPRIMIMOS EN PANTALLA LO QUE LEEN NUESTROS SENSORERES
  Serial.println("Sensor izquierda    Sensor Centro     Sensor Derecha");//Imprimimos texto en pantalla
  Serial.print(s1);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.print(s2);//Imprimimos valor en pantalla
  Serial.print("                     ");//Espacio
  Serial.println(s3);//Imprimimos valor en pantalla


  //HACEMOS LOS CASOS PARA EL MOVIMIENTO DE NUESTRO CARRO
  
  if((s1==0) && (s2==0) && (s3==0))
  {
      atras(potencia = 100); //Llamamos a función
      delay(100); //Hacemos una pausa del tiempo indicado 
      bandera1 = 0; //Asignamos valor a una variable
  }
  else if((s1==0) && (s2==0) && (s3==1))
  {
    bandera1 = 1; //Asignamos valor a una variable
    atras(potencia = 150); //Llamamos a función
    delay(20); //Hacemos una pausa del tiempo indicado 
    //REALIZAMOS UN GIRO GRADUALMENTE
    izquierda(potencia = 100); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    izquierda(potencia = 200); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    izquierda(potencia = 250); //Llamamos a función
    delay(70); //Hacemos una pausa del tiempo indicado 
  }
else if((s1==0) && (s2==1) && (s3==1))
  {
    bandera1 = 1; //Asignamos valor a una variable
    atras(potencia = 150); //Llamamos a función
    delay(20); //Hacemos una pausa del tiempo indicado 
    //REALIZAMOS UN GIRO GRADUALMENTE
    izquierda(potencia = 100); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    izquierda(potencia = 200); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    izquierda(potencia = 250); //Llamamos a función
    delay(70); //Hacemos una pausa del tiempo indicado 
  }  
  else if((s1==1) && (s2==0) && (s3==0))
  {
    bandera1 = 1; //Asignamos valor a una variable
    atras(potencia = 150); //Llamamos a función
    delay(20); //Hacemos una pausa del tiempo indicado 
    //REALIZAMOS UN GIRO GRADUALMENTE
    derecha(potencia = 100); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    derecha(potencia = 200); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    derecha(potencia = 250); //Llamamos a función
    delay(70); //Hacemos una pausa del tiempo indicado 
  }
  else if((s1==1) && (s2==1) && (s3==0))
  {
    bandera1 = 1; //Asignamos valor a una variable
    atras(potencia = 150); //Llamamos a función
    delay(20); //Hacemos una pausa del tiempo indicado 
    //REALIZAMOS UN GIRO GRADUALMENTE
    derecha(potencia = 100); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    derecha(potencia = 200); //Llamamos a función
    delay(50); //Hacemos una pausa del tiempo indicado 
    derecha(potencia = 250); //Llamamos a función
    delay(70); //Hacemos una pausa del tiempo indicado 
  }
  else if((s1==1) && (s2==1) && (s3==1))
  {
    bandera2 = 1;
  }
  if((bandera1 == 1) && (bandera2 == 1)){
    bandera1 = 0;
    bandera2 = 0;
    adelante(potencia = 100); //Llamamos a función
    delay(100); //Hacemos una pausa del tiempo indicado 
    alto(potencia = 100); //Llamamos a función
    delay(10); //Hacemos una pausa del tiempo indicado 
  }
  if((bandera1 == 0) && (bandera2 == 1))
  {
    adelante(potencia = 110); //Llamamos a función
    delay(20); //Hacemos una pausa del tiempo indicado 
    alto(potencia = 100); //Llamamos a función
    delay(5); //Hacemos una pausa del tiempo indicado 
  }
}
*/