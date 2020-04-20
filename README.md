# DES-algorithm

Data Encryption Standard  -
Triple DES –
Otelea Alina- Alexandra



I – Scurta descriere 

Originile sale sunt in anii 1970. Acesta a fost format dupa concluziile unui studiu asupra nevoilor de securitate pentru calculatoare a guvernului Statelor Unite si s-a cautat un standard pentru a fi folosit in toate statele.
Dupa 15 mai 1973, dupa consultarea cu NSA, NBS (National Boureau of Standards ) a solicitat propuneri pentru un cifru conform criteriilor de design riguroase, nu s-a gasit o solutie de aceasta data, abia la un an dupa, mai exact pe 27 august 1974 IBM a inscris un candidat, mai exact un cifru  dezvoltat în perioada 1973–1974, bazat pe un algoritm existent, cifrul Lucifer al lui Horst Feistel.
Acest standard nu mai este folosit fiind inlocuit de AES, este considerat nesigur din pricina cheii prea mici de 52 de biti, fiind din aceasta cauza si un algoritm controversat considerandu-se o portita pentru NSA.
Se crede ca algoritmul este practic sigur în forma Triplu DES, desi exista atacuri teoretice si asupra acestuia.
Triplu DES este pur si simplu DES aplicat de trei ori, folosindu-se de doua chei intr-o ordine particulara. Prima cheie este folosita pentru a cifra mesajul conform DES, a doua cheie este folosita pentru a descripta mesajul criptat, din moment ce a doua cheie nu este cea buna, aceasta descriptare va amesteca mesajul. Amestecat de doua ori mesajul este din nou criptat cu prima cheie. Aceste trei etape sunt denumite Triplu Des.






II – Descrierea detaliata a algoritmului DES

DES opereaza pe blocuri de 64 de biti si returneaza blouri de aceeasi dimensiune.
Are 2^64 posibile aranjari si fiecare bloc este inpartit inn 32 de biti fiecare in stanga(notat cu L) si dreapta(notat cu D).
Consideram Mesajul M = 0123456789ABCDEF ( in hexazecimal )
Incepem prin a-l transforma in binar adica :
M = 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
Il vom impartii in doi vectori a cate 8 blocuri cu 4 biti fiecare, adica din cei 64 de biti totali fiacre va contine 32 de biti.
L =  0000 0001 0010 0011 0100 0101 0110 0111
R = 1000 1001 1010 1011 1100 1101 1110 1111
Cheia are efectiv 54 de biti, dar este stocata ca avand 64 biti(la fel ca si mesajul) , insa la fiecare bloc de 8 biti, ultimul bit nu este folosit ( vom afla mai tarziu si explicatia).
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
Se va elimina bitul cu nr : 8, 16, 24, 32 , 40 , 48 , 56 si 64 atunci cand vom creea subcheile.
Vom considera cheia K = 133457799BBCDFF1
O transformam in binar si obtinem :
K = 00010011 00110100 01010111 01111001 10011011 10111100 11011111 11110001

PASUL 1
In acest pas vom creea 16 subchei fiecare cu o lungime de 48 de biti.
Cheia de 64 de biti este permutata conform tabelului standard PC-1, dupa formarea acestui tabel vor mai ramane 54 de biti.
Practic vom muta indexul din cheia K conform tabelului PC-1.
Cheia K ( pe primul rand vom numerota indecsii cheii iar pe al doilea vor fi trecute valorile in binar calculate anterior )
K
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
0	0	0	1	0	0	1	1	0	0	1	1	0	1	0	0
17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32
0	1	0	1	0	1	1	1	0	1	1	1	1	0	0	1
33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48
1	0	0	1	1	0	1	1	1	0	1	1	1	1	0	0
49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64
1	1	0	1	1	1	1	1	1	1	1	1	0	0	0	1

