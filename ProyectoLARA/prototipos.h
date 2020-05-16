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
bool mallocClientes(Cliente*,int);
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
void pedirApellidoValido(char*);
void pedirDomicilioValido(char*);

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
void mostrarPedido(Pedido);
void modificarPedido();
int encontrarPosicionPedido(int);
bool modificarRegistroPedido(Pedido,int);
Pedido crearRegModificadoPedidos(int);
int validado_estado();
bool mostrarPedido_porPosicion(int);
void listarPedido_porID();

//configuracion
void submenuConfig();
void copiaSeguridad();
void restaurarCopiaSeguridad();
bool bkp_Clientes();
bool escribirBackupClientes(Cliente*,int);
bool bkp_Pedidos();
bool mallocPedidos(Pedido *,int);
bool escribirBackupPedidos(Pedido *,int);
bool escribirBackupPlatos(Plato*,int);
bool mallocPlatos(Plato*,int);
bool bkp_Platos();
int cargarListaPlatos(Plato*,int);
int cargarListaPedidos(Pedido*,int);
bool restaurar_bkp_Clientes();
bool cargarBackupClientes(Cliente*,int);
int cargarListaBKPClientes(Cliente*,int);
bool sobreescribirClientes(Cliente*,int);
bool restaurar_bkp_Pedidos();
bool cargarBackupPedidos(Pedido*,int);
int cargarListaBKPPedidos(Pedido*,int);
bool sobreescribirPedidos(Pedido*,int);
bool restaurar_bkp_Platos();
bool cargarBackupPlatos(Plato*,int);
int cargarListaBKPPlatos(Plato*,int);
bool sobreescribirPlatos(Plato*,int);








#endif // PROTOTIPOS_H_INCLUDED
