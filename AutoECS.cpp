#include<windows.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<mmsystem.h>

using namespace std;

/*
** GLOBAL VARIABLES
*/
void print_menu();
void print_actions_menu();

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
	// Limpia la pantalla
	system("cls");
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
** Pinta el cuadrado de log cuando se ejecute los comandos de la terminal
** @mca 29/06/2021
*/
void print_log_title() {
	gotoxy(0,1);
	printf("\E[0;37m %c%c       %c%c%c%c%c%c   %c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(0,2);
	printf("\E[0;37m %c%c      %c%c    %c%c %c%c",219,219,219,219,219,219,219,219);
	gotoxy(0,3);
	printf("\E[0;37m %c%c      %c%c    %c%c %c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(0,4);
	printf("\E[0;37m %c%c      %c%c    %c%c %c%c    %c%c",219,219,219,219,219,219,219,219,219,219);
	gotoxy(0,5);
	printf("\E[0;37m %c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(0,6);
	for (int i=0; i<141; i++) {
		printf("\E[0;37m%c",205);
	}
	gotoxy(0,8);
}

/*
** Mapea las unidades de red de windows
** @mca 28/06/2021
*/
void map_network_drive() {
	system("cls");
	print_log_title();
	printf("\E[0;32mMapeando unidades de red...\E[0;37m\n\n");
	system("net use X: \\\\MASTERS\\drivers /persistent:no");
	system("net use Z: \\\\MASTERS\\informes /persistent:no");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Desmapea las unidades de red de windows
** @mca 28/06/2021
*/
void unmap_network_drive() {
	system("cls");
	print_log_title();
	printf("\E[0;32mDesmapeando unidades de red...\E[0;37m\n\n");
	system("net use * /delete /y");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Actualiza la hora del sistema
** @mca 28/06/2021
*/
void update_sys_hour() {
	system("cls");
	print_log_title();
	printf("\E[0;32mComprobando si el servicio de tiempo esta iniciado...\E[0;37m\n\n");
    system("net start w32time");
    printf("\E[0;32mSincronizando hora con el servidor time.windows.com...\E[0;37m\n\n");
    system("w32tm /resync");
}

/*
** Descarga y usa el burnintest
** @mca 28/06/2021
*/
void bit() {
	system("cls");
	print_log_title();
	printf("\E[0;32mMoviendo BurninTest al equipo...\E[0;37m\n\n");
	system("Xcopy /E /I ""X:\\otros\\BIT\\"" """"");
	system("copy ""X:\\otros\\BIT\\"" """"");
	printf("\n\E[0;32mIniciando BurnInTest...\E[0;37m\n\n");
	system(""".\\BurninTest\\bit.exe"" /c "".\\BurninTest\\config.bitcfg"" /r""");
	printf("\E[0;32mMoviendo el informe a la unidad...\E[0;37m\n\n");
	system("AutoBit.bat");
	printf("\n\E[0;32mLimpiando...\E[0;37m\n\n");
	system("rmdir /Q /S ""BurnInTest""");
	system("del ""AutoBit.bat""");
	printf("\n\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Instala los drivers automaticamente
** @mca 28/06/2021
*/
void install_drivers() {
	system("cls");
	print_log_title();
	printf("\E[0;32mInstalando drivers...\E[0;37m\n\n");
	system("pnputil /add-driver \\\\MASTERS\\drivers\\otros\\*.inf /subdirs /install");
	printf("\n\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Ejecuta todas las funciones de forma automatica
** @mca 30/06/2021
*/
void auto_mode() {
	map_network_drive();
	update_sys_hour();
	install_drivers();
	bit();
	unmap_network_drive();
	cin.ignore();
	cin.ignore();
	print_bg();
	print_menu();
}

/*
** Imprime el menu de acciones y las realiza
** @mca 28/06/2021
*/
void print_actions_menu() {
	//LLama la funcion de pintar el area de seleccion 
	print_select_area();
	// Imprime las opciones
    gotoxy(58,24);
    printf("\E[0;36m1.\E[0;37mConectar unidades de red");
    gotoxy(58,26);
    printf("\E[0;36m2.\E[0;37mDesconectar unidades de red");
    gotoxy(58,28);
    printf("\E[0;36m3.\E[0;37mInstalar Drivers");
    gotoxy(58,30);
    printf("\E[0;36m4.\E[0;37mActualizar la hora del sistema");
    gotoxy(58,32);
    printf("\E[0;36m5.\E[0;37mBurninTest");
    gotoxy(58,34);
    printf("\E[0;31m0.\E[0;37mVolver al menu");
    gotoxy(61,39);
	printf("Elige una opcion: ");
	// Recoge un valor introducido por el usuario
	int menu_opt;
    scanf("%d", &menu_opt);
    // Detecta si se ha introducido un valor no valido
    if (menu_opt<=5 || menu_opt==666) {
    	// Switch para las diferentes opciones
    	switch (menu_opt) {
    		case 0:
    			print_menu();
    		break;
    		case 1:
    			map_network_drive();
    			cin.ignore();
				cin.ignore();
				print_bg();
    			print_actions_menu();
    		break;
    		case 2:
    			unmap_network_drive();
    			cin.ignore();
				cin.ignore();
				print_bg();
    			print_actions_menu();
    		break;
    		case 3:
    			install_drivers();
    			cin.ignore();
				cin.ignore();
				print_bg();
    			print_actions_menu();
    		break;
    		case 4:
    			update_sys_hour();
    			cin.ignore();
				cin.ignore();
				print_bg();
    			print_actions_menu();
    		break;
    		case 5:
    			bit();
    			cin.ignore();
				cin.ignore();
				print_bg();
    			print_actions_menu();
    		break;
    		case 666:
    			print_bg();
    			print_actions_menu();
    		break;
		}
	} else {
		gotoxy(53,41);
		printf("\e[4;31mHAS INTRODUCIDO UN VALOR NO VALIDO!");
		gotoxy(50,42);
		printf("PRESIONA ENTER PARA VOLVER A INTENTARLO...\e[0m");
		cin.ignore();
		cin.ignore();
		print_actions_menu();
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
    if (menu_opt<=2 || menu_opt==666) {
    	// Switch para las diferentes opciones
    	switch (menu_opt) {
    		case 0:
    			exit(0);
		   	break;
    		case 1:
    			auto_mode();
    		break;
    		case 2:
    			print_actions_menu();
    		break;
    		case 666:
    			print_bg();
    			print_menu();
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
}
