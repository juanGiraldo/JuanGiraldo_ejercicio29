walks: walk.c walk_omp.c walking_hist.py
        gcc -fopenmp walk_omp.c walk_omp.x
        gcc -o walk.c walk.x
        ./walk.x
        ./walk_omp.x
        python walking_hist.py

adveccion: advec.c plots.py
	gcc -o Non_linear_advection.c advec.x
	./advec.x
	python advection.py

clean: 
	adveccion.pdf
	cond_init.dat
	Advect.dat
	advect.x
        caminatas.pdf
