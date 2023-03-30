
#!/bin/bash

#set -x

#pobieranie słowa z zewnętrznego API
word=$(curl -s https://random-word-api.herokuapp.com/word | tr -d '"[]')
#odkomentować żeby łatwiej było przetestować działanie programu
#echo $word

#sprawdzanie długości słowa
length=${#word}

#inicjalizacja zmiennej dla zgadywanego słowa, gdzie nieodgadnięte jeszcze litery są zastąpione znakiem '-'
guessed_word=`echo -n "$word" | sed 's/./-/g'`

#ustawienie liczby szans
chances=7
#inicializacja zmiennej dla odgadniętych już liter
guessed_letters=''

#wypisanie zgadywanego słowa, gdzie wszystkie litery są zastąpione '-', jednakże informuje to o ilości znaków
echo "Odgadywane slowo: $guessed_word"

#pętla wykonująca sie do momentu aż nasze szanse na odgadnięcie słowa nie spadną do 0 oraz słowo nie zostało właśnie odgadnięte
while [ $chances -gt 0 ] && [ $guessed_word != $word ]
do
  #pobieranie od użytkownika litery z klawiatury, jednakże należy litery podawać pojedynczo oraz nie można odgadnąć od razu hasła tylko jeśli już wiemy co to za słowo podajemy jego litery pojedynczo
  read -p "Podaj litere: " letter

  #sprawdzenie czy podana przez nas litera nie została już uprzednio sprawdzana
  if [[ $guessed_letters == *"$letter"* ]]; then
    echo "Juz podawales te litere"
  else
    #sprawdzanie czy podana przez nas litera znajduje się w słowie
    if [[ $word == *"$letter"* ]]; then
      #pętla znajdująca pozycję litery w słowie, oczywiście jeśli ta się w nim znajduje
      for (( i=0; i<$length; i++ ))
      do
        #uzyskanie litery znajdującej się na pozycji i, aby później móc sprawdzić czy jest ona taka jak wpisana przez nas litera
        char=${word:i:1}

        if [ "$letter" == "$char" ]; then
          #zastąpienie '-' podaną przez nas literą w miejscu gdzie w odgadywanym słowie się ta znajduje
          guessed_word=${guessed_word:0:i}$letter${guessed_word:i+1}
        fi
      done
    else

      #zmniejszenie szansy o 1 w przypadku błędnej litery
      chances=$((chances-1))
      if [ $chances -eq 7 ]; then
echo "
_______
|/ |
|
|
|
|
|

"
elif [ $chances -eq 6 ]; then
echo "
_______
|/ |
| O
|
|
|
|

"
elif [ $chances -eq 5 ]; then
echo "
_______
|/ |
| O
| |
|
|
|

"
elif [ $chances -eq 4 ]; then
echo "
_______
|/ |
| O
| /|
|
|
|

"
elif [ $chances -eq 3 ]; then
echo "
_______
|/ |
| O
| /|\\
|
|
|

"
elif [ $chances -eq 2 ]; then
echo "
_______
|/ |
| O
| /|\\
| /
|
|

"
elif [ $chances -eq 1 ]; then
echo "
_______
|/ |
| O
| /|\\
| / \\
|
|

"
elif [ $chances -eq 0 ]; then
echo "
_______
|/ |
| X
| /|\\
| / \\
|
|

"
fi
echo "Błędna litera, pozostało $chances szans "
    fi
  fi
  #dodanie litery do już odgadniętych
  guessed_letters=$guessed_letters$letter

  echo "Odgadywane slowo: $guessed_word"

done

#sprawdzenie czy ilość szans jest równa 0
if [ $chances -eq 0 ]; then
  #wypisanie komunikatu o przegranej z powodu braku szans lub o wygranej w przypadku odgadnięcia przez nas słowa
    echo "Przegrales! Odgadywane slowo to: $word"
else
  echo "Wygrana! Odgadłeś słowo: $word"
fi