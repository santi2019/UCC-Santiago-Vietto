#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#define USER "Grupo1"
#define PASS "12345"
#define ENTER 13
#define BACKSPACE 8

using namespace std;

void mostrarEnBinario(unsigned char);
void choque();
void autoFantastico();
void carrera();
void Relleno();
void Tren();

int main() {

    string usuario, password;
    bool end1 = false;
    int intentos = 0;

    bool end = false;
    int opcion;

        cout<<"\t\t\t -------------------------------------"
        <<endl
            <<"\t\t\t|Proyecto Arquitectura de Computadoras|"
        <<endl
            <<"\t\t\t -------------------------------------"
        <<endl;
        cout<<endl;

    while(!end1 && intentos < 3){
        cout<<"\nLogin Usuario"
            <<endl
            <<endl
            <<"Usuario: ";
        getline(cin, usuario);
        cout<<"Password: ";

        char caracter;
        caracter = getch ();
        password = "";
        while(caracter != 13){
            if(caracter != 8){
                password.push_back(caracter);
                cout<<"*"; }
            else{
                if(password.length()>0)
                    cout<< "\b \b";
                password = password.substr(0, password.length() - 1);
            }
            caracter = getch();
        }
        cout<<endl;
        cout<<endl;

        if (usuario == USER && password == PASS){
            cout<<"Bienvenido al sistema"<<endl;
            end1 = true;
         while(!end){
           cout<<"\n\nIngrese: "
            <<"\n1: Choque"
            <<"\n2: Auto Fantastico"
            <<"\n3: Carrera"
            <<"\n4: Relleno"
            <<"\n5: Tren"
            <<"\n6: Finalizar"
            <<"\n\nOpcion: ";
        cin>> opcion;
        cout<<endl;
        switch (opcion) {
            case 1:
                choque();
                break;
            case 2:
                autoFantastico();
                break;
            case 3:
                carrera();
                break;
            case 4:
                Relleno();
                break;
            case 5:
                Tren();
                break;
            case 6:
                end = true;
                break;
            default:
                cout<<"Comando incorrecto";
               }
            }
          }
        else{
            cout<<"El usuario y/o contrase�a son incorrectos"<<endl;
            intentos ++; }
    }
}

void choque(){
    cout<<"\n\nMostrando Choque:"
    <<endl
    <<endl;
    char a;
    unsigned char tabla[7] = {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42};

    while(!kbhit()){
        for (int i=0; i<7; i++) {
                if (!kbhit()){
                  mostrarEnBinario(tabla[i]);
                  cout<<"\r";
                  Sleep(200);}
                }
       }

cout<<"\n\nPresione una tecla para regresar: ";
cin>> a;
cout<<"\n\n--------------------------------------------------------------------------";
}

 void autoFantastico(){
  cout<<"\n\nMostrando Auto Fantastico:"
  <<endl
  <<endl;
  unsigned char a;
  int i;
  while(!kbhit()){
    a = 0x1;
        for (i=0; i<8; i++) {
            if(!kbhit()){
            mostrarEnBinario(a);
            cout<<"\r";
            Sleep(200);
            a=a<<1; }
            }
    a = 0x40;
        for (i=0; i<6; i++) {
          if(!kbhit()){
            mostrarEnBinario(a);
            cout<<"\r";
            Sleep(200);
            a=a>>1;
            }
        }
  }
cout<<"\n\nPresione una tecla para regresar: ";
cin>> a;
cout<<"\n\n--------------------------------------------------------------------------";
}

void carrera(){
    cout<<"\n\nMostrando Carrera:"
    <<endl
    <<endl;
    char a;
    unsigned char tabla[16]={0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x88, 0x48, 0x24, 0x14, 0xA, 0x6, 0x3, 0x1};

    while(!kbhit()){
    for (int i = 0; i<15; i++) {
        if(!kbhit()){
        mostrarEnBinario(tabla[i]);
        cout << "\r";
        Sleep(200);}
        }

}
cout<<"\n\nPresione una tecla para regresar: ";
cin>> a;
cout<<"\n\n--------------------------------------------------------------------------";
}

void Relleno(){
    cout<<"\n\nMostrando Relleno:"
    <<endl
    <<endl;
    char a;
    unsigned char tabla[7] = {0x81, 0xC3, 0xE7, 0xFF, 0xFF, 0xE7, 0xC3};
  while(!kbhit()){
        for (int i=0; i<7; i++){
          if(!kbhit()){
            mostrarEnBinario(tabla[i]);
            cout<<"\r";
            Sleep(200);
          }
        }
  }
cout<<"\n\nPresione una tecla para regresar: ";
cin>> a;
cout<<"\n\n--------------------------------------------------------------------------";
}

void Tren(){
  cout<<"\nMostrando Tren:"
  <<endl
  <<endl;
  unsigned char a;
  int i;

  while(!kbhit()){
    a = 0x3F;
        for (i=0; i<10; i++){
          if(!kbhit()){
            mostrarEnBinario(a);
            cout<<"\r";
            Sleep(200);
            a=a<<1;
          }
        }
    a = 0xFC;
        for (i=0; i<10; i++){
          if(!kbhit()){
            mostrarEnBinario(a);
            cout<<"\r";
            Sleep(200);
            a=a>>1;
            }
        }
  }
cout<<"\n\nPresione una tecla para regresar: ";
cin>> a;
cout<<"\n\n--------------------------------------------------------------------------";
}

void mostrarEnBinario(unsigned char byteOriginal){
    for (unsigned char mask = 128; mask > 0; mask/=2){
        if (byteOriginal&mask){
            cout<<"*";
        }
        else
            cout<<"_";
    }
}
