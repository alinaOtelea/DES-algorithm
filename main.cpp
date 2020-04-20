#include<bits/stdc++.h>
#include <stdlib.h>
#include <bitset>

using namespace std;
//cheia : 133457799BBCDFF1
//C = 85E813540F0AB405
string hex2bin(string p)
{
    string ap="";
    int l=p.length();
    for(int i=0;i<l;i++)
    {
        string st="";
        if(p[i]>='0'&&p[i]<='9')
        {
            int te=int(p[i])-48;
            while(te>0)
            {
                st+=char(te%2+48);
                te/=2;
            }
            while(st.length()!=4)
                st+='0';
            for(int j=3;j>=0;j--)
                ap+=st[j];
        }
        else
        {
            int te=p[i]-'A'+10;
            while(te>0)
            {
                st+=char(te%2+48);
                te/=2;
            }
            for(int j=3;j>=0;j--)
                ap+=st[j];
        }
    }
    return ap;
}

string binar (int n){
    string soutt = "",sout= "";
    while(n>0){
        soutt = soutt + char(n%2+48);
        n = n/2;
    }
    while(soutt.length()!=4)
        {
             soutt+='0';
        }

        for(int j=soutt.length()-1;j>=0;j--)
        {
            sout+=soutt[j];
        }
    return sout;
}

