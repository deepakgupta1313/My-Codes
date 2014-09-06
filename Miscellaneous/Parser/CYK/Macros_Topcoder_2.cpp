using namespace std;
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
class Macros {
public:
    static const int MAXN = 100;
    static const int MAXL = 26;
 
    int db[MAXN][MAXN][MAXL];
 
    vector <string> whichOnes(vector <string> rules, string b) {
  int N = b.length();
  const char *pb = b.c_str();
 
  for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
    for (int l = 0; l < MAXL; l++)
        db[i][j][l] = 0;
  
  for (int j = 2; j <= N; j++)
      for (int i = 0; i + j <= N; i++)
      {
		for (int r = 0; r < rules.size(); r++)
		{
			const char *s = rules[r].c_str();
			int l = s[0] - 'A';
			if (db[i][j][l] == 1)
		  continue;
			if (islower( s[2] ) && islower( s[3] ))
		  db[i][j][l] = ((j == 2) && !strncmp( pb+i, s+2, 2 ));
			else if (islower( s[2] ))
		  db[i][j][l] = ((pb[i] == s[2]) && db[i+1][j-1][s[3]-'A']);
			else if (islower( s[3] ))
		  db[i][j][l] = (db[i][j-1][s[2]-'A'] && (pb[i+j-1] == s[3]));
			else
			{
		  db[i][j][l] = 0;
		  int l1 = s[2] - 'A';
		  int l2 = s[3] - 'A';
		  for (int k = 0; k < j; k++)
			  if (db[i][k][l1] && db[i+k][j-k][l2])
			db[i][j][l] = 1;
			}
		}
      }
  vector<string> result;
  for (int l = 0; l < 26; l++)
      if (db[0][N][l])
      {
    string foo = ".";
    foo[0] = l + 'A';
    result.push_back( foo );
      }
  return result;
    }
};
 
 
// Powered by FileEdit