/*Variable para */
int NumeroPeliculas = 0;
//estructuras de datos de las peliculas, segun los campos que necesito
struct Peliculas{
    string Nombre;
    string AnioLanzamiento;
    string Genero;
    string Resenia;
    string Director;
    string TipoVision;
    string AnioProduccion;
};
/*Preparo el puntero, con un maximo de 5000*/
Peliculas *pelicula = new Peliculas[maximo];
/*Primero leo las peliculas del txt*/
void LeerPeliculas(){
    /*Nombre del txt*/
    string NombreArchivo = "bd/peliculas.log";
    string Linea;
     /*Si no existe el archivo, muestro el mensaje*/
    ifstream Archivo(NombreArchivo.c_str());
    if( Archivo.fail() ){
        cout << "No existe el log  " << NombreArchivo << endl;
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
            /*Recorro los registros del archivo, cada seis espacios separados por pipe es una tupla*/
            for(int i = 0; i < Contenido.size(); i=i+7){
                if(NumeroPeliculas < maximo){
                    pelicula[NumeroPeliculas].Nombre          = Contenido[i];
                    pelicula[NumeroPeliculas].AnioLanzamiento = Contenido[i+1];
                    pelicula[NumeroPeliculas].Genero          = Contenido[i+2];
                    pelicula[NumeroPeliculas].Resenia         = Contenido[i+3];
                    pelicula[NumeroPeliculas].Director        = Contenido[i+4];
                    pelicula[NumeroPeliculas].TipoVision      = Contenido[i+5];
                    pelicula[NumeroPeliculas].AnioProduccion  = Contenido[i+6];
                    NumeroPeliculas++;
                }
            }

        }
    }
    /*Cierro el archivo*/
    Archivo.close();
}
void ConfirmarPeliculas(){
    /*Primero elimino el archivo, porque no puedo hacer filtro para modificar solo el campo que quiero*/
    remove("bd/peliculas.log");
    /*Abro el archivo peliculas*/
    ofstream Archivo("bd/peliculas.log");
    for(int i = 0; i < NumeroPeliculas; i++){
        Archivo << pelicula[i].Nombre << "|" ;
        Archivo << pelicula[i].AnioLanzamiento << "|" ;
        Archivo << pelicula[i].Genero << "|" ;
        Archivo << pelicula[i].Resenia << "|" ;
        Archivo << pelicula[i].Director << "|" ;
        Archivo << pelicula[i].TipoVision << "|" ;
        Archivo << pelicula[i].AnioProduccion << endl;
    }
    /*Cierro el archivo*/
    Archivo.close();

}
void AgregarPeliculas(){
    /*Limitar las peliculas segun variable*/
    if (NumeroPeliculas < maximo){
        cout << "***********Formulario para Agregar Peliculas************ "<< "\n";
        cout << "Agregar nombre a la pelicula"<< "\n";
        getline(cin, pelicula[NumeroPeliculas].Nombre);
        cin.sync();

        cout << "Agregar Anio de Lanzamiento "<< "\n";
        getline(cin, pelicula[NumeroPeliculas].AnioLanzamiento);
        cin.sync();

        cout << "Agregar Genero (Terror, Humor, Ninios, Miedo)"<< "\n";
        getline(cin, pelicula[NumeroPeliculas].Genero);
        cin.sync();

        cout << "Agregar una Resenia de la Pelicula "<< "\n";
        cin >> pelicula[NumeroPeliculas].Resenia;
        cin.sync();

        cout << "Agregar Director "<< "\n";
        getline(cin, pelicula[NumeroPeliculas].Director);
        cin.sync();

         cout << "Agregar tipo de Pelicula (2D o 3D) "<< "\n";
        getline(cin, pelicula[NumeroPeliculas].TipoVision);
        cin.sync();
    
        cout << "Agregar una anio de Produccion "<< "\n";
        pelicula[NumeroPeliculas].AnioProduccion;
        getline(cin, pelicula[NumeroPeliculas].AnioProduccion);
        cin.sync();

        NumeroPeliculas++;

        cout << "Pelicula registrada " << endl;
        /*Confirmo la Pelicula*/
        ConfirmarPeliculas();
         /*Vuelvo a lerr las Pelicula*/
        LeerPeliculas();
        Limpiar();
    }else{
            cout << "Se llenaron las cinco  mil peliculas." << endl;
    }
}