void criptare(string text_input,string cheieTastatura){
int key[64],i,j;
string cheieBinar;


    //mesajul in binar
    text_input = hex2bin(text_input);

    //cheieTastatura = cheia de la input
    cheieBinar = hex2bin(cheieTastatura);
    for(int i=0; i<64; i++){
        key[i]=cheieBinar[i]-'0';
    }

    /*
        PASUL I - GENERAREA CELOR 16 SUBCHEI
    */

    //tabelul PC-1
    int pc1[56]={
      57  , 49   , 41   ,33 ,   25   , 17 ,   9,
       1 ,  58    ,50  , 42 ,   34  ,  26  , 18,
      10  ,  2    ,59  , 51 ,   43  ,  35  , 27,
      19  , 11   ,  3  , 60  ,  52  ,  44  , 36,
      63  , 55  ,  47  , 39  ,  31   , 23  , 15,
       7  , 62   , 54  , 46  ,  38  ,  30  , 22,
      14  ,  6   , 61  , 53  ,  45   , 37  , 29,
      21  , 13  ,   5  , 28   , 20  ,  12  ,  4
    };
    //Tabelul PC-2
    int pc2[48]={
    14,    17,   11,    24,     1,    5,
    3   , 28 ,  15    , 6  ,  21  , 10 ,
    23    ,19  , 12   ,  4 ,  26  ,  8,
    16     ,7  , 27  ,  20  ,  13  ,  2,
    41   , 52 ,  31  ,  37  ,  47  , 55,
    30   , 40  , 51  ,  45  ,  33 , 48,
    44    ,49 ,  39  ,  56  ,  34 ,  53,
    46    ,42 ,  50  ,  36 ,   29 ,  32};

    int k[16][48],c[28],d[28],nshift,temp1,temp2,pkey[56];
    /*
    pkey este cheia initiala dupa permutarea cu tabelul PC-1
    de unde va rezulta Cn si Dn
    */

    //memoram cheia nou formata in vectorul pkey
    for(i=0;i<56;i++){
        //generarea cheii K+
        pkey[i]=key[pc1[i]-1]; // pentru ca incepe de la 0
        //cout<<pkey[i];
    }
    //calculam c0
    for(i=0;i<28;i++){
        c[i]=pkey[i];
        //cout<<c[i]<<" ";
    }
    //calculam d0
    for(i=0;i<28;i++){
        d[i]=pkey[i+28];
       // cout<<d[i]<<" ";
    }

    //calculam cele 16 iteratii conform tabelului de shiftari
    for(i=0;i<16;i++)
    {
        if(i==0||i==1||i==8||i==15)
            nshift=1;
        else
            nshift=2;
        while(nshift--)
        {

            temp1 = c[0];
            temp2 = d[0];
            for(j=0;j<27;j++)
            {
                c[j]=c[j+1];
                d[j]=d[j+1];
            }
            c[27]=temp1;
            d[27]=temp2;

        }

        //k[i][j] = cele 16 subchei
        for(j=0;j<48;j++)
        {
            k[i][j]=c[pc2[j]-1];
            //cout<<k[i][j];
        }
        //cout<<endl;

    }

    /*
        PASUL II - MESAJUL
    */
     int ip[64] = {58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
    };

     int e[48] = {
        32,1,2,3,4,5,
        4,5,6,7,8,9,
        8,9,10,11,12,13,
        12,13,14,15,16,17,
        16,17,18,19,20,21,
        20,21,22,23,24,25,
        24,25,26,27,28,29,
        28,29,30,31,32,1
    };

    //blocurile S
    int s[8][4][16]=
    {{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },


    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};

    //tabelul p pentru permutarea functiei f
    int p[32]={
        16 ,  7 , 20  ,21,
        29 , 12 , 28 , 17,
        1 , 15,  23,  26,
        5 , 18 , 31  ,10,
        2  , 8 , 24 , 14,
        32  ,27,   3 ,  9,
        19  ,13,  30,   6,
        22 , 11  , 4 , 25
    };

    char mesaj[64];
    int row,col;
    int left[16][32], right[16][32];

    for(i=0;i<64;i++){
        //din char in int
        mesaj[i] = int(text_input[ip[i]-1]) - 48;
        //cout<<mesaj[i]<<" ";
    }
   // cout<<endl;

/*
rightE =  partea dreapta expandata conform tabelului E
xorul = xor intre cheia K si expandare
tempBin = transformarea in binar a nr zecimal temp
sout = tot string-ul pentru fiecare 16 linii a blocurilor S1..S8
fp= functia f dupa permutarea cu tabelul P

*/

int er[48],rightE[16][48],xorul[48],runda,f[48],temp;
string sout ="",tempBin="";
char fp[32];

/*for (i=0; i<48; i++) {
    rightE[0][i] = right[e[i]-1];
    xorul[i] = rightE[0][i] ^ k[0][i];
    //cout<<xorul[i];
}*/
for(i=0;i<32;i++){
    left[0][i]=mesaj[i];
    right[0][i]=mesaj[i+32];
    //cout<<left[i];
}
//cout<<endl;

for(runda=0; runda<16 ; runda ++){

    for(i=0; i<48; i++)
    {
        rightE[runda][i] = right[runda][e[i]-1];
        xorul[i] = rightE[runda][i] ^ k[runda][i];
        //cout<<xorul[i];
    }

     for(i=0 ; i<48 ; i+=6)
    {
        row=xorul[i+5]+xorul[i]*2;
        col=xorul[i+1]*8+xorul[i+2]*4+xorul[i+3]*2+xorul[i+4];
        temp=s[i/6][row][col];
        //cout<<temp;
        tempBin = binar(temp);
        sout = sout + tempBin;

    }
    for(i=0;i<32;i++){
        fp[i] = sout[p[i]-1];
        //cout<<fp[i];
    }

    for(i=0;i<32;i++){
        left[runda+1][i] = right[runda][i];
        right[runda+1][i] = left[runda][i] ^ (int(fp[i])-48);
      //cout<<right[runda+1][i];
    }
    //cout<<endl;
    sout = "";
}

int ipUltim[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};
int rl[64] , solutie[64] ;
string solutieHexa = "";
//vom inversa dreapta cu stanga
for(i=0;i<32;i++){
      //cout<<left[16][i];
      rl[i] = right[16][i];
      rl[i+32] = left[16][i];
}

for(i=0;i<64;i++){
      solutie[i] = rl[ipUltim[i] - 1];
      //solutieHexa = solutieHexa + solutie[i];
}
cout << "Solutia in binar este : ";
for(i=0;i<64;i++){
      cout<<solutie[i];
}
cout<<endl;
//cout<<solutieHexa;
for(i=0;i<64;i+=4)
{
    temp = solutie[i]*8+solutie[i+1]*4+solutie[i+2]*2+solutie[i+3];
    if(temp<10){
        solutieHexa = solutieHexa + char(temp+48);
    }
    else{
        solutieHexa = solutieHexa + char(temp+55);
    }
}
cout<<"Solutia C : "<<solutieHexa<<endl;
}

