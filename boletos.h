//estructuras de datos de los tickets, segun los campos que necesito
struct Boleto{
    int IdPelicula;
    int NumeroBoletos;
    int NumeroButaca;
    string Fecha;
    string HoraFuncion;
    float Golosinas;
    string Sucursal;

};
/*Preparo el puntero, con un maximo de 5000*/
Boleto *boleto = new Boleto[maximo];
int NumeroBoleto=0;
void LeerBoletos(){
     /*Nombre del log*/
    string NombreArchivo = "bd/boletos.log";
    string Linea;
    NumeroBoleto = 0;
    /*Si no existe el archivo, muestro el mensaje*/
    ifstream Archivo(NombreArchivo.c_str());
    if( Archivo.fail() ){
        cout << "No existe el log " << NombreArchivo << endl;
        /*Salir del sistema*/
        exit(1);
    }
    /*Mientras no este en el final del archivo*/
    while (!Archivo.eof()) {
        getline(Archivo,Linea);
        /*Mientras no este en el final del archivo*/
        if (!Archivo.eof()){

            vector <string> Contenido;
            stringstream revisar(Linea);
            string Intermedio;

            while(getline(revisar, Intermedio, '|')){
                /*Guardo el contenido del archivo en el vector*/
                Contenido.push_back(Intermedio);
            }
            /*Recorro los registros del archivo, cada siete espacios separados por pipe es una tupla*/
            for(int i = 0; i < Contenido.size(); i=i+7){
                if(NumeroBoleto < maximo){
                    boleto[NumeroBoleto].IdPelicula = atoi(Contenido[i].c_str());
                    boleto[NumeroBoleto].NumeroBoletos = atoi(Contenido[i+1].c_str());
                    boleto[NumeroBoleto].NumeroButaca= atoi(Contenido[i+2].c_str());
                    boleto[NumeroBoleto].Fecha = Contenido[i+3];
                    boleto[NumeroBoleto].HoraFuncion = Contenido[i+4];
                    boleto[NumeroBoleto].Golosinas = stof(Contenido[i+5].c_str());
                    boleto[NumeroBoleto].Sucursal = Contenido[i+6];
                    NumeroBoleto++;

                }

             }
        }
    }
    /*Cierro el archivo*/
    Archivo.close();
}
void ConfirmarBoleto(){
    /*Primero elimino el archivo, porque no puedo hacer filtro para modificar solo el campo que quiero*/
    remove("bd/boletos.log");
     /*Abro el archivo peliculas*/
    ofstream fichero("bd/boletos.log");
    for(int i = 0; i < NumeroBoleto; i++){
        fichero << boleto[i].IdPelicula << "|" ;
        fichero << boleto[i].NumeroBoletos << "|" ;
        fichero << boleto[i].NumeroButaca << "|" ;
        fichero << boleto[i].Fecha << "|" ;
        fichero << boleto[i].HoraFuncion << "|" ;
        fichero << boleto[i].Golosinas << "|" ;
        fichero << boleto[i].Sucursal << endl;
    }
     /*Cierro el archivo*/
    fichero.close();
}
void AgregarBoleto(){
    int Id = 4999;
    /*Agregar boletos, segun campos ya declarados en el iterador*/
    cout << "***********Formulario para Comprar Boletos************ "<< "\n";
    cout << "Introduce el ID de la pelicula: ";
    cin >> boleto[NumeroBoleto].IdPelicula;
    cin.sync();
    cout << "Introduce el numero de Boletos a Comprar: ";
    cin >> boleto[NumeroBoleto].NumeroBoletos;
    cin.sync();

    cout << "Introduce el numero de butaca: ";
    cin >> boleto[NumeroBoleto].NumeroButaca;
    cin.sync();

    cout << "Introduce fecha de la funcion: ";
    cin >> boleto[NumeroBoleto].Fecha;
    cin.sync();

    cout << "Introduce la hora de la funcion: ";
    getline(cin, boleto[NumeroBoleto].HoraFuncion);
    cin.sync();

    cout << "Introduce el total gastado en golosinas: ";
    cin >> boleto[NumeroBoleto].Golosinas;
    cin.sync();
    /*Id de la pelicula*/
    Id=boleto[NumeroBoleto].IdPelicula;
    /*Precio de la funcion de la pelicula*/
    float PrecioFuncionPorPelicula = pelicula[Id].Precio;
    /*Numero de boletos que estan comprando*/
    int NumeroBoletos=boleto[NumeroBoleto].NumeroBoletos;
    /*Calculo el precio total por los tickets*/
    float total= PrecioFuncionPorPelicula*NumeroBoletos;
    cout << "Total de los boletos: " << total << endl;
    cout << "Total gastado: " << boleto[NumeroBoleto].Golosinas + (total) << endl;
    cout << "Boleto Comprado" << endl;
    /*LLevo el control del numero de boletos*/
    NumeroBoleto++;
    /*Confirmo registro en la bd*/
    ConfirmarBoleto();
    /*Vuelvo a leer los registros*/
    LeerBoletos();
    /*Limpio la pantalla*/
    Limpiar();
}

void VerBoletos(){
    /*Revisar el detalle de boletos*/
    cout << "***********Formulario para Ver los Boletos************ "<< "\n";
    for (int i=0; i < NumeroBoleto; i++){
         /*Id de la pelicula*/
        int Id=boleto[i].IdPelicula;
        /*Precio de la funcion de la pelicula*/
        float PrecioFuncionPorPelicula = pelicula[Id].Precio;
        /*Numero de boletos que estan comprando*/
        int NumeroBoletos=boleto[i].NumeroBoletos;
        /*Calculo el precio total por los tickets*/
        float total= PrecioFuncionPorPelicula*NumeroBoletos;
        cout << "ID: " << i << "\n"
             << "Pelicula: " << pelicula[Id].Nombre  << "\n"
             << "Hora de la funcion: " << boleto[i].HoraFuncion << "\n"
             << "Numero de butaca: " << boleto[i].NumeroButaca << "\n"
             << "Numero de Boletos: " << boleto[i].NumeroBoletos << "\n"
             << "Total de los Boletos: " << total << "\n"
             << "Total gastado: " << boleto[i].Golosinas + (total) << "\n"
             << "Resenia: " << pelicula[Id].Resenia << endl << endl;
    }
     /*Limpio la pantalla*/
    Limpiar();

}




