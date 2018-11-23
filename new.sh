#PBS -l nodes=4,ppn=16, mem=1gb,walltime=00:10:00
#PBS -M jc.giraldo10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio30

module load anaconda/python3
cd /hpcfs/home/fisi4028/jc.giraldo10/JuanGiraldo_ejercicio29/
make clean
make walks
