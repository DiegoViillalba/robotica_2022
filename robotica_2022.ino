/*
--------------------------------------------- AUTORES ---------------------------------------------
                              Hernández Cuevas Jonathan Alexis 
                               Villalba Gónzalez Diego Antonio
*/

/*-------------------------DECLARAMOS VARIABLES NECESARIAS PARA EL CÓDIGO-------------------------*/
int i; //Declaramos la variable i del tipo entero para asignar los pines establecidos
int potencia; //Declaramos la variable potencia del tipo entero para la velocidad de los motores
char memoria; //Declaramos la variable memoria del tipo entero para el caso donde esta en blanco (Guardar)
int s1 = 0; //Declaramos la variable s1 para la lectura de valores 
int s2 = 0; //Declaramos la variable s2 para la lectura de valores
int s3 = 0; //Declaramos la variable s3 para la lectura de valores
bool button; //Declaramos la variable button para la lectura de valores
bool sentido = 0;
int s1_r = 0; //Declaramos la variable s1 para la lectura de valores 
int s2_r = 0; //Declaramos la variable s2 para la lectura de valores
int s3_r = 0; //Declaramos la variable s3 para la lectura de valores
int c=0;
int j=0;
/*-------------------------DECLARAMOS ASPECTOS DEL CÓDIGO-------------------------*/
void setup() 
{
  Serial.begin(9600); //Inicializamos comunicación serial
  pinMode(A1, INPUT); //Declaramos A1 como salida al sensor Derecho externo
  pinMode(A2, INPUT); //Declaramos A2 como salida al sensor Derecho
  pinMode(A3, INPUT); //Declaramos A3 como salida al sensor Centro
  pinMode(A4, INPUT); //Declaramos A4 como salida al sensor Izquierda
  pinMode(A5, INPUT); //Declaramos A5 como salida al sensor Izquierda externo
  pinMode(A6, INPUT); //Declaramos A5 como salida al push button
  pinMode(6, OUTPUT); //Declaramos A2 como salida al Motor Derecha
  pinMode(5, OUTPUT); //Declaramos A2 como salida al Motor Izquierda
}

/*-------------------------DEFINIMOS LA FUNCION PARA NUESTROS LECTURA-------------------------*/
int funcionp(int s1, int s2, int s3)
{
  float p; //Declaramos variables para nuestras funciones 
  float d; //Declaramos variables para nuestras funciones 
  float v; //Declaramos variables para nuestras funciones 
  float k; //Declaramos variables para nuestras funciones 
  p = (s1+s3)/2; 
  d = (s2-p);
  k = d*0.30;
  v = s2 - k;
  return v;
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
    Motor1(i=0, potencia = 0);
    Motor2(i=0, potencia = 200);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: IZQUIERDA
void izquierda(){
    Motor1(i=0, potencia = 200);
    Motor2(i=0, potencia = 0);
  }
//FUNCION QUE INDICA EL MOVIMIENTO DE LOS MOTORES: DETENIDO
void alto(){
    Motor1(i=2, potencia = 230);
    Motor2(i=2, potencia = 230);
  }
//DECLARAMOS INSTRUCCIONES DEL CÓDIGO
void loop() {
  button = digitalRead(A6);
  int v;
  
  

      //ASIGNAMOS VALORES A NUESTRAS VARIABLES
    s2_r = analogRead(A3); //Asignamos a la variable s2 la lectura del sensor reflexivo conectado al pin A3
    s3_r = analogRead(A2)-20; //Asignamos a la variable s3 la lectura del sensor reflexivo conectado al pin A2
    s1_r = analogRead(A4); //Asignamos a la variable s1 la lectura del sensor reflexivo conectado al pin A4

    if (c==0){
      v = funcionp(s1_r,s2_r,s3_r);
      c ==1;
    }
    
    /*
                                    REGISTRO DE LECTURA DE LOS SENSORES
                                        1=Blanco       0=Negro
    */

    /*
      IMPRIMIMOS EN PANTALLA LO QUE LEEN NUESTROS SENSORERES
      Serial.println("Sensor izquierda    Sensor Centro     Sensor Derecha");//Imprimimos texto en pantalla
      Serial.print(s1);//Imprimimos valor en pantalla
      Serial.print("                     ");//Espacio
      Serial.print(s2);//Imprimimos valor en pantalla
      Serial.print("                     ");//Espacio
      Serial.println(s3);//Imprimimos valor en pantalla
    */

  //HACEMOS CASOS PARA GUARDAR VARIABLES 
  if (s1_r <= v) 
  {
    s1 = 0;
    Serial.println(s1_r);//Espacio
  }
  else if(s1_r>v)
  {
    s1=1;
    Serial.println(s1_r);//Espacio
  }
  if (s2_r <= v)
  {
    s2 = 0;
  }
  else if(s2_r>v)
  {
    s2=1;
  }
  if (s3_r <= v)
  {
    s3 = 0;
  }
  else if(s3_r>v)
  {
    s3=1;
  }

  //HACEMOS LOS CASOS PARA EL MOVIMIENTO DE NUESTRO CARRO

    if( (s1==0) && (s2==0) && (s3==0))
    {
      if(memoria == '3'){
        if(j==0){
          izquierda();//Llamamos a la funcion 
        Serial.println("izquierda");//Espacio
        memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
        j=1;
          }
          else{
        derecha();//Llamamos a la funcion 
        Serial.println("derecha");//Espacio
        memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
        j=0;
      }
          
        
      }
          
      else if(memoria == '2'){
        if(j==0){
        derecha();//Llamamos a la funcion 
        Serial.println("derecha");//Espacio
        memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
        j=1;
      }
      else {
          izquierda();//Llamamos a la funcion 
        Serial.println("izquierda");//Espacio
        memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
        j=0;
          }
      }
      
    }else if( (s1==0) && (s2==1) && (s3==0))
    {
      adelante();//Llamamos a la funcion 
      Serial.println("adelante");//Espacio
      memoria='1'; //Guardamos los valores en la variable para que asosie al movimieto
    }else if( (s1==1) && (s2==0) && (s3==0))
    {
      izquierda();//Llamamos a la funcion 
      Serial.println("izquierda");//Espacio
      memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
    }else if( (s1==0) && (s2==0) && (s3==1))
    {
      derecha();//Llamamos a la funcion 
      Serial.println("derecha");//Espacio
      memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
    }
    else if( (s1==1) && (s2==1) && (s3==0))
    {
      izquierda();//Llamamos a la funcion 
      Serial.println("izquierda");//Espacio
      memoria='2';//Guardamos los valores en la variable para que asosie al movimieto
    }else if( (s1==0) && (s2==1) && (s3==1))
    {
      derecha();//Llamamos a la funcion 
      Serial.println("derecha");//Espacio
      memoria='3';//Guardamos los valores en la variable para que asosie al movimieto
    }
}
