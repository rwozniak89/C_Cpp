#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Zmienne globalne

string cr, cl, cp;      // ³añcuchy do znaków ramek
int dane [ 20 ], n = 0;

// Procedura wypisuje drzewo
//--------------------------
void printBT ( string sp, string sn, int v )
{
  string s;
  if( v < n )
  {
    s = sp;
    if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
    printBT ( s + cp, cr, 2 * v + 2 );

    s = s.substr ( 0, sp.length( ) - 2 );

    cout << s << sn << dane [ v ] << endl;

    s = sp;
    if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
    printBT ( s + cp, cl, 2 * v + 1 );
  }
}

// procedura wstawia v do kopca
//-----------------------------
void heap_push ( int v )
{
  int i, j;

  i = n++;
  j = ( i - 1 ) / 2;

  while( i > 0 && dane [ j ] < v )
  {
    dane [ i ] = dane [ j ];
    i = j;
    j = ( i - 1 ) / 2;
  }

  dane [ i ] = v;
}


//PROGRAM G£ÓWNY
int main( )
{
  int i, v;

  int rozmiar = 18;

  srand ( time ( NULL ) );

  // ustawiamy ³añcuchy znakowe, poniewa¿ nie wszystkie edytory pozwalaj¹
  // wstawiaæ znaki konsoli do tworzenia ramek.
  // cr = +--
  //      |

  // cl = |
  //      +--

  // cp = |
  //      |

  cr = cl = cp = "  ";
  cr [ 0 ] = 218; cr [ 1 ] = 196;
  cl [ 0 ] = 192; cl [ 1 ] = 196;
  cp [ 0 ] = 179;


  cout << "przed sortowaniem" << endl;
  for( i = 0; i < rozmiar; i++ )
  {
    v = rand( ) % 100;
    cout << v << " ";
    heap_push ( v );
  }
  cout << endl;
  cout << "po sortowaniu" << endl;

  for(int i = 0; i< rozmiar; i++ ){
    cout << dane [i] << " ";
  }

  cout << endl << endl;

  printBT ( "", "", 0 );
}
