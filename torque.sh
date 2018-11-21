#PBS -l nodes=3:ppn=16,mem=1gb,walltime=00:10:00
#PBS -M jc.giraldo10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio29

module load anaconda/python3
cd /hpcfs/home/fisi4028/jc.giraldo10/juanGiraldo_Ejercicio29/
make clean
make adveccion