Tabelul PC-1 -  in acest tabel practic vom transpune numerele din tabelul de sus, corespunzatoare cheii K, conform numarului hexazecimal atasat deasupra lui.
Mai exact indexului 57 din tabelul de mai sus ii corespunde nr in binar 1 ( de pe randul al doilea in dreptul lui ), acesta va deveni primul numar al lui pc-1, pentru ca reamintesc ca in acest tabel de vor face permutari si acest tabel este standard.
                             PC-1

              57   49    41   33    25    17    9
               1   58    50   42    34    26   18
              10    2    59   51    43    35   27
              19   11     3   60    52    44   36
              63   55    47   39    31    23   15
               7   62    54   46    38    30   22
              14    6    61   53    45    37   29
              21   13     5   28    20    12    4

57
1	49
1	41
1	33
1	25
0	17
0	9
0
1
0	58
1	50
1	42
0	34
0	26
1	18
1
10
0	2
0	59
1	51
0	43
1	35
0	27
1
19
0	11
1	3
0	60
1	52
1	44
1	36
1
63
0	55
1	47
0	39
1	31
0	23
1	15
0
7
1	62
0	54
1	46
1	38
0	30
0	22
1
14
1	6
0	61
0	53
1	45
1	37
1	29
1
21
0	13
0	5
0	28
1	20
1	12
1	4
1

Cee ace va rezulta din tabelul PC-1 vom nota cu K+.
K+ = 1111000 0110011 0010101 0101111 0101010 1011001 1001111 0001111
Dupa aceasta etapa cheia K+ va fi la randul ei impartita in doua parti egale.
C0 = 1111000 0110011 0010101 0101111  -28 biti
D0 = 0101010 1011001 1001111 0001111  -28 biti
Cu acesti vectori initiali putem creea 16 blocuri. Fiecare bloc va fi creeat din blocul precedent, se vor muta biti catre stanga conform unui alt tabel. Rolul acestor blocuri si siftari este ca mai tarziu se vor creea subchei corespunzaroare fiecarui bloc conform tabelului PC-2.

Indexul iteratiei	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
Nr de siftari catre stanga	1	1	2	2	2	2	2	2	1	2	2	2	2	2	2	1

Si vor rezulta urmatoarele blocuri :
C0 = 1111000011001100101010101111
D0 = 0101010101100110011110001111   -28 de biti C0  + 28 de biti D0 = 56 de biti
C1 = 1110000110011001010101011111
D1 = 1010101011001100111100011110
C2 = 1100001100110010101010111111
D2 = 0101010110011001111000111101
C3 = 0000110011001010101011111111
D3 = 0101011001100111100011110101
C4 = 0011001100101010101111111100
D4 = 0101100110011110001111010101
C5 = 1100110010101010111111110000
D5 = 0110011001111000111101010101
C6 = 0011001010101011111111000011
D6 = 1001100111100011110101010101
C7 = 1100101010101111111100001100
D7 = 0110011110001111010101010110
C8 = 0010101010111111110000110011
D8 = 1001111000111101010101011001
C9 = 0101010101111111100001100110
D9 = 0011110001111010101010110011
C10 = 0101010111111110000110011001
D10 = 1111000111101010101011001100
C11 = 0101011111111000011001100101
D11 = 1100011110101010101100110011
C12 = 0101111111100001100110010101
D12 = 0001111010101010110011001111
C13 = 0111111110000110011001010101
D13 = 0111101010101011001100111100
C14 = 1111111000011001100101010101
D14 = 1110101010101100110011110001
C15 = 1111100001100110010101010111
D15 = 1010101010110011001111000111
C16 = 1111000011001100101010101111
D16 = 0101010101100110011110001111
Din nou si de aceasta data se va elimina ultimul bit, mai exact din 7 in 7.
Fiecarui bloc in parte I se va asocia cate o cheie conform tabelului PC-2:
			     PC-2

                 14    17   11    24     1    5
                  3    28   15     6    21   10
                 23    19   12     4    26    8
                 16     7   27    20    13    2
                 41    52   31    37    47   55
                 30    40   51    45    33   48
                 44    49   39    56    34   53
                 46    42   50    36    29   32


