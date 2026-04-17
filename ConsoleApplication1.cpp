#include <iostream>
#include <iomanip> // Para dar formato a los decimales

using namespace std;

int main() {
    // Definición de constantes y variables
    const int MAX_ESTUDIANTES = 20;
    const int NOTAS_POR_ESTUDIANTE = 4;

    double promedios[MAX_ESTUDIANTES];
    int numEstudientes;

    // Variables para estadísticas
    double sumaGeneral = 0;
    double notaMasAlta = -1; // Iniciamos en -1 para que cualquier 0 sea mayor
    double notaMasBaja = 101; // Iniciamos en 101 para que cualquier 100 sea menor
    int aprobados = 0;
    int reprobados = 0;

    //  Solicitar cantidad de estudiantes con validación
    do {
        cout << "Ingrese la cantidad de estudiantes (máximo " << MAX_ESTUDIANTES << "): ";
        cin >> numEstudientes;
        if (numEstudientes < 1 || numEstudientes > MAX_ESTUDIANTES) {
            cout << "Error: Cantidad no permitida.\n";
        }
    } while (numEstudientes < 1 || numEstudientes > MAX_ESTUDIANTES);

    // Captura de datos y procesamiento
    for (int i = 0; i < numEstudientes; i++) {
        double sumaNotasEstudiante = 0;
        cout << "\n--- Estudiante " << i + 1 << " ---\n";

        for (int j = 0; j < NOTAS_POR_ESTUDIANTE; j++) {
            double nota;
            // Validación de rango de calificación (0-100)
            do {
                cout << "  Ingrese calificacion " << j + 1 << ": ";
                cin >> nota;
                if (nota < 0 || nota > 100) {
                    cout << "  Error: La nota debe estar entre 0 y 100.\n";
                }
            } while (nota < 0 || nota > 100);

            sumaNotasEstudiante += nota;

            // Determinar nota más alta y baja a nivel general
            if (nota > notaMasAlta) notaMasAlta = nota;
            if (nota < notaMasBaja) notaMasBaja = nota;
        }

        // Calcular y almacenar promedio individual
        promedios[i] = sumaNotasEstudiante / NOTAS_POR_ESTUDIANTE;
        sumaGeneral += promedios[i];

        // Contar aprobados y reprobados
        if (promedios[i] >= 70) {
            aprobados++;
        }
        else {
            reprobados++;
        }
    }

    // Mostrar resultados
    cout << "\n========================================";
    cout << "\n       REPORTE DE CALIFICACIONES";
    cout << "\n========================================\n";
    

    for (int i = 0; i < numEstudientes; i++) {
        cout << "Estudiante " << i + 1 << " | Promedio: " << promedios[i] << endl;
    }

    cout << "----------------------------------------\n";
    cout << "Promedio general del grupo: " << sumaGeneral / numEstudientes << endl;
    cout << "Calificacion más alta registrada: " << notaMasAlta << endl;
    cout << "Calificacion más baja registrada: " << notaMasBaja << endl;
    cout << "----------------------------------------\n";
    cout << "Estudiantes que Aprobaron: " << aprobados << endl;
    cout << "Estudiantes que Reprobaron: " << reprobados << endl;
    cout << "========================================\n";

    return 0;
}
