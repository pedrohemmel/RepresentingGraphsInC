#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Constants
#define max 10

//Variables
int size = 0;
int graph[max];
int matrix[max][max];

//prototipação
int getSizeOfGraph();
void graphInserting();
void graphDraw();
void graphDrawMatrix();
void graphRemoving();
int showMenu();

//Defining the number of graph vertices
int getSizeOfGraph() {
  int newSize;
  printf("\nDigite a quantidade de vértices que deseja ter no seu grafo: ");
  scanf("%d", &newSize);
  return newSize;
}

//Function that will request the number of the vertice to the user
void graphInserting() {
  int originNum, destinyNum;

  system("cls");
  printf("\nEscolha o vertice de origem entre 0 e %d: ", size-1);
  scanf("%d", &originNum);

  printf("\nEscolha o vertice de destino entre 0 e %d: ", size);
  scanf("%d", &destinyNum);

  if(originNum > size-1 || destinyNum > size-1 || originNum < 0 || destinyNum < 0) {
    printf("\nO número digitado é inválido, digite um número para o vertice entre 0 e %d\n", size);
    system("pause");
  } else {
    matrix[originNum][destinyNum] = 1;
    matrix[destinyNum][originNum] = 1;
  }
}

//Removing the number of graph vertices
void graphRemoving() {
    int originNum, destinyNum;

  system("cls");
  printf("\nEscolha o vertice de origem entre 0 e %d: ", size-1);
  scanf("%d", &originNum);

  printf("\nEscolha o vertice de destino entre 0 e %d: ", size);
  scanf("%d", &destinyNum);

  if(originNum > size-1 || destinyNum > size-1 || originNum < 0 || destinyNum < 0) {
    printf("\nO número digitado é inválido, digite um número para o vertice entre 0 e %d\n", size);
    system("pause");
  } else {
    matrix[originNum][destinyNum] = 0;
    matrix[destinyNum][originNum] = 0;
  }
}

//Function that print an array with the maxSize of numbers
void graphDraw() {
  printf("Lista de vertices \n[");
  for(int i = 0; i < size; i++) {
    printf(" %d ", graph[i]);
  }
  printf("]\n\n");
}

//Function that will draw the adjacent matrix 
void graphDrawMatrix() {
  printf("Matriz de adjacencias \n[\n");
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
  printf("]\n");
}



//Function that will let the user choose the operations that (s)he wants
int showMenu() {
  int decisao;
  if(size == 0 || size > max) {

    if(size > max) {
      printf("O tamanho do seu grafo é maior que o tamanho máximo implementado. Digite um número de 1 a %d.", max);
    }
    
    printf("\n\nEscolha uma opção com base em grafos. \n");

    printf("\nDigite <1> para difinir o tamanho do seu novo grafo;\n");
    
    scanf("%d", &decisao);

    switch(decisao) {
      case 1:
        size = getSizeOfGraph();
      break;
      default: 
      return 1;
    }
  } else if(size != 0) {

    //Defining the values of the graph
    for(int i = 0; i < size; i++) {
        graph[i] = i;
    }

    printf("\n\nEscolha uma opção com base em grafos. \n");

    printf("\nDigite <1> para inserir um novo vertice ao seu grafo;\n");
    printf("\nDigite <2> para remover um vertice ao seu grafo;\n");
    printf("\nDigite <3> para desenhar seu grafo;\n");
    printf("\nDigite <4> para desenhar seu grafo adjacente;\n");
    printf("\nDigite <5> para parar a operação;\n");
    
    scanf("%d", &decisao);

    switch(decisao) {
      case 1:
        graphInserting();
      break;
      case 2: 
        graphRemoving();
      break;
      case 3:
        graphDraw();
      break;
      case 4:
        graphDrawMatrix();
      break;
      case 5: 
      return 1;
      default: 
      return 2;
    }
  }

  int op;
  printf("Se deseja continuar a operação, digite <1>, caso contrário, digite 2: ");
  scanf("%d", &op);
  
  return op;
}






int main(void) {
  
  while(showMenu() == 1) {}
  return 0;
}