Ne vom uita la indecsii Cn, Dn  si ii vom premuta conform tabelului de mai sus. Dupa formarea fiecarei subchei conform tabelului, din 54 de biti vor mai ramane 48.





C1, D1
1	2	3	4	5	6	7	8	9	10	11	12	13	14
1	1	1	0	0	0	0	1	1	0	0	1	1	0
15	16	17	18	19	20	21	22	23	24	25	26	27	28
0	1	0	1	0	1	0	1	0	1	1	1	1	1
29	30	31	32	33	34	35	36	37	38	39	40	41	42
1	0	1	0	1	0	1	0	1	1	0	0	1	1
43	44	45	46	47	48	49	50	51	52	53	54	55	56
0	0	1	1	1	1	0	0	0	1	1	1	1	0

PC-2
14
0	17
0	11
0	24
1	1
1	5
0
3
1	28
1	15
0	6
0	21
0	10
0
23
0	19
0	12
1	4
0	26
1	8
1
16
1	7
0	27
1	20
1	13
1	2
1
41
1	52
1	31
1	37
1	47
1	55
1
30
0	40
0	51
0	45
1	33
1	48
1
44
0	49
0	39
0	56
0	34
0	53
1
46
1	42
1	50
0	36
0	29
1	32
0

De aici va rezulta prima subcheie :
K1 =  000110 110000 001011 101111 111111 000111 000001 110010
Repetam acest pas pentru toate cele 16 blocuri.
K2 = 011110 011010 111011 011001 110110 111100 100111 100101
K3 = 010101 011111 110010 001010 010000 101100 111110 011001
K4 = 011100 101010 110111 010110 110110 110011 010100 011101
K5 = 011111 001110 110000 000111 111010 110101 001110 101000
K6 = 011000 111010 010100 111110 010100 000111 101100 101111
K7 = 111011 001000 010010 110111 111101 100001 100010 111100
K8 = 111101 111000 101000 111010 110000 010011 101111 111011
K9 = 111000 001101 101111 101011 111011 011110 011110 000001
K10 = 101100 011111 001101 000111 101110 100100 011001 001111
K11 = 001000 010101 111111 010011 110111 101101 001110 000110
K12 = 011101 010111 000111 110101 100101 000110 011111 101001
K13 = 100101 111100 010111 010001 111110 101011 101001 000001
K14 = 010111 110100 001110 110111 111100 101110 011100 111010
K15 = 101111 111001 000110 001101 001111 010011 111100 001010
K16 = 110010 110011 110110 001011 000011 100001 011111 110101

PASUL 2
In acest pas vom coda fiecare bloc de 64 de biti a mesajului. 
Exista o permutare initiala notata IP conform tabelului:
		              IP

            58    50   42    34    26   18    10    2
            60    52   44    36    28   20    12    4
            62    54   46    38    30   22    14    6
            64    56   48    40    32   24    16    8
            57    49   41    33    25   17     9    1
            59    51   43    35    27   19    11    3
            61    53   45    37    29   21    13    5
            63    55   47    39    31   23    15    7

II vom creea si acestuia un tabel si pentru mesajul M pentru a ne fi mai usor de urmarit.
M = 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111 ->

M
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
0	0	0	0	0	0	0	1	0	0	1	0	0	0	1	1
17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32
0	1	0	0	0	1	0	1	0	1	1	0	0	1	1	1
33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48
1	0	0	0	1	0	0	1	1	0	1	0	1	0	1	1
49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64
1	1	0	0	1	1	0	1	1	1	1	0	1	1	1	1





IP
58
1	50
1	42
0	34
0	26
1	18
1	10
0	2
0
60
0	52
0	44
0	36
0	28
0	20
0	12
0	4
0
62
1	54
1	46
0	38
0	30
1	22
1	14
0	6
0
64
1	56
1	48
1	40
1	32
1	25
1	16
1	8
1
57
1	49
1	41
1	33
1	25
0	17
0	9
0	1
0
59
1	51
0	43
1	35
0	27
1	19
0	11
1	3
0
61
1	53
1	45
1	37
1	29
0	21
0	13
0	5
0
63
1	55
0	17
1	39
0	31
1	23
0	15
1	7
0