void VerPeliculas(){
    /*Mostrar las peliculas que estan en el iterador*/
    cout << "***********Formulario para Ver Peliculas************ "<< "\n";
    for (int i=0; i < NumeroPeliculas; i++){
        cout << "Orden: " << i << "\n"
        << "Nombre de Pelicula: " << pelicula[i].Nombre << "\n"
        << "Anio de Lanzamiento: " << pelicula[i].AnioLanzamiento << "\n"
        << "Genero: " << pelicula[i].Genero << "\n"
        << "Resenia: " << pelicula[i].Resenia << "\n"
        << "Director: " << pelicula[i].Director << "\n"
        << "Tipo Vision: " << pelicula[i].TipoVision << "\n"
        << "Anio Produccion: " << pelicula[i].AnioProduccion << endl << endl;
    }
    Limpiar();
}
void ModificarPeliculas(){
    int Id = 4999;
    string Respuesta = "";
    /*Pregunto por el id de la pelicula a modificar*/
    cout << "Ingrese el ID de la pelicula: ";
    cin >> Id;
    cin.sync();
    /*Pregunto si en verdad es esa la pelicula*/
    cout << "Pelicula a Modificar" << pelicula[Id].Nombre << " Si/No " << endl;
    getline(cin, Respuesta);
    if(Respuesta == "si"){
        cout << "***********Formulario para Modificar Peliculas************ "<< "\n";
        cout << "Agregar nombre a la pelicula"<< "\n";
        getline(cin, pelicula[Id].Nombre);
        cin.sync();

        cout << "Agregar Anio de Lanzamiento "<< "\n";
        getline(cin, pelicula[Id].AnioLanzamiento);
        cin.sync();

        cout << "Agregar Genero (Terror, Humor, Ninios, Miedo)"<< "\n";
        getline(cin, pelicula[Id].Genero);
        cin.sync();

        cout << "Agregar una Resenia de la Pelicula "<< "\n";
        cin >> pelicula[Id].Resenia;
        cin.sync();

        cout << "Agregar Director "<< "\n";
        getline(cin, pelicula[Id].Director);
        cin.sync();

         cout << "Agregar tipo de Pelicula (2D o 3D) "<< "\n";
        getline(cin, pelicula[Id].TipoVision);
        cin.sync();

        cout << "Agregar una anio de Produccion "<< "\n";
        getline(cin, pelicula[Id].AnioProduccion);
        cin.sync();
         /*Confirmo la Pelicula*/
        ConfirmarPeliculas();
         /*Vuelvo a lerr las Pelicula*/
        LeerPeliculas();
        Limpiar();
    }else{
        cout << "Revise la opcion de ver las Peliculas y filtre de nuevo." << endl;
        Limpiar();
    }
}

void PeliculasPorAnio(){
    /*Variable para guardar el anio a filtrar*/
    string Anio;
    /*Bandera para saber si hay peliculas en el anio*/
    bool Bandera = false;
    cout << "Ingrese anio a Filtrar: "<< "\n";
    cin >> Anio;
    cin.sync();
    system("cls");
    /*Recorro todo el arreglo, buscando las peliculas a filtrar segun el anio ingresado*/
    cout << "***********Peliculas por Anio************ "<< "\n";
    for(int i = 0; i < NumeroPeliculas; i++){
        if(pelicula[i].AnioProduccion == Anio){
            /*Muestro los datos*/
            cout << "ID: " << i << "\n";
            cout << "Nombre: " << pelicula[i].Nombre << "\n";
            cout << "Anio Lanzamiento " << pelicula[i].AnioLanzamiento  << "\n";
            cout << "Tipo Vision: " << pelicula[i].TipoVision  << "\n";
            cout << "Resenia: " << pelicula[i].Resenia  << endl;
            Bandera = true;
        }
    }
    Limpiar();
}

void PeliculasEstreno(){
    /*Saco la fecha y hora del sistema*/
    char fecha[4]; 
    time_t current_time;
    current_time=time(NULL);
    ctime(&current_time);
    strcpy(fecha, ctime(&current_time));
    /*De la fecha y hora, extraigo el anio para poder ver las peliculas de estreno*/
    string Fecha=fecha;
    string anio = Fecha.substr (19,5);
    cout << "***********Peliculas de Estreno, Anio"<< anio <<" ************ "<< "\n";  
    cout << anio << '\n';
     for(int i = 0; i < NumeroPeliculas; i++){
        if(pelicula[i].AnioProduccion == anio){
            cout << "ID: " << i << "\n"
            << "Nombre: " << pelicula[i].Nombre << "\n"
            << "Tipo Vision: " << pelicula[i].TipoVision << "\n"
            << "Resenia: " << pelicula[i].Resenia << endl << endl;
        }
    }
    /*Limpio la pantalla*/
    Limpiar();
}