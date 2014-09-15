#pragma warning( disable : 4786 )

#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <functional>
#include <deque>

using namespace std;

vector< string > tokenize( string in, string kar ) {
  string::iterator cp = in.begin();
  vector< string > oot;
  while( cp != in.end() ) {
    while( cp != in.end() && count( kar.begin(), kar.end(), *cp ) )
      cp++;
    if( cp != in.end() )
      oot.push_back( string( cp, find_first_of( cp, in.end(), kar.begin(), kar.end() ) ) );
    cp = find_first_of( cp, in.end(), kar.begin(), kar.end() );
  };
  return oot;
};

vector< int > sti( const vector< string > &foo ) {
  int i;
  vector< int > bar;
  for( i = 0; i < foo.size(); i++ ) {
    bar.push_back( atoi( foo[ i ].c_str() ) );
  }
  return bar;
};

long double ipow( int a, int b ) {
  long double t = 1;
  for( int i = 0; i < b; i++ )
    t *= a;
  return t;
};

long double fact( int a ) {
  long double t = 1;
  for( int i = 1; i <= a; i++ )
    t *= i;
  return t;
};

long double ncr( int a, int b ) {
  return fact( a ) / ( fact( b ) * fact( a - b ) ); };

long double makechance( int choi, int blan, bool sort, bool uniq ) {
  if( !sort && !uniq ) {
    return ipow( choi, blan );
  } else if( !sort && uniq ) {
    return ncr( choi, blan ) * fact( blan );
  } else if( sort && !uniq ) {
    return ncr( choi - 1 + blan, blan );
  } else if( sort && uniq ) {
    return ncr( choi, blan );
  }
};

class Lottery {
  public:
  vector <string> sortByOdds(vector <string> a) {
    vector< pair< long double, string > > ned;
    for( int i = 0; i < a.size(); i++ ) {
      vector< string > toka = tokenize( a[ i ], ":" );
      vector< string > tokb = tokenize( toka[ 1 ], " " );
      vector< int > tokc = sti( tokb );
      ned.push_back( make_pair( makechance( tokc[ 0 ], tokc[ 1 ], tokb[ 2 ] == "T", tokb[ 3 ] == "T" ), toka[ 0 ] ) );
    }
    sort( ned.begin(), ned.end() );
    vector< string > oot;
    for( int i = 0; i < ned.size(); i++ ) {
      printf( "%s is %lf\n", ned[ i ].second.c_str(), (double)ned[ i ].first );
      oot.push_back( ned[ i ].second );
    };
    return oot;
  }
};
