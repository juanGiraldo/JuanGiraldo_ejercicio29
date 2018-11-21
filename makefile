adveccion: advec.c plots.py
	gcc -o Non_linear_advection.c advec.x
	./advec.x
	python advection.py

clean: 
	adveccion.pdf
	cond_init.dat
	Advect.dat
	advect.x