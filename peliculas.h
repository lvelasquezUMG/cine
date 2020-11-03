/*Variable para */
int NumeroPeliculas = 0;
//estructuras de datos de las peliculas, segun los campos que necesito
struct Peliculas{
    string Nombre;
    string AnioLanzamiento;
    string Genero;
    string Resenia;
    string Director;
    int AnioProduccion;
};
/*Preparo el puntero, con un maximo de 5000*/
Peliculas *fichas = new Peliculas[maximo];
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
            for(int i = 0; i < Contenido.size(); i=i+6){
                if(NumeroPeliculas < maximo){
                    fichas[NumeroPeliculas].Nombre          = Contenido[i];
                    fichas[NumeroPeliculas].AnioLanzamiento = Contenido[i+1];
                    fichas[NumeroPeliculas].Genero          = Contenido[i+2];
                    fichas[NumeroPeliculas].Resenia         = Contenido[i+3];
                    fichas[NumeroPeliculas].Director        = Contenido[i+4];
                    fichas[NumeroPeliculas].AnioProduccion  = atoi(Contenido[i+5].c_str());
                    NumeroPeliculas++;
                }
            }

        }
    }
    /*Cierro el archivo*/
    Archivo.close();
}