#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define MAX 4
#define MIN 0
using namespace std;
 //SISTEMA DE REGISTRO DE USUARIOS 
//CONSTANTES
const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador=0;
//TIPOS
typedef char TCadena[MAXCAD+1]; // MAXCAD caracteres + FINCAD
struct Persona_R
{
TCadena PASS;
};
// CABECERA DE PROCEDIMIENTOS Y FUNCIONES
void pausa();	
void finalizar_programa();
void borrar_pantalla();
void Ingresar_PASS(Persona_R &p);
void confirmar_PASS(Persona_R &p);
// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_de_usuario(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero,Persona_R &password);
void retardo(){
	for(int z=0; z<11000; z++){
		for(int m=0; m<9000; m++){
		}
	}
}
 
class Usuario_data{
public:
    string edad_usuario_registrado;
    string correo_usuario_registrado;
     string Nombre_usuario_registrado;
    string nombre_usuario_registrado;
};


int main()
{
Persona_R p;;
Persona_R password;;
char opcion;
int num;
bool fin,encontrado;
TCadena nombre_usuario_registrado;
TCadena Nombre_usuario_registrado;
TCadena edad_usuario_registrado;
TCadena correo_usuario_registrado;
int opcion_menu;

system ("color f9");
cout << "\n	BIENVENIDOS A HEART.THLY" << endl;
cout << "==============================================" << endl;
cout << "1. Iniciar sesion" << endl;
cout << "2. Registrarse" << endl;
cout << "3. Ingresar como psicologo " << endl;
cout << "4. Salir del Programa." << endl;
cout << "----------------------------" << endl;
cout << "Introduzca Opcion:  ";
cin >> opcion_menu;
if (opcion_menu==4) {finalizar_programa();}
if((opcion_menu<MIN)||(opcion_menu>MAX)){        
try {        system("cls");
             cout<<"\n\n\t  ============================\n"
                 <<"\n\n\t | ESTA OPCION  ES INCORRECTA |\n"
                 <<"\n\n\t  ============================\n"; 
                 Sleep(1500);    //SEGUNDO Y MEDIO QUE DURA
                 system("cls"); //LIMPIA TODO  
                 main();//Y VUELVE AL MENÚ  
    }//TRY
    catch(...)
	{cout << "\n UN ERROR HA OCURRIDO " << endl; } }  
	
switch(opcion_menu)
{
case 1: 
    system("cls");
	for(int z=0; z<20; z++){
		printf("\nCARGANDO..............\n");
		printf("[");
		for(int m=0; m<z; m++){
			printf("X");
		}
		printf("]");
		printf("\n"); 
		printf("CARGANDO..............\n");
		retardo();
		system("cls");
	}
	    retardo();
cout << "\nDigite su Nombre de Usuario:     ";//INGRESAR COMO USUARIO
cin >> nombre_usuario_registrado;
verificar_existencia_fichero(nombre_usuario_registrado);
//confirmar_PASS(password);
verificar_contrasena(nombre_usuario_registrado,password);
Sleep(1000);borrar_pantalla();main();
break;


case 2: 
    system("cls");
	for(int z=0; z<20; z++){
		printf("\nCARGANDO..............\n");
		printf("[");
		for(int m=0; m<z; m++){
			printf("X");
		}
		printf("]");
		printf("\n"); 
		printf("CARGANDO..............\n");
		retardo();
		system("cls");
	}
	    retardo();

cout << "\n                         REGISTRO     ";
cout << "\n**************************************************************     ";
cout << "\nCual es tu edad:     ";//INGRESAR COMO USUARIO
cin >> edad_usuario_registrado;
insertarPersonaTXT(edad_usuario_registrado,p);
cout << "\nDigita tu correo:     ";//INGRESAR COMO USUARIO
cin >> correo_usuario_registrado;
insertarPersonaTXT(correo_usuario_registrado,p);
cout << "\nDigite su Nombre:     ";//INGRESAR COMO USUARIO
cin >> Nombre_usuario_registrado;
insertarPersonaTXT(Nombre_usuario_registrado,p);
cout << "\nEscriba su Nuevo Nombre de Usuario:    ";//REGISTRO
cin >> nombre_usuario_registrado;
verificar_existencia_de_usuario(nombre_usuario_registrado);
Ingresar_PASS(p);
insertarPersonaTXT(nombre_usuario_registrado,p);
Sleep(1000);borrar_pantalla();main();
break;

case 3: 
int p;
cout << "\nHOLA DESARROLLADOR !!!... \n"; // Ingresar como visitante
cout << "\n FOR SECURITY MATTERS WE NEED A PASSWORD \n";
cout << " ";
cout << " Enter password \n";
cin >> p;
	cout<<"Bienvenido al sistema";
	cout<<"contrasena incorrecta";

break;
}
return 0;
}
void finalizar_programa()
{
borrar_pantalla();     
printf("El Programa CERRARA en Cualquier Momento"); Sleep(3000);
exit(0);
}
void pausa()
{
system("PAUSE");
}
void borrar_pantalla()
{
system("CLS");
}
void Ingresar_PASS(Persona_R &p)
{
cout << "Escriba su Nuevo PASS:                 " ;
cin >> p.PASS;
cout<<"\nSE HA REGISTRADO CORRECTAMENTE"<<endl; Sleep(2500); 
}
void confirmar_PASS(Persona_R &password)
{
cout << "Escriba su PASS:          " ;
cin >> password.PASS;
}

// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
ofstream out;
out.open(nombreFichero,ios::app);
// Abro el fichero para añadir
if (out.bad()){
// El fichero no existe ... lo creo
out.open(nombreFichero);}	
EscribePersonaFicheroTXT(out,p);
out.close();
}

void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p)
{
fichero << p.PASS << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
	    ifstream archivo(nombreFichero); 
    if (!archivo)
    {    
          cout<<"\nNombre de Usuario INCORRECTO.....INTENTELO DE NUEVO\n"<<endl; Sleep(2500); borrar_pantalla();main();  
    }
             else 
             {
              cout<<"\nNombre de Usuario CORRECTO..!!!\n"<<endl;Sleep(200);     
              } 
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero); 
    if (!archivo)
    {
             cout<<"\nNombre de Usuario DISPONIBLE\n"<<endl;Sleep(2500);
             }
             else 
             {
             cout<<"\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO"<<endl; Sleep(2500); borrar_pantalla();main();      
             }   
}

void verificar_contrasena(TCadena nombreFichero,Persona_R &password)
{
string cadena;
string contrase;
cout << "Escriba su PASS:                 " ;
cin >> password.PASS;
ifstream fichero(nombreFichero,ios::in);	
   
   while(!fichero.eof()) {                 
      fichero >> cadena;   
      //cadena = strstr (fichero,"simple");
  
  }
  if(cadena!=password.PASS){
  cout<<"\n PASS es INCORRECTO.....INTENTELO DE NUEVO\n"<<endl;Sleep(2000);
  fichero.close();}
  cin.get();
  
if(cadena==password.PASS){
cout<<"\n Su PASS es CORRECTA..!!! \n"<<endl;
    system("cls");
	for(int z=0; z<20; z++){
		printf("\nCARGANDO..............\n");
		printf("[");
		for(int m=0; m<z; m++){
			printf("X");
		}
		printf("]");
		printf("\n"); 
		printf("CARGANDO..............\n");
		retardo();
		system("cls");
	}
	    retardo();

	     cout<<"\n BIENVENIDO " <<endl; 
system("cls");
 int m;
                      cout <<"Que deseas hacer"<< endl;
                       cout <<"========================================================================================================================"<< endl;
                       cout <<"  1-PSICOLOGOS"<< endl;
                       cout <<"  2-RUTINAS"<< endl;
                       cout <<"  3-TEST "<< endl;
                       cout <<"  4-ATTAQUE DE ANSIEDAD"<< endl;
                       cout <<"  5-Perfil "<< endl;
                       cout <<"  6-Ajustes "<< endl;
                       cout <<"  Ingresa una opcion:     ";
                       cin>>m;
                        switch(m){
                        case 1:{
            	            cout <<"========================================================================================================================"<<endl;  
			 		        cout<<"Psicologos disponibles "<<endl;
			 		        //Mostrar perfiles de los psycologos  
			 		        system("PAUSE");
				        break;
                            }
                       	case 2:{
                       		{
            	            cout <<"========================================================================================================================"<<endl;  
                            int pro;
                            system("cls");
						  		cout<<"1) Paz mental"<<endl;
	                            cout<<"2) Lidiar con mi depresion"<<endl;
	                            cout<<"3) Controlar mi ansiedad"<<endl;
	                            cout<<"4) Darme animos"<<endl;
	                            cout<<"5) Me siento solo y quiero hablar con alguien"<<endl;
						  	    cin>> pro;
						  	        switch(pro){
						  	            case 1:
						  	            	system("cls");
		                                    cout<<"****************************************************************************************************************************"<<endl;
    		                                cout<<"PROXIMAMENTE TE AYUDAREMOS CON TU PAZ MENTAL"<<endl;
    		                                system("PAUSE");
    		                                break;
		                                case 2:
		                                	system("cls");
	                                		cout<<"****************************************************************************************************************************"<<endl;
			                                cout<<"PROXIMAMENTE TE ENSEÑAREMOS EL AUTOCONTROL DE LA DEPRESION"<<endl;
			                                system("PAUSE");
			                                break;
	                     	            case 3:
	                     	            	system("cls");
		                                	cout<<"****************************************************************************************************************************"<<endl;
			                                cout<<"PROXIMAMENTE TE APOYAREMOS CON EL CONTROL DE TU ANSIEDAD"<<endl;
			                                system("PAUSE");
			                                break;
			                            case 4:
			                            	system("cls");
		                                   	cout<<"****************************************************************************************************************************"<<endl;
			                                cout<<"PROXIMAMENTE TE DAREMOS ANIMOS"<<endl;
			                                system("PAUSE");
											break; 
			                            case 5:
			                            	system("cls");
			                                cout<<"****************************************************************************************************************************"<<endl;
		                                 	cout<<"PROXIMAMENTE TENDRAS GRANDES AMIGOS"<<endl;
		                                    system("PAUSE"); 
		                            default: cout<<"NO es una opcion valida";
									break;
						   }
                        }
                       	case 3:{
            	            cout <<"========================================================================================================================"<<endl;  
			 		        cout<<"NO SE QUE PONER"<<endl;
			 		        system("PAUSE");
					    break;
                        }
                  	    case 4:{
            	            cout <<"========================================================================================================================"<<endl;  
			 		        cout<<"QUIERES LLAMAR A EMERGENCIAS"<<endl;
			 		        cout<<"VER 2 ANUNCIOS PARA CONTINUAR"<<endl;
			 		        system("PAUSE");
					    break;
                        }
                        case 5:{
            	            cout <<"========================================================================================================================"<<endl;  
                             cout << "Perfil del Usuario" << endl;
                             ifstream archivo("nombreFichero,ios::app");
                                 if (archivo.is_open()) {
                                string linea;
                          while (getline(archivo, linea)) {
                             cout << linea << endl;
                       }
                             archivo.close();
                                } else {
                            cout << "Error al abrir el archivo para lectura. Asegúrate de haber guardado la información primero.\n";
                                  }
                            system("PAUSE");
                            break;
                             
                         }
    
                        case 6:{
            	            cout <<"========================================================================================================================"<<endl;  
			 		        cout<<"Foto de perfil"<<endl;
							 cout<<"Ayuda"<<endl;
			 		        cout<<"Cerra sesion"<<endl;
			 		        system("PAUSE");
					    break;
                        }
                        cin.get();
					}
				}
	
	}
	}