void decriptare(string text_input,string cheieTastatura){
int key[64],i,j;
string cheieBinar;


    //mesajul in binar
    text_input = hex2bin(text_input);
    //cout<<text_input<<endl;

    //cheieTastatura = cheia de la input
    cheieBinar = hex2bin(cheieTastatura);
    for(int i=0; i<64; i++){
        key[i]=cheieBinar[i]-'0';
    }

    /*
        PASUL I - GENERAREA CELOR 16 SUBCHEI
    */

    //tabelul PC-1
    int pc1[56]={
      57  , 49   , 41   ,33 ,   25   , 17 ,   9,
       1 ,  58    ,50  , 42 ,   34  ,  26  , 18,
      10  ,  2    ,59  , 51 ,   43  ,  35  , 27,
      19  , 11   ,  3  , 60  ,  52  ,  44  , 36,
      63  , 55  ,  47  , 39  ,  31   , 23  , 15,
       7  , 62   , 54  , 46  ,  38  ,  30  , 22,
      14  ,  6   , 61  , 53  ,  45   , 37  , 29,
      21  , 13  ,   5  , 28   , 20  ,  12  ,  4
    };
    //Tabelul PC-2
    int pc2[48]={
    14,    17,   11,    24,     1,    5,
    3   , 28 ,  15    , 6  ,  21  , 10 ,
    23    ,19  , 12   ,  4 ,  26  ,  8,
    16     ,7  , 27  ,  20  ,  13  ,  2,
    41   , 52 ,  31  ,  37  ,  47  , 55,
    30   , 40  , 51  ,  45  ,  33 , 48,
    44    ,49 ,  39  ,  56  ,  34 ,  53,
    46    ,42 ,  50  ,  36 ,   29 ,  32};

    int k[16][48],c[28],d[28],nshift,temp1,temp2,pkey[56];
    /*
    pkey este cheia initiala dupa permutarea cu tabelul PC-1
    de unde va rezulta Cn si Dn
    */

    //memoram cheia nou formata in vectorul pkey
    for(i=0;i<56;i++){
        //generarea cheii K+
        pkey[i]=key[pc1[i]-1]; // pentru ca incepe de la 0
        //cout<<pkey[i];
    }
    //calculam c0
    for(i=0;i<28;i++){
        c[i]=pkey[i];
        //cout<<c[i]<<" ";
    }
    //calculam d0
    for(i=0;i<28;i++){
        d[i]=pkey[i+28];
       // cout<<d[i]<<" ";
    }

    //calculam cele 16 iteratii conform tabelului de shiftari
    for(i=0;i<16;i++)
    {
        if(i==0||i==1||i==8||i==15)
            nshift=1;
        else
            nshift=2;
        while(nshift--)
        {

            temp1 = c[0];
            temp2 = d[0];
            for(j=0;j<27;j++)
            {
                c[j]=c[j+1];
                d[j]=d[j+1];
            }
            c[27]=temp1;
            d[27]=temp2;

        }

        //k[i][j] = cele 16 subchei
        for(j=0;j<48;j++)
        {
            k[i][j]=c[pc2[j]-1];
           // cout<<k[i][j];
        }
        //cout<<endl;

    }

    /*
        PASUL II - MESAJUL
    */

    int ipUltim[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};
int ip[64] = {58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
    };
     int e[48] = {
        32,1,2,3,4,5,
        4,5,6,7,8,9,
        8,9,10,11,12,13,
        12,13,14,15,16,17,
        16,17,18,19,20,21,
        20,21,22,23,24,25,
        24,25,26,27,28,29,
        28,29,30,31,32,1
    };
    int s[8][4][16]=
    {{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },


    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};
    int p[32]={
        16 ,  7 , 20  ,21,
        29 , 12 , 28 , 17,
        1 , 15,  23,  26,
        5 , 18 , 31  ,10,
        2  , 8 , 24 , 14,
        32  ,27,   3 ,  9,
        19  ,13,  30,   6,
        22 , 11  , 4 , 25
    };


int rl[64],r[17][32],l[17][32];
for(i=0;i<64;i++){
    rl[i] = int(text_input[ip[i] - 1]) - 48;
    //cout<<rl[i];
}
//cout<<endl;

for(int w=0;w<32;w++){
    r[16][w] = rl[w];
}
for(int w=0;w<32;w++){
    l[16][w] = rl[w+32];
}

/*
for(i=0;i<32;i++){
    cout<<r[16][i];
}
*/
int er[48],leftE[16][48],xorul[48],runda,f[48],temp;
string sout ="",tempBin="";
char fp[32];
int row,col;

/*
noul LeftE este defapt expandarea lui R0

Ca sa aflam partea noua din stanga (cea dreapta se copiaza din partea stanga a pasului "anterior") vom aplica un
XOR intre partea dreapta curenta si functia f. Adica L15 = R16 XOR f.
Pentru ca la criptare ca sa calculam functia f aplicam un xor intre cheia pasului curent si partea dreapta a pasului anterior
(de sus) adica de ex pentru f 16 aplicam un xor pe k16 si r15,
acum vom aplica un xor intre cheia pasului curent si partea dreapta a pasului urmator (de jos) ,
de exemplu pentru f16 aplicam xor pe k16 si r 15, dar de aceasta data r15 = l16 deci vom aplica aceste calcule pe partea stanga a
pasului curent.
*/

for(runda=15; runda>=0 ; runda --){

    for(i=0; i<48; i++)
    {
        leftE[runda][i] = l[runda+1][e[i]-1];
        xorul[i] = leftE[runda][i] ^ k[runda][i];
        //cout<<leftE[runda][i];
        //cout<<xorul[i];
    }

     for(i=0 ; i<48 ; i+=6)
    {
        row=xorul[i+5]+xorul[i]*2;
        col=xorul[i+1]*8+xorul[i+2]*4+xorul[i+3]*2+xorul[i+4];
        temp=s[i/6][row][col];
        //cout<<temp;
        tempBin = binar(temp);
        sout = sout + tempBin;
    }
    //cout<<sout<<" ";
    for(i=0;i<32;i++){
        fp[i] = sout[p[i]-1];
        //cout<<fp[i];
    }

    for(i=0;i<32;i++){
        r[runda][i] = l[runda+1][i];
        l[runda][i] = r[runda+1][i] ^ (int(fp[i])-48);
        //cout<<r[runda][i];
    }

    sout = "";
    //cout<<endl;
}
int mesaj[64];
int solutie[64] ;
string solutieHexa = "";

for(i=0;i<32;i++){
      mesaj[i] = l[0][i];
      mesaj[i+32] = r[0][i];
      //cout<<l[0][i]<<r[0][i];
}
for(i=0;i<64;i++){
    solutie[i] = mesaj[ipUltim[i] -1];
}

cout<<"Mesajul in binar este : ";
for(i=0;i<64;i++){
    cout<<solutie[i];
}
cout<<endl;

for(i=0;i<64;i+=4)
{
    temp = solutie[i]*8+solutie[i+1]*4+solutie[i+2]*2+solutie[i+3];
    if(temp<10){
        solutieHexa = solutieHexa + char(temp+48);
    }
    else{
        solutieHexa = solutieHexa + char(temp+55);
    }
}
cout<<"Mesajul este : "<<solutieHexa<<endl;
}

