const MAXNOM = 30;
const MAXDAT = 20;
const MAXTIPOID = 4;

struct datos_persona{
    int id;
    char nombre[MAXNOM];
    char apellido[MAXNOM];
    char telefono[MAXNOM];
    char ocupacion[MAXDAT];
    char codigo[MAXNOM];
};

struct datos_prestamo{
    char nom_libro[MAXDAT];
    char codigo[MAXNOM];
    int dia_1;
    int mes_1;
    int anio1;
    int dia_2;
    int mes_2;
    int anio2;
    int multa;
    int dia_3;
    int mes_3;
    int anio3;
};
struct libro{
    char isbn[MAXNOM];
    char autor[MAXNOM];
    char nombre[MAXNOM];
    char editorial[MAXNOM];
    char area_conocimiento[MAXNOM];
    int error;
};

struct datos_credencial{
    char usuario[MAXNOM];
    char clave[MAXNOM];
    int id;
    char ocupacion[MAXDAT];
};

program gestion_biblioteca{
    version gestion_biblioteca_version{
        bool registrarPersona(datos_persona objPersona)=1;
        datos_persona consultarPersona(char codigo)=2;
        bool prestarLibro(datos_prestamo objPrestamo)=3;
        datos_prestamo devolverLibro(string codigo)=4;
        libro consultarLibro(string libro)=5;
        datos_credencial abrir_sesion(datos_credencial objCredencial)=6;
        bool verificar(int codVer)=7;
    }=1;
}=0x20000021;

