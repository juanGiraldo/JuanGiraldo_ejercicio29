#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*global vars*/

float delta_x;
float t_max;
float delta_t;
float L;
int N ;

/* crea las condiciones iniciales*/

void initial(float *x, float *u){

	int i;
		
	for(i= 1; i< N; i++){
		x[i]= x[i-1]+delta_x;		
	}
	
	i=0;
	while(x[i]<2.0){
		u[i]=1.0;
		i++;
	}
	
}

void flux(float *U_out, float *U_in){
	int i;
	
	for(i=0;i<N;i++){
		U_out[i]= 0.5*pow(U_in[i],2);
	}
}

void Lax(float *u, float *u_f){
	int N_t;
	int i;
	int j;
	float *F;
	float *ub;
	
	N_t = (t_max/delta_t);
	F= malloc(N*sizeof(float));
	ub= malloc(N*sizeof(float));
	
	/* copiamos u*/
	for(i=0;i<N;i++){
		u_f[i]= u[i];
		ub[i] = u[i];
	}	
	
	for(i=0;i<N_t;i++){
		flux(F,u);
		
		for(j=0;j<N-2;j++){
			ub[j+1] = 0.5*(u[j+2]+u[j]);
			u_f[j+1] = ub[j+1] - (0.5 * (delta_t/delta_x) * (F[j+2] - F[j]));
			/*ahora actualizamos u*/
		}
		
		for(j=0;j<N;j++){
		u[j]= u_f[j];
		}
	}
}

void files(float *U_out){
	/*Crea archivos .dat con los resultados para ser procesados en python*/
	FILE *fsample;
	fsample = fopen("Advect.dat", "w+"); 
	int i;
	
	for(i=0; i<N; i++){
		fprintf(fsample, "%f \n", U_out[i]);
	}
	
	fclose(fsample); //closes the stream
}	

	
/*--------main boi -----------*/

int main(int argc, char *argv[]){

float *X;
float *U;
float *U_final;
int t_i;
float t_max_values[4];
FILE *finit;

/*inicializa todo*/

delta_x=0.05;
L=4.0;
N = (L/delta_x)+1;
t_max = 0.45;
delta_t = 0.015;


X=malloc(N*sizeof(float));
U=malloc(N*sizeof(float));
U_final=malloc(N*sizeof(float));

initial(X,U);


/*Crea el .dat con la condicion inicial*/
	
finit = fopen("cond_init.dat", "w+"); 
int index;
	
for(index=0; index<N; index++){
	fprintf(finit, "%f \n", U[index]);
	}
	
fclose(finit); 

// solucions

Lax(U, U_final);

files(U_final);

	
return 0;	
}