IP = 1100 1100 0000 0000 1100 1100 1111 1111 . 1111 0000 1010 1010 1111 0000 1010 1010
Si pe acesta in vom imparti in doua parti egale si anume:
L0 = 1100 1100 0000 0000 1100 1100 1111 1111      -> 32 de biti
R0 = 1111 0000 1010 1010 1111 0000 1010 1010     -> 32 de biti
Acum vom trece prin cele 16 iteratii folosid o functie f care opereaza cu doua blocuri
( un bloc de 32 de biti si cheia calculata anterior pentru a produce blocuri de 32 de biti) .
Formula este :
Ln = Rn-1 
Rn = Ln-1 + f(Rn-1,Kn)
Adica cu fiecare iteratie vom lua cei 32 de biti din partea dreapta (Rn) a rezultatului anterior si ii vom transfera in partea stanga a rezultatului current. Pentru a calcula cei 32 de biti din partea dreapta a rezultatului current vom face XOR din bitii din partea stanga a rezultatului anterior plus o functie f.
K1 = 000110 110000 001011 101111 111111 000111 000001 110010 
L1 = R0 = 1111 0000 1010 1010 1111 0000 1010 1010 
R1 = L0 + f(R0,K1)

Pentru a calcula aceasta functie f (f(Rn-1+Kn)), trebuie mai intai sa expandam vectorul Rn-1 din cei 32 de biti in 48.
Acest lucru il vom face printr-un tabel, in care se vor repeat anumiti biti aflati in Rn-1
Acest tabel il vom denumi E si va avea 32 de biti la input si 48 de biti la output.

			      E

                 32     1    2     3     4    5
                  4     5    6     7     8    9
                  8     9   10    11    12   13
                 12    13   14    15    16   17
                 16    17   18    19    20   21
                 20    21   22    23    24   25
                 24    25   26    27    28   29
                 28    29   30    31    32    1

R0 = 1111 0000 1010 1010 1111 0000 1010 1010     

E
32
0	1
1	2
1	3
1	4
1	5
0
4
1	5
0	6
0	7
0	8
0	9
1
8
0	9
1	10
0	11
1	12
0	13
1
12
0	13
1	14
0	15
1	16
0	17
1
16
0	17
1	18
1	19
1	20
1	21
0
20
1	21
0	22
0	23
0	24
0	25
0
24
0	25
1	26
0	27
1	28
0	29
1
28
0	29
1	30
0	31
1	32
0	1
1

E(R0) = 011110 100001 010101 010101 011110 100001 010101 010101

! Observam cum la fiecare bloc din cele 8, s-a expandat din 4 in 6 biti fiecare.

In urmatorul pas vom calcula XOR de E(Rn-1) si cheia Kn.
K1            = 000110 110000 001011 101111 111111 000111 000001 110010 
E(R0)       = 011110 100001 010101 010101 011110 100001 010101 010101 
K1+E(R0) = 011000 010001 011110 111010 100001 100110 010100 100111
Dupa acesti pasi vom calcula aceste 8 grupuri noi rezultate ca fiind adrese in blocurile S.
Pentru a determina locatia acelei adrese vom calcula un nr format din 4 biti ce va inlocuii cei 6 biti originali. Urmatorul rezultat va fi ca cele 8 grupuri a cate 6 biti var fi transformati in 8 grupuri a cate 4 biti, pentru a forma 48 de biti.
Acesti 48 de biti vor fi de forma: 
Kn + E(Rn-1) = B1 B2 B3 B4 B5 B6 B7 B8
Bi este un grup format din 6 biti si vom calcula :
S1(B1)  S2(B2)  S3(B3)  S4(B4)  S5(B5)  S6(B6)  S7(B7)  S8(B8)
Unde Si(Bi) se refera la output-ul cu indicele i din blocul Si
Mai exact fiecare bloc S1 …S8 va avea un tabel standard cu valori si vom calcula in functie de B indicele de output.
Vom lua ca exemplu prima data S1


                             S1

	0  1   2  3   4  5   6  7   8  9  10 11  12 13  14 15

  0   14  4  13  1   2 15  11  8   3 10   6 12   5  9   0  7
  1    0 15   7  4  14  2  13  1  10  6  12 11   9  5   3  8
  2    4  1  14  8  13  6   2 11  15 12   9  7   3 10   5  0
  3   15 12   8  2   4  9   1  7   5 11   3 14  10  0   6 13

