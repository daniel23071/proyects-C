#include <stdio.h>
#include <stdlib.h>

// Definición de la función de activación
float funcion_activacion(float x) {
  return x > 0 ? 1 : 0;
}

// Definición de la función de error
float error(float y_real, float y_pred) {
  return y_real - y_pred;
}

// Definición de la función de actualización de pesos
void actualizar_pesos(float *w, float *x, float *y_real, float error, float alpha) {
  for (int i = 0; i < 2; i++) {
    w[i] += alpha * error * x[i];
  }
}

// Definición de la función principal
int main() {
  // Definición de los parámetros del Perceptrón Simple
  int n_ciclos_maximos = 100;
  float alpha = 0.5;

  // Definición de los patrones de entrenamiento
  float x[][2] = {
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
    {0, 0, 1},
  };
  float y[] = {1, 1, 0, 1};

  // Definición de los pesos iniciales
  float w[] = {0, 0};

  // Bucle principal
  while (1) {
    // Opción 1: Ver / Configurar Perceptrón
    printf("1. Ver / Configurar Perceptrón\n");
    printf("2. Ver / Configurar Patrones\n");
    printf("3. Entrenar Perceptrón\n");
    printf("4. Ejecutar Perceptrón\n");
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
          printf("Patrón %d: x1 = %f, x2 = %f, d = %f\n", i + 1, x[i][0], x[i][1], y[i]);
        }

        // Permitir al usuario crear nuevos patrones
        printf("Ingrese el valor de x1 para el nuevo patrón: ");
        scanf("%f", &x[4][0]);
        printf("Ingrese el valor de x2 para el nuevo patrón: ");
        scanf("%f", &x[4][1]);
        printf("Ingrese el valor de d para el nuevo patrón: ");
        scanf("%f", &y[4]);
        break;

      case 3:
        // Entrenar el Perceptrón
        for (int i = 0; i < n_ciclos_maximos; i++) {
          // Iteración sobre los patrones de entrenamiento
          for (int j = 0; j < 5; j++) {
            // Cálculo de la salida del Perceptrón
            float y_pred = funcion_activacion(w[0] * x[j][0] + w[1] * x[j][1]);

            // Cálculo del error
            float error_j = error(y[j], y_pred);

            // Actualización de los pesos
            actualizar_pesos(w, x[j], y[j], error_j, alpha);
          }
        }

        // Imprimir los pesos entrenados
        printf("Pesos entrenados: w0 = %f, w1 = %f\n", w[0], w[1]);
        break;

      case 4:
        // Ejecutar el Perceptrón
        printf("Ingrese el valor de x1: ");
        scanf("%f", &x[5][0]);
        printf("Ingrese el valor de x2: ");
        scanf("%f", &x[5][1]);

        // Cálculo de la salida del Perceptrón
        float y_pred = funcion_activacion(w[0] * x[5][0] + w[1] * x[5][1]);

        // Impresión de los resultados
        printf("Salida: %f\n", y_pred);
        printf("Error: %f\n", error(y[5], y_pred));
        printf("Net: %f\n", w[0] * x[5][0] + w[1] * x[5][1]);

        break;

      default:
        printf("Opción no válida.\n");
        break;
    }
  }

  return 0;
}
