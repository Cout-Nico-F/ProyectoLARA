#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED



void logo();
void menuPrincipal();
void borrarTodo(const char*);
void adios();

//validaciones generales
int pedirEnteroValido();
float pedirFloatValido();
bool esPositivo(int);
bool existeDia(Fecha,int);
bool esBisiesto(int);
bool preguntar(const char *);///

//platos
void submenuPlatos();
void ingresoNuevoPlato();
bool agregarPlato(Plato);
bool iD_PlatoExistente(int);
int indiceIDPlatos(int);
Plato buscarPlato(int);
void modificarPlato();
int modificarRegistroPlatos(int,Plato);
void mostrarListaPlatos();
int mostrarID(int);
void listarPlatosporID();
void eliminarPlato();
void listarPlatosPorRestaurant();
int mostrarIDrestaurant(int);
int iD_RestaurantExistente(int);

//platosNuevas
void ingresoPlatoNuevo();
Plato pedirPlato();
int pedirIDvalidado();
void pedirNombreValido(char *);
float pedirCostoPrepValido();
float pedirValorVentaValido(int);
int pedirTiempoPrepValido();
int pedirIdRestauranteValido();
int pedirComisionRestValido();
int pedirIdCategoria();

//clientes
void submenuClientes();
void nuevoCliente();
int cantidadRegistros(int);
Cliente pedirCliente();
void mostrarCliente(Cliente);//
void mostrarFecha(Fecha);//
bool agregarCliente(Cliente);
bool modificarRegistroCliente(Cliente,int);
int encontrarPosicionCliente(int);
void modificarCliente();
Cliente crearRegModificadoClientes(int);
void listarCliente_porID();
bool mostrarCliente_porPosicion(int pos);
void listarTodosLosClientes();
int cargarListaClientes(Cliente *,int);
void ordenarListaClientes(Cliente*,int);
void mostrarListaClientes(Cliente*,int);
bool bajaLogica(int);
void darDeBajaCliente();

//validaciones en clientes
int validado_IdAutonumerico(int);
int validado_CpCliente();
int validado_Dia(Fecha);
int validado_Mes();
int validado_Anio();
void validado_EmailCliente(char*);
void asignarIdAutonumerico(int*,int);
bool iD_clienteExistente(int);

//Pedidos
void submenuPedidos();
void nuevoPedido();
Pedido pedirPedido();
int validado_IdClienteExistente();
int validado_IdPlatoExistente();
int validado_Cantidad();
float devolverPrecio(int);
int validado_valoracion();
bool agregarPedido(Pedido);
void listarTodosLosPedidos();

#endif // PROTOTIPOS_H_INCLUDED