Reamintim faptul ca Bi este cate un bloc luat din Kn + E(Rn-1).
La fiecare acest bloc vom considera primul si ultimul bit un numar, calculandu-l in baza doi el poate fi in intervalul 0-3 (adica 00,01,11) – pe acesta il notam cu i .
Ne mai raman 4 biti in mijloc, calculandu-I sip e acestia in baza doi va fi un numar intre 0 – 15 ( adica intre 0000 ….1111 ) – pe acesta il vom nota cu j.
Deci pentru primul grup adica B1 din K1+E(R0) -> B1 = 0 1100 0
i	j	i
0	1	1	0	0	0
i=0 ; j = 1100 = 12
Indicele i indica randul tabelului iar j indica coloana tabelului. In cazul nostru randul este 0, iar coloana este 12, deci output-ul va fi 5. Acesta transformat in binar este 0101 , deci 
S1(011000) = 0101
Deci pentru urmatorul ar fi:
S2(B2) = 010001 ; I = 01 = 1, j = 1000 = 8
Randul 1 coloana 8 din S2-> 
                           S2
      0  1   2  3   4  5   6  7   8  9  10 11  12 13  14 15

0    15  1   8 14   6 11   3  4   9  7   2 13  12  0   5 10
1     3 13   4  7  15  2   8 14  12  0   1 10   6  9  11  5
2     0 14   7 11  10  4  13  1   5  8  12  6   9  3   2 15
3    13  8  10  1   3 15   4  2  11  6   7 12   0  5  14  9

12 = 1100 => S2(010001) = 1100
Vom continua aceste calcule pana la S8. Conform tabelelelor standard :
                             S1

     14  4  13  1   2 15  11  8   3 10   6 12   5  9   0  7
      0 15   7  4  14  2  13  1  10  6  12 11   9  5   3  8
      4  1  14  8  13  6   2 11  15 12   9  7   3 10   5  0
     15 12   8  2   4  9   1  7   5 11   3 14  10  0   6 13

                             S2

     15  1   8 14   6 11   3  4   9  7   2 13  12  0   5 10
      3 13   4  7  15  2   8 14  12  0   1 10   6  9  11  5
      0 14   7 11  10  4  13  1   5  8  12  6   9  3   2 15
     13  8  10  1   3 15   4  2  11  6   7 12   0  5  14  9

                             S3

     10  0   9 14   6  3  15  5   1 13  12  7  11  4   2  8
     13  7   0  9   3  4   6 10   2  8   5 14  12 11  15  1
     13  6   4  9   8 15   3  0  11  1   2 12   5 10  14  7
      1 10  13  0   6  9   8  7   4 15  14  3  11  5   2 12

                             S4

      7 13  14  3   0  6   9 10   1  2   8  5  11 12   4 15
     13  8  11  5   6 15   0  3   4  7   2 12   1 10  14  9
     10  6   9  0  12 11   7 13  15  1   3 14   5  2   8  4
      3 15   0  6  10  1  13  8   9  4   5 11  12  7   2 14

                             S5

      2 12   4  1   7 10  11  6   8  5   3 15  13  0  14  9
     14 11   2 12   4  7  13  1   5  0  15 10   3  9   8  6
      4  2   1 11  10 13   7  8  15  9  12  5   6  3   0 14
     11  8  12  7   1 14   2 13   6 15   0  9  10  4   5  3

                             S6

     12  1  10 15   9  2   6  8   0 13   3  4  14  7   5 11
     10 15   4  2   7 12   9  5   6  1  13 14   0 11   3  8
      9 14  15  5   2  8  12  3   7  0   4 10   1 13  11  6
      4  3   2 12   9  5  15 10  11 14   1  7   6  0   8 13

                             S7

      4 11   2 14  15  0   8 13   3 12   9  7   5 10   6  1
     13  0  11  7   4  9   1 10  14  3   5 12   2 15   8  6
      1  4  11 13  12  3   7 14  10 15   6  8   0  5   9  2
      6 11  13  8   1  4  10  7   9  5   0 15  14  2   3 12

                             S8

     13  2   8  4   6 15  11  1  10  9   3 14   5  0  12  7
      1 15  13  8  10  3   7  4  12  5   6 11   0 14   9  2
      7 11   4  1   9 12  14  2   0  6  10 13  15  3   5  8
      2  1  14  7   4 10   8 13  15 12   9  0   3  5   6 11

