//Nume : George Caloian
//Grupa : 322 seria CC
//Tema 1 Proiectarea Algoritmilor
//Problema 1


#include <stdio.h>
#include <stdlib.h>


//functia auxiliara - minimul a 2 numere
int min( int a , int b ){
	
	if( a > b ){
		return b;
	}

	else{
		return a;
	}
}

//functie auxiliara - lungimea unui cuvant
int length( char* a ){
	
	int i = 0;

	while( a[i] != '\0' ){
		i++;
	}
	return i;
}


int solve( char* cuvant ){
	
	int i = 0; //indicele cu care plec de la inceputul cuvantului
	int j = length(cuvant) - 1; //indicele cu care plec de la final
	int p;
	int k;
	int res = 0;	

	while( i < j ){ //cat timp nu am ajuns la jumatate
		
		int peri = 1;
		int perj = 1;
		
		if( cuvant[i] == cuvant[j] ){
			//daca cele 2 litere coincid este OK si trec mai departe
			//(ma duc spre centru)
			i++;
			j--;
		}
		
		else{ //daca ele difera am nevoie de interschimbari
			
			for( p = i + 1 ; p <= j ; p++ ){ 
			//caut litera de pe pozitia j plecand de la pozitia i
				
				if( cuvant[p] != cuvant[j] ){
					peri++;
					// contorizez cat de mult m-am indepartat de pozitia i
				}
				
				else{			
					break;
				}

			}
			
			for( k = j - 1 ; k >= i ; k-- ){
			//caut litera de pe pozitia i plecand de la pozitia j
				
				if( cuvant[k] != cuvant[i] ){
					perj++;
					// contorizez cat de mult m-am indepartat de pozitia j
				}
				
				else{
					break;
				}

			}

			if( peri == perj && peri == ( ( j - i ) ) ){
				// daca niciun din cautari nu a dat roade insemana ca nu putem
				//forma un palindrom
				return -1;
			}
		
			if( min( peri , perj ) == peri ){ 
				// cazul in care prima parcurgere a gasit o solutie
				//viabila mai rapid
				char aux;
					
				aux = cuvant[i + peri]; // salvez litera gasita
				
				int m;
				for( m = i + peri ; m > i ; m-- ){ 
					cuvant[m] = cuvant[m - 1]; 
					// shiftez intregul cuvant intre pozitia i si pozitia 
					//literei ce coincide cu cea de pe poz j
				}
				
				cuvant[i] = aux; // aduc acea litera in pzoitia corecta 
			
				res = res + peri; 
				// adun numarul de interschimbari la numarul total
			}	
			else{ 
				// absolut identic pentru cazul in care a 2-a parcurgere 
				// este mai buna ( mai scurta )
				
				char aux;
					
				aux = cuvant[j - perj];

				int n;
				
				for( n = j - perj ; n < j ; n++ ){
					cuvant[n] = cuvant[n+1];
				}

				cuvant[j] = aux;
				
				res = res + perj;
			}
		}
		
	}

    return res;
}

int main(){

	int N = 0;
  
    FILE * fin = fopen("joc.in", "r");
    FILE * fout = fopen("joc.out", "w");

    fscanf( fin, "%d", &N );
	
    char words[350];
	
	int i;
    for ( i = 1; i <= N; ++ i ){
		fscanf( fin, "%s\n", words );
		fprintf( fout, "%d\n", solve(words) );
	}

	fclose(fin);
    fclose(fout);
	
    return 0;
}
