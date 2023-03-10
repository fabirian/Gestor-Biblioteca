/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GESTIONBIBLIOTECA_H_RPCGEN
#define _GESTIONBIBLIOTECA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXNOM 30
#define MAXDAT 20
#define MAXTIPOID 4

struct datos_persona {
	int id;
	char nombre[MAXNOM];
	char apellido[MAXNOM];
	char telefono[MAXNOM];
	char ocupacion[MAXDAT];
	char codigo[MAXNOM];
};
typedef struct datos_persona datos_persona;

struct datos_prestamo {
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
typedef struct datos_prestamo datos_prestamo;

struct libro {
	char isbn[MAXNOM];
	char autor[MAXNOM];
	char nombre[MAXNOM];
	char editorial[MAXNOM];
	char area_conocimiento[MAXNOM];
	int error;
};
typedef struct libro libro;

struct datos_credencial {
	char usuario[MAXNOM];
	char clave[MAXNOM];
	int id;
	char ocupacion[MAXDAT];
};
typedef struct datos_credencial datos_credencial;

#define gestion_biblioteca 0x20000021
#define gestion_biblioteca_version 1

#if defined(__STDC__) || defined(__cplusplus)
#define registrarPersona 1
extern  bool_t * registrarpersona_1(datos_persona *, CLIENT *);
extern  bool_t * registrarpersona_1_svc(datos_persona *, struct svc_req *);
#define consultarPersona 2
extern  datos_persona * consultarpersona_1(char *, CLIENT *);
extern  datos_persona * consultarpersona_1_svc(char *, struct svc_req *);
#define prestarLibro 3
extern  bool_t * prestarlibro_1(datos_prestamo *, CLIENT *);
extern  bool_t * prestarlibro_1_svc(datos_prestamo *, struct svc_req *);
#define devolverLibro 4
extern  datos_prestamo * devolverlibro_1(char **, CLIENT *);
extern  datos_prestamo * devolverlibro_1_svc(char **, struct svc_req *);
#define consultarLibro 5
extern  libro * consultarlibro_1(char **, CLIENT *);
extern  libro * consultarlibro_1_svc(char **, struct svc_req *);
#define abrir_sesion 6
extern  datos_credencial * abrir_sesion_1(datos_credencial *, CLIENT *);
extern  datos_credencial * abrir_sesion_1_svc(datos_credencial *, struct svc_req *);
#define verificar 7
extern  bool_t * verificar_1(int *, CLIENT *);
extern  bool_t * verificar_1_svc(int *, struct svc_req *);
extern int gestion_biblioteca_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define registrarPersona 1
extern  bool_t * registrarpersona_1();
extern  bool_t * registrarpersona_1_svc();
#define consultarPersona 2
extern  datos_persona * consultarpersona_1();
extern  datos_persona * consultarpersona_1_svc();
#define prestarLibro 3
extern  bool_t * prestarlibro_1();
extern  bool_t * prestarlibro_1_svc();
#define devolverLibro 4
extern  datos_prestamo * devolverlibro_1();
extern  datos_prestamo * devolverlibro_1_svc();
#define consultarLibro 5
extern  libro * consultarlibro_1();
extern  libro * consultarlibro_1_svc();
#define abrir_sesion 6
extern  datos_credencial * abrir_sesion_1();
extern  datos_credencial * abrir_sesion_1_svc();
#define verificar 7
extern  bool_t * verificar_1();
extern  bool_t * verificar_1_svc();
extern int gestion_biblioteca_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_datos_persona (XDR *, datos_persona*);
extern  bool_t xdr_datos_prestamo (XDR *, datos_prestamo*);
extern  bool_t xdr_libro (XDR *, libro*);
extern  bool_t xdr_datos_credencial (XDR *, datos_credencial*);

#else /* K&R C */
extern bool_t xdr_datos_persona ();
extern bool_t xdr_datos_prestamo ();
extern bool_t xdr_libro ();
extern bool_t xdr_datos_credencial ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GESTIONBIBLIOTECA_H_RPCGEN */