int main()
{

    int i,expression;
    string text_input,cheieTastatura;

    cout<<"Introduceti 1 pentru CRIPTARE\nSau 2 pentru DECRIPTARE\n";
    cin>>expression;
    switch(expression){
       case 1  :
                      //blocul pre, aici se revine daca nu sunt introduse corect datele
                pre: ;
                cout<<"Introduceti textul pe care doriti sa-l criptati in format hexazecimal (16biti) \n";
                cin>>text_input;

                if(text_input.length()!=16)
                {
                    cout<<"ATENTIE!! \t Lungime incorecta. \n";
                    goto pre;
                }
                for(i=0;i<16;i++)
                {
                    if((text_input[i]>='0'&&text_input[i]<='9')||(text_input[i]>='A'&&text_input[i]<='F'));
                    else
                    {
                        cout<<"!Nu este valid\n";
                        goto pre;
                    }
                }
                pr: ;
                cout<<"Introduceti o cheie in format hexazecimal (16bit) \n";
                cin>>cheieTastatura;
                 if(cheieTastatura.length()!=16)
                 {
                    cout<<"ATENTIE!! \t Reintroduceti toti bitii, lungimea este incorecta.\n";
                    goto pr;
                 }
                for(int i=0;i<16;i++)
                {
                    if((cheieTastatura[i]>='0'&&cheieTastatura[i]<='9')||(cheieTastatura[i]>='A'&&cheieTastatura[i]<='F'));
                    else
                    {
                        cout<<"!Nu este o cheie valida \n";
                        goto pr;
                    }
                }

                criptare(text_input,cheieTastatura);
          break; //optional
       case 2  :
          //statement(s);
           aici: ;
                cout<<"Introdceti textul pe care doriti sa-l descriptati\n";
                cin>>text_input;

                if(text_input.length()!=16)
                {
                    cout<<"ATENTIE!! \t Lungime incorecta. \n";
                    goto pre;
                }
                for(i=0;i<16;i++)
                {
                    if((text_input[i]>='0'&&text_input[i]<='9')||(text_input[i]>='A'&&text_input[i]<='F'));
                    else
                    {
                        cout<<"!Nu este valid\n";
                        goto aici;
                    }
                }
            aici2: ;
                cout<<"Introduceti o cheie in format hexazecimal (16bit) \n";
                cin>>cheieTastatura;
                 if(cheieTastatura.length()!=16)
                 {
                    cout<<"ATENTIE!! \t Reintroduceti toti bitii, lungimea este incorecta.\n";
                    goto aici2;
                 }
                for(int i=0;i<16;i++)
                {
                    if((cheieTastatura[i]>='0'&&cheieTastatura[i]<='9')||(cheieTastatura[i]>='A'&&cheieTastatura[i]<='F'));
                    else
                    {
                        cout<<"!Nu este o cheie valida \n";
                        goto aici2;
                    }
                }
                decriptare(text_input,cheieTastatura);
          break;


    }
        return 0;
}
