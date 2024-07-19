#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>


int main()
{
    float fpes [1][2] = {{0},{0}};
    float fumb = 0,fErr = 0;
    int ides[4] = {1,1,1,0};
    int iOp, iOp2,iOp3,p,p2,iCont = 0;
    int iSalir;
    float ifact = 0.5, fNet[4][1],fy[4][1],fError[4];
    int iCicl = 100;
    int iPat[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    int continuar;

    do {
        printf ("MENU RPINCIPAL");
        printf("\n 1.VER/CONFIGURAR PERCEPTRON\n 2.VER/CONFIGURAR PATRONES\n 3.ENTRENAR PERCEPTRON\n 4.EJECUTAR PERCEPTRON\n 5.SALIR\n");
        printf ("SELECCIONE UNA DE LAS OPCIONES \n");
         while (iSalir){
         printf ("OPCION: ");
         scanf ("%d",&iOp);
            if (iOp > 5 || iOp < 1){
                iSalir = 1;
                system("cls");
            }
            else {
               iSalir = 0;
                    }
        }
                srand(time(NULL));
                for (int i = 0; i < 2; i++){
                 fpes[0][i] = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
                }
                fumb = ((float)rand() / RAND_MAX) * 2.0 - 1.0;
        switch (iOp) {
            case 1:
                system("cls");
                printf ("INGRESE EL NUMERO DE CICLOS MAX 100: ");
                scanf ("%d",&iCicl);
                printf ("INGRESE EL FACTOR DE APRENDIZAJE: ");
                scanf ("%f",&ifact);
                printf("Pesos = [%f %f]\n", fpes[0][0], fpes[0][1]);
                printf("Umbral = %f\n",fumb);
                printf ("alpha: %f\n",ifact);
                printf ("nciclos: %d\n",iCicl);
            break;
            case 2:
                system("cls");
                printf ("1.CREAR PATRON \n");
                printf ("2.LEER Y MOSTRAR PATRON \n");
                printf ("3.EDITAR Y ACUTALIZAR PATRON \n");
                printf ("4.BORRAR PATRON\n");
                printf ("SELECCIONE UNA DE LAS OPCIONES \n");
                scanf ("%d",&iOp2);

                switch (iOp2){
                    case 1:
                          system("cls");
                          for (int i = 0; i < 4; i++) {
                            printf("INGRESE EL PATRON %d:\n", i+1);
                            for (int j = 0; j < 2; j++) {
                                printf("[%d][%d]: ", i, j);
                                scanf("%d", &iPat[i][j]);
                            }
                          }
                        for (int i = 0; i < 4; i++){
                            printf ("INGRESE EL VALOR ESPERADO PARA EL PATRON %d \n", i + 1);
                            scanf("%d", &ides[i]);
                        }
                        system("cls");
                        printf("LOS PATRONES INGRESADOS SON :\n");
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 2; j++) {
                                printf("\t%d\t ", iPat[i][j]);
                            }
                            printf ("\n");
                        }
                        printf("LOS VALORES ESPERADOS SON :\n");
                        for (int i = 0; i < 4; i++){
                            printf ("\t%d \n", ides[i]);

                        }
                    break;
                    case 2:
                        system("cls");
                        printf("LOS PATRONES ACTUALES SON :\n");
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 2; j++) {
                                printf("\t%d\t ", iPat[i][j]);
                            }
                            printf ("\n");
                        }
                        printf("LOS VALORES ESPERADOS ACTUALES SON :\n");
                        for (int i = 0; i < 4; i++){
                            printf ("\t%d \n", ides[i]);}
                    break;

                    case 3:
                        system("cls");
                        printf ("SELECCIONE QUE DESEA EDITAR 1.PATRONES\n 2.VALORES ESPERADOS \n");
                        scanf ("%d",&iOp3);

                        switch (iOp3){
                        case 1 :
                            printf("LOS PATRONES ACTUALES SON :\n");
                            for (int i = 0; i < 4; i++) {
                                for (int j = 0; j < 2; j++) {
                                    printf("\t%d\t ", iPat[i][j]);
                                }
                                printf ("\n");
                            }
                            printf("INGRESE EL NUMERO DEL PARTRON QUE DESA ACTUALIZAR 1 <= P <= 4 \n");
                            scanf ("%d",& p );

                            printf ("INGRESE EL NUEVO PATRON \n");
                            switch (p){
                                case 1:
                                    printf("[%d][%d]: ", 0, 0);
                                    scanf("%d", &iPat[0][0]);
                                    printf("[%d][%d]: ", 0, 1);
                                    scanf("%d", &iPat[0][1]);
                                break;
                                case 2:
                                    printf("[%d][%d]: ", 1, 0);
                                    scanf("%d", &iPat[1][0]);
                                    printf("[%d][%d]: ", 1, 1);
                                    scanf("%d", &iPat[1][1]);
                                break;
                                case 3:
                                    printf("[%d][%d]: ", 2, 0);
                                    scanf("%d", &iPat[2][0]);
                                    printf("[%d][%d]: ", 2, 1);
                                    scanf("%d", &iPat[2][1]);
                                break;
                                case 4:
                                    printf("[%d][%d]: ", 3, 0);
                                    scanf("%d", &iPat[3][0]);
                                    printf("[%d][%d]: ", 3, 1);
                                    scanf("%d", &iPat[3][1]);
                                break;
                                default:
                                     printf ("OPCION NO VALIDA");
                                break;
                                }
                        break;
                        case 2:
                            printf("LOS VALORES ESPERADOS ACTUALES SON :\n");
                            for (int i = 0; i < 4; i++){
                            printf ("\t%d \n", ides[i]);}
                            printf ("INGRESE EL NUMERO  DEL VALOR ESPERADO QUE DESEA ACUTALIZAR 1<= E <=4 \n");
                            scanf("%d",&p2);
                            printf ("INGRESE EL NUEVO VALOR ESPERADO \n");
                              switch (p2){
                                case 1:
                                    scanf("%d", &ides[0]);
                                break;
                                case 2:
                                    scanf("%d", &ides[1]);
                                break;
                                case 3:
                                    scanf("%d", &ides[2]);
                                break;
                                case 4:
                                    scanf("%d", &ides[3]);
                                break;
                                default:
                                     printf ("OPCION NO VALIDA");
                                break;
                                }
                        break;
                        default:
                            printf ("OPCION NO VALIDA");
                        break;
                        }
                    break;
                    case 4:
                      for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 2; j++) {
                            iPat [i][j] = 0;
                        } }
                      for (int i = 0; i < 4; i++){
                           ides [i] = 0;
                        }
                    printf ("LOS PATRONES Y VALORES ESPERADOS SE HAN BORRADO CON EXITO \n");
                    break;
                   default:
                     printf ("OPCION NO VALIDA");
                    break; }
            break;
            case 3:
                // VALOR INICIAL DE LOS PESOS;
                 printf ("EL VALOR INICIAL DE LOS PESOS ES:\n");
                 printf("PESOS = [%f %f]\n", fpes[0][0], fpes[0][1]);
                do{
                // CALCULO DE LA NET
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 2 ; j++){
                fNet[i][0] = fpes[0][0]*iPat[i][j] + fpes[0][1]*iPat[i][j] + fumb;
                }}
                // CALCULO DE LA SALIDA
                for (int i = 0; i < 4; i++){
                   fy[i][0] = (1/(1+ exp(-fNet[i][0])));
                }

                // ACTUALIZACION DE LOS PESOS
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 2; j++){
                       fpes[0][j] = fpes [0][j] + ifact*(ides[i]- fy[i][0])*iPat[i][j];
                    }
                }

                // SE CALCULA EL ERROR
                for (int i = 0;i < 4; i++){
                    fError[i] = ides[i]-fy[i][1];
                }
                iCont++;
                fErr = fError[0] + fError[1] + fError [2] + fError[3];
                fErr = pow(fErr,2);
                }while(fErr != 0 && iCont < iCicl);
                if (iCont >= 100){
                    printf("SE CUMPLIERON LA CANTIDAD DE CICLOS ESTABLECIDA CICLOS = %d",iCont);
                }
                // MOSTRAR NET
                printf("\n NET FINAL:\n");
                for (int i = 0; i < 4; i++){
                    printf("Net = %f \n",fNet[i][0]);
                }

                // VALOR FINAL DE LOS PESOS
                printf("EL VALOR FINAL DE LOS PESOS ES: \n");
                printf("PESOS = [%f %f]\n", fpes[0][0], fpes[0][1]);

                  // MOSTRAR SALIDA
                  printf("SALIDA FINAL:\n");
                printf("\n");
                for (int i = 0; i < 4; i++){
                    printf("%f \n",fy[i][0]);
                }
                // ERROR PARA TODOS LOS PESOS
                printf("EL ERROR FINAL PARA TODOS LOS PATRONES ES: \n");
                for (int i = 0;i < 4; i++){
                   printf("%f \n",fError[i]);
                }
                printf("ERROR GLOBLAL FINAL ES %f: \n",fErr);

            break;
            case 4:
            break;
            case 5:
                return 0;
            break;
            default:
            printf("Opción no válida. Por favor, elige nuevamente.\n");
            break;
        }
         printf("PRESIONE ENTER PARA CONTINUAR...");
        _getch(); // Esperar a que el usuario presione Enter
         system("cls");
         iOp = 0;
         iSalir = 1;
    } while (1);

    return 0;
}
