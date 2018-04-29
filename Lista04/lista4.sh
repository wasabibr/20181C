
#!/bin/bash

declare -A sumarioAcertos
declare -A sumarioTotal
declare -A sumarioStatus
vermelho='\033[0;31m'
verde='\033[0;32m'
normal='\033[0m'
azul='\033[0;36m'
amarelo='\033[44m'

avaliar () {
	file=$1
	if ! [ -n "${sumarioTotal[$1]}" ]; then
		echo -e "${amarelo}              problema $1            ${normal}"
	fi
	sumarioTotal[$1]=$((sumarioTotal[$1]+1))
	if ! [ -n "${sumarioAcertos[$1]}" ]; then
		sumarioAcertos[$1]=0
	fi
	if [ -f $file.c ]; then
		charset="$(file -bi "$file.c" | awk -F "=" '{print $2}')"
		if [ "$charset" != utf-8 ]; then
			iconv -f "$charset" -t utf8 "$file.c" -o tmp.c
			mv tmp.c "$file.c"
		fi
		if gcc $file.c -lm  2> /dev/null; then
			echo -e "$2" > input
			echo -e "$3" > gabarito
			timeout 2 ./a.out < input > output
			printf 'Teste %d: ' ${sumarioTotal[$1]}
			if ! diff -wB output gabarito > /dev/null; then
				echo -e "${vermelho} [x]${normal}"
				#echo -e '\tEntrada:' "${azul} $2 ${normal}"
				echo -e '\tSaída do seu programa:' "${azul} $(cat output) ${normal}"
				echo -e '\tSaída esperada:' "${azul} $3 ${normal}"
			else
				echo -e "${verde} [ok] ${normal}"
				sumarioAcertos[$1]=$((sumarioAcertos[$1]+1))
			fi
		else
			sumarioStatus[$1]='código '$file.c' não compila'
		fi
	else
		sumarioStatus[$1]='código '$file.c' não existe'
	fi
}

avaliar 'q1' '..***.*..* 0' '0'
avaliar 'q1' '..***.*..* 1' '1'
avaliar 'q1' '..***.*..* 5' '2'
avaliar 'q1' '..***.*..* 4' 'bum!'
avaliar 'q1' '..***.*..* 9' 'bum!'
avaliar 'q1' '..***.*..* 8' '1'
avaliar 'q1' '* 0' 'bum!'
avaliar 'q1' '- 0' '0'
avaliar 'q1' '-* 1' 'bum!'
avaliar 'q1' '*- 1' '1'
avaliar 'q1' '-* 0' '1'
avaliar 'q1' '-- 1' '0'

avaliar 'q2' '19 2.31 6.09 0.80 1.94 3.18 2.62 0.92 2.05 2.57 5.56 2.36 8.62 4.00 9.12 9.02 1.68 5.85 4.02 6.22 ' '7'
avaliar 'q2' '29 5.81 3.60 6.65 9.43 5.14 6.25 2.00 0.10 8.70 7.40 8.13 4.91 8.89 2.54 6.40 1.25 1.08 5.79 7.05 2.31 4.65 0.74 1.95 7.60 4.10 8.27 9.78 0.04 8.29 ' '16'
avaliar 'q2' '23 6.08 5.09 1.10 8.27 2.73 7.66 7.22 7.10 8.15 4.08 5.73 8.20 7.78 6.21 4.61 2.22 1.12 8.74 4.69 9.75 1.51 5.37 0.21 ' '12'
avaliar 'q2' '24 3.85 2.40 0.86 3.97 3.57 3.13 8.44 4.77 9.91 0.31 3.28 4.27 9.92 4.90 8.83 2.52 7.96 5.64 7.20 4.69 8.92 3.59 6.95 8.73 ' '10'

avaliar 'q3' 'tres pratos de trigo para tres tigres tristes' 'b c f h j k l m n q u v w x y z'
avaliar 'q3' 'mais vale um passaro na mao do que dois voando' 'b c f g h j k t w x y z'
avaliar 'q3' 'The quick brown fox jumps over the lazy dog' ''
avaliar 'q3' 'Gazeta publica hoje breve nota de faxina na quermesse' 'g k w y'
avaliar 'q3' 'gazeta publica hoje breve nota de faxina na quermesse' 'k w y'

avaliar 'q4' '4 1 4 3 7' 'não'
avaliar 'q4' '4 1 4 3 2' 'sim'
avaliar 'q4' '4 0 4 2 1' 'não'
avaliar 'q4' '4 1 1 2 3' 'não'
avaliar 'q4' '4 1 4 3 2' 'sim'
avaliar 'q4' '1 1' 'sim'
avaliar 'q4' '1 0' 'não'
avaliar 'q4' '5 5 4 3 2 1' 'sim'
avaliar 'q4' '5 4 5 2 3 6' 'não'
avaliar 'q4' '5 5 5 5 4 3' 'não'
avaliar 'q4' '7 6 4 3 1 2 5 7' 'sim' 

