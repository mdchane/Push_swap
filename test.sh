#!/bin/bash
echo -e '\033[0mGetting an average in a range from 0 to 49'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

echo -e '\033[0mGetting an average in a range from 0 to 99'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

echo -e '\033[0mGetting an average in a range from 0 to 149'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..149).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

echo -e '\033[0mGetting an average in a range from 0 to 199'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..199).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

echo -e '\033[0mGetting an average in a range from 0 to 399'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..399).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res


echo -e '\033[0mGetting an average in a range from 0 to 499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 999'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..999).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

echo -e '\033[0mGetting an average in a range from 0 to 1499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..1499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

cat res

rm res