Deci pentru prima iteratie vom obtine:
S1(B1)  S2(B2)  S3(B3)  S4(B4)  S5(B5)  S6(B6)  S7(B7)  S8(B8) =  0101 1100 1000 0010 1011 0101 1001 0111
Pasul final al lui f consta intr-o permutare a blocurilor S.
Vom forma un bloc de 32 de biti conform tabelului P.
				P

                         16   7  20  21
                         29  12  28  17
                          1  15  23  26
                          5  18  31  10
                          2   8  24  14
                         32  27   3   9
                         19  13  30   6
                         22  11   4  25

Ca mai devreme pentru o intelegere mai facila vom forma un tabel unde pe primul rand vom trece numarul indicelui iar sub el va fi trecuta valoarea corespunzatoare in binar.
	
	S1(B1)  S2(B2)  S3(B3)  S4(B4)  S5(B5)  S6(B6)  S7(B7)  S8(B8)

1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
0	1	0	1	1	1	0	0	1	0	0	0	0	0	1	0
17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32
1	0	1	1	0	1	0	1	1	0	0	1	0	1	1	1
P
16
0	7
0	20
1	21
0
29
0	12
0	28
1	17
1
1
0	15
1	23
0	26
0
5
1	18
0	31
1	10
0
2
1	8
0	24
1	14
0
32
1	27
0	3
0	9
1
19
1	13
0	30
1	6
1
22
1	11
0	4
1	25
1

 F1 = 0010 0011 0100 1010 1010 1001 1011 1011
Reamintesc ca L0 = 1100 1100 0000 0000 1100 1100 1111 1111 si R0 = 1111 0000 1010 1010 1111 0000 1010 1010 , iar cum partea stanga curenta este creeata din partea dreapta anterioara avem:
L1 = R0 = 1111 0000 1010 1010 1111 0000 1010 1010 
si R1 = L0 + f(R0,K1)
Deci = 1100 1100 0000 0000 1100 1100 1111 1111 
         + 0010 0011 0100 1010 1010 1001 1011 1011 
         = 1110 1111 0100 1010 0110 0101 0100 0100
Vom continua algoritmul in acelasi mod, mai exact R1 devine L2, adica ceea ce am calculate anterior vom trece in partea stanga si mai ramane sa calculam partea dreapta prin aceleasi blocuri R2 =L1 + f(R1, K2).
Exceptie la acest lucru o va face a-16-ea iteratie.La aceasta iteratie vom inversa blocurilor L16 si R16, astfel incat sa devina R16 L16 .
L16 = 0100 0011 0100 0010 0011 0010 0011 0100 
R16 = 0000 1010 0100 1100 1101 1001 1001 0101
R16L16 = 00001010 01001100 11011001 10010101 01000011 01000010 00110010 00110100
Apoi fiecare indice a acesti noi vector va fi permutat conform tabelului IP-1



                               IP-1

            40     8   48    16    56   24    64   32
            39     7   47    15    55   23    63   31
            38     6   46    14    54   22    62   30
            37     5   45    13    53   21    61   29
            36     4   44    12    52   20    60   28
            35     3   43    11    51   19    59   27
            34     2   42    10    50   18    58   26
            33     1   41     9    49   17    57   25


