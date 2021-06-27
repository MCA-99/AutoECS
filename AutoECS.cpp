#include<windows.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<mmsystem.h>

using namespace std;

/*
** GLOBAL VARIABLES
*/
char temp;

/*
** Posiciona el cursor en las coordenadas x,y especificadas
** @mca 24/06/2021
*/
void gotoxy(int x, int y){
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

/*
** Pinta el fondo basico que usara en todo el programa
** @mca 24/06/2021
** (llamar esta funcion lo menos posible ya que tarda en pintar todo el fondo)
*/
void print_bg() {
	//Pinta el area general de verde
	for (int i=2; i<139; i++) {
		for (int j=1; j<49; j++) {
			gotoxy(i,j);
        	printf("\E[0;32m%c", 219);
		}
    }
    // Pinta el area del titulo de negro
    for (int i=20; i<120; i++) {
		for (int j=3; j<17; j++) {
			gotoxy(i,j);
        	printf("\E[0;30m%c", 219);
		}
    }
    // Imprime el titulo
    gotoxy(41,7);
    printf("\E[0;37m %c%c%c%c%c%c %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c \E[0;31m%c%c%c%c%c%c%c\E[0;37m%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,187,219,219,187,219,219,187,219,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187);
    gotoxy(41,8);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\E[0;31m%c%c\E[0;37m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187,219,219,186,219,219,186,200,205,205,219,219,201,205,205,188,219,219,201,205,205,205,219,219,187,219,219,201,205,205,205,205,188,219,219,201,205,205,205,205,188,219,219,201,205,205,205,205,188);
    gotoxy(41,9);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c   %c%c%c   %c%c%c\E[0;31m%c%c%c%c%c\E[0;37m%c  %c%c%c     %c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,219,219,219,187,219,219,186,219,219,219,219,219,219,219,187);
    gotoxy(41,10);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c   %c%c%c   %c%c%c\E[0;31m%c%c\E[0;37m%c%c%c%c  %c%c%c     %c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,201,205,205,188,219,219,186,200,205,205,205,205,219,219,186);
    gotoxy(41,11);
    printf("\E[0;37m%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c%c%c%c%c%c%c\E[0;31m%c%c%c%c%c%c%c\E[0;37m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,186,219,219,186,200,219,219,219,219,219,219,201,188,219,219,186,200,219,219,219,219,219,219,201,188,219,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,219,186);
	gotoxy(41,12);
	printf("\E[0;37m%c%c%c  %c%c%c %c%c%c%c%c%c%c    %c%c%c    %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,188,200,205,188,200,205,205,205,205,205,188,200,205,188,200,205,205,205,205,205,188,200,205,205,205,205,205,205,188,200,205,205,205,205,205,188,200,205,205,205,205,205,205,188);
}

/*
** Pinta un cuadrado negro usando las coordenadas dadas por un bucle  
** @mca 24/06/2021
*/
void print_select_area() {
	//Pinta el area de seleccion de negro
	for (int i=20; i<120; i++) {
		for (int j=20; j<46; j++) {
			gotoxy(i,j);
        	printf("\E[0;30m%c", 219);
		}
    }
}

/*
** Imprime el menu basico para seleccionar acciones
** @mca 24/06/2021
*/
void print_menu() {
	//LLama la funcion de pintar el area de seleccion 
	print_select_area();
	// Imprime las opciones
    gotoxy(65,27);
    printf("\E[0;36m1.\E[0;37mAuto");
    gotoxy(65,29);
    printf("\E[0;33m2.\E[0;37mAcciones");
    gotoxy(65,31);
    printf("\E[0;31m0.\E[0;37mSalir");
    gotoxy(61,39);
	printf("Elige una opcion: ");
	// Recoge un valor introducido por el usuario
	int menu_opt;
    scanf("%d", &menu_opt);
    // Detecta si se ha introducido un valor no valido
    if (menu_opt<=2) {
    	// Switch para las diferentes opciones
    	switch (menu_opt) {
    		case 0:
    			exit(0);
    		break;
    		case 1:
    			print_select_area();
    			gotoxy(21,21);
    			printf("\E[0maaa");
    		break;
    		case 2:
    			print_select_area();
    			gotoxy(21,21);
    			printf("\E[0mbbb");
    		break;
		}
	} else {
		gotoxy(53,41);
		printf("\e[4;31mHAS INTRODUCIDO UN VALOR NO VALIDO!");
		gotoxy(50,42);
		printf("PRESIONA ENTER PARA VOLVER A INTENTARLO...\e[0m");
		cin.ignore();
		cin.ignore();
		print_menu();
	}
    
}

int main(){
	
	system("TITLE AutoECS");
	system("MODE 141,50");
	
	print_bg();
	print_menu();
	
	// borrame al final papu
	cin.ignore();
	cin.ignore();
}
