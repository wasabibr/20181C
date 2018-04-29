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

avaliar 'q7' '' 'O poeta é um fingidor\nFinge tão completamente\nQue chega a fingir que é dor\nA dor que deveras sente.\n'
avaliar 'q8' 'a' 'b'
avaliar 'q8' 't' 'u'
avaliar 'q8' 'c' 'd'
avaliar 'q8' 'x' 'y'
avaliar 'q8' 'A' 'B'
avaliar 'q8' 'T' 'U'
avaliar 'q8' 'C' 'D'
avaliar 'q8' 'X' 'Y'
avaliar 'q9' '8.1 2' 'Nota: 9.90'
avaliar 'q9' '5.3 1.3' 'Nota: 6.07'
avaliar 'q11' '15' 'Resposta: 0'
avaliar 'q11' '18' 'Resposta: 1'
avaliar 'q11' '0' 'Resposta: 0'
avaliar 'q11' '30' 'Resposta: 0'
avaliar 'q11' '4' 'Resposta: 0'
avaliar 'q11' '21' 'Resposta: 1'
avaliar 'q11' '3' 'Resposta: 1'
avaliar 'q12' '0 0 0' '0'
avaliar 'q12' '23 59 59' '86399'
avaliar 'q12' '15 12 30' '54750'
avaliar 'q12' '18 5 32' '65132'
avaliar 'q13' '1 2 3' '3.435002'
avaliar 'q13' '-2 2 5' '5.400000'
avaliar 'q14' '30 28 2' 'Resposta: 1'
avaliar 'q14' '20 35 15' 'Resposta: 1'
avaliar 'q14' '25 45 70' 'Resposta: 1'
avaliar 'q14' '4 2 2' 'Resposta: 1'
avaliar 'q14' '0 0 0' 'Resposta: 1'
avaliar 'q14' '31 28 2' 'Resposta: 0'
avaliar 'q14' '20 36 15' 'Resposta: 0'
avaliar 'q14' '25 45 71' 'Resposta: 0'

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

