# /bin/bash
i=`shuf -i 1-3 -n 1`
i=`shuf -i 1-3 -n 1`
i=`shuf -i 1-3 -n 1`

#echo $i
case $i in
	1)    
                mkdir lab_exam
                echo "----------------------------------------------------------------"
		        echo "A working directory called lab_exam has been created for you."
		        echo "The problem statement is provided in a file p1 within lab_exam"
		        echo "---------------------------------------------------------------"
                cp ./.p1 ./lab_exam/p1
		;;
	
	2)           mkdir lab_exam
                echo "----------------------------------------------------------------"
		        echo "A working directory called lab_exam has been created for you."
		        echo "The problem statement is provided in a file p2 within lab_exam"
		        echo "---------------------------------------------------------------"
                cp ./.p2 ./lab_exam/p2
		;;
	
	3)         mkdir lab_exam
		       echo "---------------------------------------------------------------"
		       echo "A working directory called lab_exam has been created for you."
		       echo "The problem statement is provided in a file p3 within lab_exam"
		       echo "---------------------------------------------------------------"
                cp ./.p3 ./lab_exam/p3
		;;
       
	
		




  esac
