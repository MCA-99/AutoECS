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
** Positions the cursor at the specified x, y coordinates
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
** Print the basic background that you will use throughout the program
** @mca 24/06/2021
** (call this function as little as possible since it takes time to paint the entire background)
*/
void print_bg() {
	system("cls");
	for (int i=2; i<139; i++) {
		for (int j=1; j<49; j++) {
			gotoxy(i,j);
        	printf("\E[0;32m%c", 219);
		}
    }
    
    for (int i=20; i<120; i++) {
		for (int j=3; j<17; j++) {
			gotoxy(i,j);
        	printf("\E[0;30m%c", 219);
		}
    }
    // Print the title
    gotoxy(41,7);
    printf("\E[0;37m %c%c%c%c%c%c %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c \E[0;31m%c%c%c%c%c%c%c\E[0;37m%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,187,219,219,187,219,219,187,219,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,219,219,219,219,219,219,219,187);
    gotoxy(41,8);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\E[0;31m%c%c\E[0;37m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187,219,219,186,219,219,186,200,205,205,219,219,201,205,205,188,219,219,201,205,205,205,219,219,187,219,219,201,205,205,205,205,188,219,219,201,205,205,205,205,188,219,219,201,205,205,205,205,188);
    gotoxy(41,9);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c   %c%c%c   %c%c%c\E[0;31m%c%c%c%c%c\E[0;37m%c  %c%c%c     %c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,219,219,219,187,219,219,186,219,219,219,219,219,219,219,187);
    gotoxy(41,10);
    printf("\E[0;37m%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c   %c%c%c   %c%c%c\E[0;31m%c%c\E[0;37m%c%c%c%c  %c%c%c     %c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,186,219,219,201,205,205,188,219,219,186,200,205,205,205,205,219,219,186);
    gotoxy(41,11);
    printf("\E[0;37m%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c   %c%c%c%c%c%c%c%c%c\E[0;31m%c%c%c%c%c%c%c\E[0;37m%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,186,219,219,186,200,219,219,219,219,219,219,201,188,219,219,186,200,219,219,219,219,219,219,201,188,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,219,219,219,219,219,219,219,186);
	gotoxy(41,12);
	printf("\E[0;37m%c%c%c  %c%c%c %c%c%c%c%c%c%c    %c%c%c    %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,188,200,205,188,200,205,205,205,205,205,188,200,205,188,200,205,205,205,205,205,188,200,205,205,205,205,205,205,188,200,205,205,205,205,205,188,200,205,205,205,205,205,205,188);
}

/*
** Print a black square using the coordinates given by a loop
** @mca 24/06/2021
*/
void print_select_area() {
	for (int i=20; i<120; i++) {
		for (int j=20; j<46; j++) {
			gotoxy(i,j);
        	printf("\E[0;30m%c", 219);
		}
    }
}

/*
** Print the log square when the terminal commands are run
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
** Print a help screen in the main menu
** @mca 02/07/2021
*/
void print_help() {
	print_select_area();
	gotoxy(21,21);
	printf("\e[4;37m%c Este programa simplifica el proceso de BurnIn en los equipos fabricados.",175);
	gotoxy(21,26);
	printf("%c Segun el color en los numeros de las opciones significa una cosa u otra:",175);
	gotoxy(21,28);
	printf("\E[0;36mCyan\E[0m: La opcion se puede utilizar con normalidad, no requiere permisos de administrador.");
	gotoxy(21,30);
	printf("\E[0;33mNaranja\E[0m: La opcion requiere permisos de administrador, si no se ha ininiciado el programa como"); 
	gotoxy(21,31);
	printf("administrador es necesario reiniciarlo y abrirlo con los permisos correspondientes.");
	gotoxy(21,33);
	printf("\E[0;31mRojo\E[0m: Se utiliza para marcar la opcion de volover atras, o en caso de error.");
	gotoxy(21,35);
	printf("\E[0;35mMorado\E[0m: Se utiliza para marcar la opcion de ayuda.");
	gotoxy(57,39);
	printf("\E[4;31mPRESIONA ENTER PARA VOLVER\e[0m");
	gotoxy(21,43);
	printf("Made By: MCA");
	gotoxy(21,44);
	printf("Contact Mail: m.capdet@e-corp.es");
	cin.ignore();
	cin.ignore();
    print_menu();
}

/*
** Wait for an input before repainting the background and the menu (it will be used in each function of the action menu)
** @mca 01/07/2021
*/
void cls_actions_mnu() {
	cin.ignore();
	cin.ignore();
	print_bg();
    print_actions_menu();
}

/*
** Map windows network drives
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
** Unmap network drives from windows
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
** Update the system time
** @mca 28/06/2021
*/
void update_sys_hour() {
	system("cls");
	print_log_title();
	printf("\E[0;32mComprobando si el servicio de tiempo esta iniciado...\E[0;37m\n\n");
    system("net start w32time");
    printf("\E[0;32mSincronizando hora con el servidor time.windows.com...\E[0;37m\n\n");
    system("w32tm /resync");
    printf("\n\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Install drivers automatically
** @mca 28/06/2021
** 
** DEPRECATED BY UNKNOWN ERROR, NOW USING "device_manager()" FUNCTION
** @mca 05/07/2021
*/
void install_drivers() {
	system("cls");
	print_log_title();
	printf("\E[0;32mInstalando drivers...\E[0;37m\n\n");
	system("pnputil /add-driver X:\\masters\\drivers\\drivers\\*.inf /subdirs /install");
	printf("\n\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Update the system using WUMT
** @mca 01/07/2021
*/
void update_sys() {
	map_network_drive();
	system("cls");
	print_log_title();
	printf("\E[0;32mMoviendo el actualizador al equipo...\E[0;37m\n\n");
	system("copy ""X:\\programas\\wumt.exe"" """"");
	printf("\n\E[0;32mAbriendo actualizador...\E[0;37m\n");
	system("wumt.exe");
	printf("\n\E[0;32mLimpiando...\E[0;37m\n\n");
	system("del ""wumt.exe""");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Open the system activation wizard
** @mca 01/07/2021
*/
void activate_sys() {
	system("cls");
	print_log_title();
	printf("\E[0;32mAbriendo la ventana de activacion del sistema...\E[0;37m\n\n");
	system("start ms-settings:activation");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Move, use, and remove the BurnInTest
** @mca 28/06/2021
*/
void bit() {
	map_network_drive();
	system("cls");
	print_log_title();
	printf("\E[0;32mMoviendo BurninTest al equipo...\E[0;37m\n\n");
	system("Xcopy /E /I ""X:\\programas\\BurnInTest"" ""BurnInTest""");
	system("copy ""X:\\programas\\AutoBit.bat"" """"");
	printf("\n\E[0;32mIniciando BurnInTest...\E[0;37m\n\n");
	system(""".\\BurninTest\\bit.exe"" /c "".\\BurninTest\\config.bitcfg"" /r""");
	printf("\E[0;32mMoviendo el informe a la unidad...\E[0;37m\n\n");
	system("AutoBit.bat");
	printf("\n\E[0;32mLimpiando...\E[0;37m\n\n");
	system("rmdir /Q /S ""BurnInTest""");
	system("del ""AutoBit.bat""");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Open device manager
** @mca 02/07/2021
*/
void device_manager() {
	system("cls");
	print_log_title();
	printf("\E[0;32mAbriendo el administrador de dispositivos...\E[0;37m\n\n");
	system("devmgmt.msc");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Open the partition manager
** @mca 02/07/2021
*/
void partition_manager() {
	system("cls");
	print_log_title();
	printf("\E[0;32mAbriendo el gestor de particiones...\E[0;37m\n\n");
	system("diskmgmt.msc");
	printf("\E[0;32m### COMPLETADO Pulsa cualquier tecla para volver ###\E[0;37m\n\n");
}

/*
** Run all functions automatically
** @mca 30/06/2021
*/
void auto_mode() {
	map_network_drive();
	update_sys_hour();
	// -------------- OPTIONAL USE "device_manager()" TO INSTALL MISSING DRIVERS
	update_sys();
	activate_sys();
	bit();
	unmap_network_drive();
	cin.ignore();
	cin.ignore();
	print_bg();
	print_menu();
}

/*
** Print the menu of actions and perform them
** @mca 28/06/2021
*/
void print_actions_menu() {
	print_select_area();
    gotoxy(39,24);
    printf("\E[0;36m1.\E[0;37mConectar unidades de red");
    gotoxy(39,26);
    printf("\E[0;36m2.\E[0;37mDesconectar unidades de red");
    gotoxy(39,28);
    printf("\E[0;36m3.\E[0;37mInstalar Drivers");
    gotoxy(39,30);
    printf("\E[0;33m4.\E[0;37mActualizar la hora del sistema");
    gotoxy(39,32);
    printf("\E[0;36m5.\E[0;37mInstalar actualizaciones");
    gotoxy(39,34);
    printf("\E[0;36m6.\E[0;37mActivar el sistema");
    gotoxy(39,36);
    printf("\E[0;36m7.\E[0;37mBurninTest");
    gotoxy(77,24);
    printf("\E[0;36m8.\E[0;37mComprobar particiones");
    gotoxy(77,36);
    printf("\E[0;31m0.\E[0;37mVolver al menu");
    gotoxy(61,43);
	printf("Elige una opcion: ");
	int menu_opt;
    scanf("%d", &menu_opt);
    if (menu_opt<=8 || menu_opt==666) {
    	switch (menu_opt) {
    		case 0:
    			print_menu();
    		break;
    		case 1:
    			map_network_drive();
    			cls_actions_mnu();
    		break;
    		case 2:
    			unmap_network_drive();
    			cls_actions_mnu();
    		break;
    		case 3:
    			device_manager();
    			cls_actions_mnu();
    		break;
    		case 4:
    			update_sys_hour();
    			cls_actions_mnu();
    		break;
    		case 5:
    			update_sys();
    			cls_actions_mnu();
    		break;
    		case 6:
    			activate_sys();
    			cls_actions_mnu();
    		break;
    		case 7:
    			bit();
    			cls_actions_mnu();
    		break;
    		case 8:
    			partition_manager();
    			cls_actions_mnu();
    		break;
    		break;
    		case 666:
    			print_bg();
    			print_actions_menu();
    		break;
		}
	} else {
		gotoxy(53,39);
		printf("\e[4;31mHAS INTRODUCIDO UN VALOR NO VALIDO!");
		gotoxy(50,40);
		printf("PRESIONA ENTER PARA VOLVER A INTENTARLO...\e[0m");
		cin.ignore();
		cin.ignore();
		print_actions_menu();
	}
}

/*
** Print the basic menu to select actions
** @mca 24/06/2021
*/
void print_menu() {
	print_select_area();
    gotoxy(65,27);
    printf("\E[0;36m1.\E[0;37mAuto");
    gotoxy(65,29);
    printf("\E[0;33m2.\E[0;37mAcciones");
    gotoxy(65,31);
    printf("\E[0;35m3.\E[0;37mAyuda");
    gotoxy(65,34);
    printf("\E[0;31m0.\E[0;37mSalir");
    gotoxy(61,39);
	printf("Elige una opcion: ");
	int menu_opt;
    scanf("%d", &menu_opt);
    if (menu_opt<=3 || menu_opt==666) {
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
    		case 3:
    			print_help();
    			print_menu();
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
