make compile

exec_files=$(ls *.exec)

for exec_file in $exec_files
do
    ./$exec_file -s 0 -l 100000
done

make clean
