#include <stdio.h>
#include <stdlib.h>

// Definici�n de la funci�n de activaci�n
float funcion_activacion(float x) {
  return x > 0 ? 1 : 0;
}

// Definici�n de la funci�n de error
float error(float y_real, float y_pred) {
  return y_real - y_pred;
}

// Definici�n de la funci�n de actualizaci�n de pesos
void actualizar_pesos(float *w, float *x, float *y_real, float error, float alpha) {
  for (int i = 0; i < 2; i++) {
    w[i] += alpha * error * x[i];
  }
}

// Definici�n de la funci�n principal
int main() {
  // Definici�n de los par�metros del Perceptr�n Simple
  int n_ciclos_maximos = 100;
  float alpha = 0.5;

  // Definici�n de los patrones de entrenamiento
  float x[][2] = {
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
    {0, 0, 1},
  };
  float y[] = {1, 1, 0, 1};

  // Definici�n de los pesos iniciales
  float w[] = {0, 0};

  // Bucle principal
  while (1) {
    // Opci�n 1: Ver / Configurar Perceptr�n
    printf("1. Ver / Configurar Perceptr�n\n");
    printf("2. Ver / Configurar Patrones\n");
    printf("3. Entrenar Perceptr�n\n");
    printf("4. Ejecutar Perceptr�n\n");
    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        // Mostrar los pesos actuales
        printf("Pesos actuales: w0 = %f, w1 = %f\n", w[0], w[1]);

        // Permitir al usuario configurar los pesos
        printf("Ingrese el valor de w0: ");
        scanf("%f", &w[0]);
        printf("Ingrese el valor de w1: ");
        scanf("%f", &w[1]);
        break;

      case 2:
        // Mostrar los patrones actuales
        for (int i = 0; i < 4; i++) {
          printf("Patr�n %d: x1 = %f, x2 = %f, d = %f\n", i + 1, x[i][0], x[i][1], y[i]);
        }

        // Permitir al usuario crear nuevos patrones
        printf("Ingrese el valor de x1 para el nuevo patr�n: ");
        scanf("%f", &x[4][0]);
        printf("Ingrese el valor de x2 para el nuevo patr�n: ");
        scanf("%f", &x[4][1]);
        printf("Ingrese el valor de d para el nuevo patr�n: ");
        scanf("%f", &y[4]);
        break;

      case 3:
        // Entrenar el Perceptr�n
        for (int i = 0; i < n_ciclos_maximos; i++) {
          // Iteraci�n sobre los patrones de entrenamiento
          for (int j = 0; j < 5; j++) {
            // C�lculo de la salida del Perceptr�n
            float y_pred = funcion_activacion(w[0] * x[j][0] + w[1] * x[j][1]);

            // C�lculo del error
            float error_j = error(y[j], y_pred);

            // Actualizaci�n de los pesos
            actualizar_pesos(w, x[j], y[j], error_j, alpha);
          }
        }

        // Imprimir los pesos entrenados
        printf("Pesos entrenados: w0 = %f, w1 = %f\n", w[0], w[1]);
        break;

      case 4:
        // Ejecutar el Perceptr�n
        printf("Ingrese el valor de x1: ");
        scanf("%f", &x[5][0]);
        printf("Ingrese el valor de x2: ");
        scanf("%f", &x[5][1]);

        // C�lculo de la salida del Perceptr�n
        float y_pred = funcion_activacion(w[0] * x[5][0] + w[1] * x[5][1]);

        // Impresi�n de los resultados
        printf("Salida: %f\n", y_pred);
        printf("Error: %f\n", error(y[5], y_pred));
        printf("Net: %f\n", w[0] * x[5][0] + w[1] * x[5][1]);

        break;

      default:
        printf("Opci�n no v�lida.\n");
        break;
    }
  }

  return 0;
}
