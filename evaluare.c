//Nume : George Caloian
//Grupa : 322 seria CC
//Tema 1 Proiectarea Algoritmilor
//Problema 2


#include <stdio.h>
#include <stdlib.h>

//functie auxiliara - minimul a 3 valori
int min( int a , int b , int c ){
	
	if( c <= b && c <=a ){
		return c;
	}

	else if( b <= a && b <=c ){
		return b;
	}

	else if( a <= b && a <= c){
		return a;
	}

}

int diferenta( int **variante , int *cuvant , int m , int n , int n_cuv ){
	
	int l = m + 1;
	int c = n + 1;
	int i;
	int j;	
	int matrice[l][c];

	for( i = 0 ; i < l ; i++) {

		for( j = 0 ; j < c ; j++) {
			
			if( i == 0 ){ //pentru prima coloana
				matrice[i][j] = j;
			}
			
			else if( j == 0 ){ // pentru prima linie
				matrice[i][j] = i;
				}
				
				else if( variante[cuvant[i-1]][j-1] == 0 ){ 
					//daca nu am litera in nicio varianta pe pozitia
					//corespunzatoare
						matrice[i][j] = min( 1 + matrice[i-1][j] ,
											1 + matrice[i][j-1] ,
											1 + matrice[i-1][j-1] );	
					}			
				
					else{ // in caz contrar
						matrice[i][j] = matrice[i-1][j-1];
					}
		}
	}

	return matrice[l-1][c-1];
	
}
int main(){

	FILE * fin = fopen( "evaluare.in" , "r" );
	FILE * fout = fopen( "evaluare.out" , "w" );

	int NR_VAR;
	int N;
	int **variante;
	int i;
	int j;
	int M;
	int *cuvant;

	fscanf( fin , "%d" , &NR_VAR );
	fscanf( fin , "%d" , &N );


	variante = malloc( 130 * (sizeof ( int* ) ) );

	for( i = 0 ; i < 130 ; i++ ){
		variante[i] = malloc( N *sizeof( int ) );
	}

	int aux;


	// citesc litera cu litera (numar cu numar)
	// si completez matricea de aparitii corespunzator
	for( i = 0 ; i < NR_VAR ; i++ ){
		
		for( j = 0 ; j < N ; j++ ){
		
			fscanf( fin , "%d" , &aux );
			variante[aux][j] = 1;
		}
	}

	fscanf(fin , "%d" , &M );

	cuvant = malloc( M*sizeof( int ) );

	for( i = 0 ; i < M ; i++ ){
		fscanf( fin , "%d" , &cuvant[i] );
	}

	//printez rezultatul aplicarii functiei
	fprintf( fout , "%d" , diferenta( variante , cuvant , M , N , NR_VAR ) );

	fclose(fin);
	fclose(fout);

	return 0;

}