avaliar 'q5' '1 2 3 4 5 6 7 8 9 0' '0'
avaliar 'q5' '5 4 2 8 7 4 2 1 0 2' '4'
avaliar 'q5' '3 2 4 6 8 1 4 5 9 7' '4'
avaliar 'q5' '5 2 1 4 6 1 4 0 1 0' '1'
avaliar 'q5' '4 3 7 4 2 8 9 5 2 6' '2'
avaliar 'q5' '7 9 3 1 2 8 9 4 6 5' '9'
avaliar 'q5' '2 5 4 0 3 7 5 5 5 5' '0'

avaliar 'q6' '4 1 2 3 4 1 5 3 5' '2 acertos'
avaliar 'q6' '4 1 2 3 4 1 2 3 4' '4 acertos'
avaliar 'q6' '7 1 2 3 2 1 5 4 3 3 3 3 3 3 3' '1 acerto'
avaliar 'q6' '7 1 2 3 2 1 5 4 1 2 2 2 2 5 5' '4 acertos'
avaliar 'q6' '20 4 5 3 2 1 2 5 3 2 4 1 5 4 4 4 2 3 4 2 3  4 4 2 2 2 3 5 4 2 2 1 4 1 4 4 3 3 5 2 3' '10 acertos'

avaliar 'q7' '4 1 1 1 1' '1 2 3 4 1'
avaliar 'q7' '10 1 2 3 4 5 4 3 2 1 0' '5 5'
avaliar 'q7' '5 0 0 0 1 1' '4 5 1'
avaliar 'q7' '1 1' '1 1'
avaliar 'q7' '5 20 21 23 14 14' '3 23'
avaliar 'q7' '10 5 5 6 6 7 7 8 8 7 7' '7 8 8'
avaliar 'q7' '10 8 8 8 5 5 8 8 5 5 5' '1 2 3 6 7 8'

avaliar 'q8' 'teste e' '2'
avaliar 'q8' 'quadrado a' '2'
avaliar 'q8' 'caramba a' '3'
avaliar 'q8' 'bbbbbbbbbbbbbb b' '14'
avaliar 'q8' 'bbbbbbbbbbbbba b' '13'

avaliar 'q9' 'O seguro morreu de velho' 'ohlev ed uerrom oruges O'
avaliar 'q9' 'ohlev ed uerrom oruges O' 'O seguro morreu de velho'
avaliar 'q9' 'The quick brown fox jumps over the lazy dog' 'god yzal eht revo spmuj xof nworb kciuq ehT'
avaliar 'q9' 'foi sem querer querendo' 'odnereuq rereuq mes iof'
avaliar 'q9' 'favor resolver as pendencias nos profiles' 'seliforp son saicnednep sa revloser rovaf'

avaliar 'q10' 'Ando devagar porque ja tive pressa' 'A: 1\na: 4\nd: 2\ne: 4\ng: 1\ni: 1\nj: 1\nn: 1\no: 2\np: 2\nq: 1\nr: 3\ns: 2\nt: 1\nu: 1\nv: 2\n'
avaliar 'q10' 'Sentou para descansar como se fosse sabado' 'S: 1\na: 6\nb: 1\nc: 2\nd: 2\ne: 4\nf: 1\nm: 1\nn: 2\no: 5\np: 1\nr: 2\ns: 6\nt: 1\nu: 1\n'
avaliar 'q10' 'Cuide bem do seu amor seja quem for' 'C: 1\na: 2\nb: 1\nd: 2\ne: 5\nf: 1\ni: 1\nj: 1\nm: 3\no: 3\nq: 1\nr: 2\ns: 2\nu: 3\n'
avaliar 'q10' 'aAbBcC' 'A: 1\nB: 1\nC: 1\na: 1\nb: 1\nc: 1\n'
avaliar 'q10' 'AAAAAAAAAAAAAAAAAABBBBBBBBCCCCDD' 'A: 18\nB: 8\nC: 4\nD: 2\n'


totalQuestoes=0
notaTotal=0
echo ''
echo -e "${amarelo}              sumário $1            ${normal}"
echo '----------------------'
echo -e 'problema\tacertos / número de testes'
for i in ${!sumarioTotal[@]}; do
	if ! [ -n "${sumarioStatus[$i]}" ]; then
		echo -e $i '\t' ${sumarioAcertos[$i]} / ${sumarioTotal[$i]}
		acertos=${sumarioAcertos[$i]}
		total=${sumarioTotal[$i]}
		notaQuestao=$(echo "$acertos/$total" | bc -l)
		notaTotal=$(echo "$notaTotal+$notaQuestao" | bc -l)
	else
		echo -e $i '\t' 'Erro:' ${sumarioStatus[$i]}
	fi
	totalQuestoes=$((totalQuestoes+1))
done
echo '----------------------'
echo 'Nota: ' $(echo "2*$notaTotal/$totalQuestoes" | bc -l)

rm gabarito input output a.out

