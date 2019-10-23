/*
 * utn.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

/** \brief muestra un menu de opciones
 *
 * \param void sin parametros
 * \return int retorna el numero seleccionado
 *
 */
void utn_menuDeOpciones(void);
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int utn_getInt(char* mensaje);
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float utn_getFloat(char* mensaje);
/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char utn_getChar(char* mensaje);
/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char utn_getNumeroAleatorio(int desde , int hasta, int iniciar);


/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
 int utn_esNumerico(char *str)
/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */;
int utn_esTelefono(char *str);
/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int utn_esAlfaNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int utn_esSoloLetras(char *str);
/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int utn_esNumericoFlotante(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void utn_getString(char mensaje[],char input[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int utn_getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int utn_getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int utn_getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargar� el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int utn_getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
 /**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int utn_getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargar� el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int utn_getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);
/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void utn_clearStdin(void);
/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void utn_pause(void);
/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 *
 */
void utn_clearScreen(void);
/**
 * \brief Verifica si el valor recibido contiene solo n�meros, y - y que acepte muestre solo un max de 2 "-"
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y dos guion maximo.
 *
 */
int utn_esCuit(char *str);
/**
 * \brief Solicita un texto al usuario y obtiene el un cuit tipo string
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el Cuit ingresado
 * \return void
 */
int utn_GetCuitString(char* mensaje,char* input);
/**
 * \brief Solicita un texto Alfanumerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene es alfanumerico
 */
int utn_getStringAlfaNumerico(char mensaje[],char input[]);
/**
 * \brief Solicita un string alfanumerico
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargar� el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int utn_getValidStringAlfaNumerico(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
/** \brief Valida que sea numerico con espacios o guines
 *
 * \param str char* es el string a validar
 * \return int retorno 1 si esta todo ok; 0 si hay error.
 *
 */
int utn_esCuitConGuiones(char* str);
/** \brief pide un nombre al usuario y lo carga al puntero str
 *
 * \return int retorno -1 si hay error, 0 si esta OK;
 *
 */
int utn_getValidName(char*name);
/** \brief Agrega los guiones a un cuit valido sin guiones
 *
 * \param cuit char* es el cuit a ser analizado
 * \return char* retorna el puntero al nuevo cuit
 *
 */
char* utn_agregarGuionesAlCuit(char* cuit);
/** \brief valida que sea un cuit valido y sin guiones
 *
 * \param cuit char* es el cuit a ser analizado
 * \return int 0 si esta todo Ok. -1 si hay error.
 *
 */
int utn_isValidCuitSinGuiones(char* cuit);
/** \brief valida que sea un cuit valido con guiones en su respectivo lugar "XX-XXXXXXXX-X"
 *
 * \param cuit char* es el cuit a ser analizado
 * \return int 0 si esta todo Ok. -1 si hay error.
 *
 */
int utn_isValidCuitConGuiones(char* cuit);
/** \brief Valida que sea un cuit  Valido solo numeros
 *
 * \param char*dni es el cuit a analizar
 * \return int 0 si esta todo Ok. -1 si hay error.
 *
 */
int utn_isValidDni(char*dni);
/** \brief valida que sea un nombre valido solo letras y mas de 3 caracteres
 *
 * \param name char* es la cadena a ser analizada
 * \return int 0 si esta todo Ok. -1 si hay error.
 *
 */
int utn_isValidName(char * name);
/** \brief valida que sea un sueldo no sea negativo.
 *
 * \param sueldo int es el numero a validar
 * \return int 0 si esta todo Ok. -1 si hay error.
 *
 */
int utn_IsValidSueldo(int sueldo);

/** \brief valida los caracteres para un mail valido maximo un @
 *
 * \param str[] char la cadena a analizar
 * \return int retorna 1 si esta todo ok, 0 si hay error
 *
 */
int utn_esMail(char str[]);
/** \brief verifica que sea un mail valido
 *
 * \param mail char* la cadena a analizar
 * \return int retorna 0 si esta todo ok, retorna -1 si hay error
 *
 */
int utn_isValidMail(char* mail);
/** \brief obtiene un dni y valida que sea correcto
 *
 * \param char*dni es la cadena a ser analizada
 * \return int retorna 0 si esta todo ok, -1 si hay error
 *
 */
int utn_getValidDni(char*dni);
/** \brief obtiene un lastName y valida que sea correcto
 *
 * \param char*lastName es la cadena a ser analizada
 * \return int retorna 0 si esta todo ok, -1 si hay error
 *
 */
int utn_getValidLastName(char* lastName);
/** \brief obtiene un mail y valida que sea correcto
 *
 * \param char*mail es la cadena a ser analizada
 * \return int retorna 0 si esta todo ok, -1 si hay error
 *
 */
int utn_getValidMail(char*dni);
/** \brief obtiene un cuit y valida que sea correcto
 *
 * \param char*cuit es la cadena a ser analizada
 * \return int retorna 0 si esta todo ok, -1 si hay error
 *
 */
int utn_getValidCuit(char*cuit);
int utn_getValidStringNumerico(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int utn_getValidStringNumericoFloat(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

#endif /* UTN_H_ */