R16L16
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
0	0	0	0	1	0	1	0 	0	1	0	0	1	1	0	0
17	18	19	20	21	22	23	24	25	26	27	28	29	30	31	32
1	1	0 	1	1	0	0	1	1	0	0	1	0	1	0	1
33	34	35	36	37	38	39	40	41	42	43	44	45	46	47	48
0	1	0	0	0	0	1	1	0	1	0	0	0	0	1	0
49	50	51	52	53	54	55	56	57	58	59	60	61	62	63	64
0	0	1	1	0	0	1	0	0	0	1	1	0	1	0	0


IP-1
40
1	8
0	18
0	16
0	56
0	24
1	64
0	32
1
39
1	7
1	47
1	15
0	55
1	23
0	63
0	31
0
38
0	6
0	46
0	14
1	54
0	22
0	62
1	30
1
37
0	5
1	45
0	13
1	53
0	21
1	61
0	29
0
36
0	4
0	44
0	12
0	52
1	20
1	60
1	28
1
35
0	3
0	43
0	11
0	51
1	19
0	59
1	27
0
34
1	2
0	42
1	10
1	50
0	18
1	58
0	26
0
33
0	1
0	41
0	9
0	49 
0	17
1	57
0	25
1

IP-1 = 10000101 11101000 00010011 01010100 00001111 00001010 10110100 00000101
Care in hexazecimal este : 85E813540F0AB405
Deci aceasta este criptarea lui M = 0123456789ABCDEF, notate cu C = 85E813540F0AB405
III – Rezumatul algoritmului
Recapituland aflam ca acest algoritm are un numar insemnat de pasi.
Dupa ce am transformat in binar mesajul si cheia aferenta am creeat la pasul 1 pe rand 16 subchei pornind initial de la cheie. Am facut permutari conform tabelului PC-1.
Ceea ce a rezultat a fost impartit in doi vectori egali C0 si D0. Acestia au ajutat pentru a forma mai departe 16 blocuri conform unui numar de siftari spre stanga. 
Toate aceste 16 blocuri au avut o cheie aferenta creeata cu ajutorul tabelului PC-2.
In pasul doi ne-am concentrat pe mesaj. L-am permutat conform tabelului IP, iar rezultatul a fost impartit in doi vectori egali respective L0 si R0, acestia fiind vectorii initiali. Am continuat sa calculez Ln si Rn, n  [1,16], dupa urmatorul principu: noua parte din stanga a pasului curent va fi egala cu partea din dreapta a pasului anterior, practice ne va ramane sa calculam partea din dreapta. Aceasta se realizeaza prin calulul XOR a partii din stanga a pasului anterior si calculul unei functii f. 
Ln = Rn-1
Rn = Ln-1 + f(Rn-1,Kn)
Aceasta formula f va fi calculata in felul urmator:
Prima data vom face XOR din cheia aferenta pasului curent(k1…k16) cu partea expandata din dreapta a pasului anterior E(Rn-1). Partea dreapta expandata inseamna ca vom expanda din cei 32 de biti a lui Rn-1 in 48 de biti conform tabelului E.
Din ceea ce va rezulta in urma XOR-ului se va impartii in 8 blocuri a cate 6 biti fiecare si se va calcula output-ul conform blocurilor S. (Acest bloc contine numere zecimale impartit pe linii si coloane, fiecare din cele 8 blocuri va rezulta un rand si o coloana si se va alege numarul aferent acestora – apoi acest numar zecimal este iar calculat in binar)
Deci vor exista 16 iteratii fiecare calculand S1(B1)  S2(B2)  S3(B3)  S4(B4)  S5(B5)  S6(B6)  S7(B7)  S8(B8).
Pasul final al functiei f este o permutare conform tabelului P.
Astfel vom calcula XOR din Ln-1 si functia calculate f.
Facem acesti pasi pentru a ajunge recursiv la L16 si R16, unde ca pasi finali le vom inversa ordinea si ii vom permute conform tabelului IP-1. Rezultatul final se va transforma in hexazecimal si acesta este textul final criptat.
