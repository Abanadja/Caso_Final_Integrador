# Caso_Final_Integrador

[Link repositorio](https://github.com/Abanadja/Caso_Final_Integrador)

## 1. Carga de scripts en tiny-lisp
El módulo Labmain.cpp define la función load_script(), que se utiliza para cargar un script en la memoria y aplicarle la coloración sintáctica. Esta función se basa en la librería estándar de C.

Implementa las funciones load_script() y load_script(filename, true) en CLion, de tal manera que puedas abrir y leer archivos de texto. El primer método toma el nombre de un archivo como entrada del usuario, mientras que el segundo muestra el contenido del archivo. Ambos métodos deben cargar el script en la consola.

void load_script(const char* filename, bool show_script = false);
void load_script();
## 2. Asegurando la robustez del código
Asegúrate de que tu código pueda manejar diferentes tipos de errores de entrada. Esto incluye, pero no se limita a:

El usuario proporciona un nombre de archivo que no existe.
El archivo proporcionado no se puede abrir por alguna razón.
Se produce un error de lectura durante la lectura del archivo.
Para manejar estos y otros errores potenciales, es posible que desees agregar comprobaciones de errores adicionales y manejar los fallos de manera más sofisticada.

### Notas
Este ejercicio no requiere el uso de funciones seguras específicas de Microsoft (las funciones con sufijo _s). En cambio, deberías usar las funciones estándar de C/C++ disponibles en todas las plataformas y compiladores, como fopen, printf y scanf.


## Rúbrica
Carga de scripts (50 puntos)

Se proporciona una implementación correcta de load_script(const char* filename, bool show_script = false) que carga correctamente el archivo dado y muestra su contenido si show_script es verdadero. (25 puntos)
Se proporciona una implementación correcta de load_script() que solicita al usuario un nombre de archivo, llama a la función load_script(const char* filename, bool show_script = false) y maneja cualquier error de manera apropiada. (25 puntos)
Manejo de errores (50 puntos)

El código tiene un manejo de errores sólido y completo para el caso de que el nombre del archivo proporcionado no exista. (15 puntos)
El código tiene un manejo de errores sólido y completo para el caso de que el archivo proporcionado no se pueda abrir por alguna razón. (15 puntos)
El código tiene un manejo de errores sólido y completo para el caso de que se produzca un error de lectura durante la lectura del archivo. (20 puntos)
Total: 100 puntos

## Correción práctica Caso Integrador Pablo Alcolea
El trabajo realizado es bastante completo teniendo encuenta cosas como try-catch y teniendo una buena estructura como en lo siguiente:

```cpp
void load_script(const string& filename, bool show_script) {
    string script;

    try {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error: No se ha podido abrir el archivo. " << filename << endl;
            return;
        }

        // Leer el contenido del archivo
        script.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

        if (show_script) {
            ColorConsole::print_colored_text(script, ColorConsole::fg_blue, ColorConsole::bg_white);
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (const ios_base::failure& e) {
        cerr << "Error: Ha ocurrido una excepción leyendo este archivo: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error: Excepción desconocida: " << e.what() << endl;
    }
}
```
Para mejorar no hay muchas cosas importantes, pero se podría añadir 
```cpp
    static void print_colored_text(const string& text, const string& fg_color, const string& bg_color) {
        cout << fg_color << bg_color << text << reset << endl;
    }
```
En el archivo .h no veo necesidad de cambios y ya en el main tenemos el load_script que está bastante bien y como puntos 
a mejorar podríamos tener en cuenta control de excepciones y también una mejor interfaz(secundario para esta práctica)
Por el resto no veo ningun problema y todo perfecto (goty)
