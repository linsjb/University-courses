#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <iostream>

using namespace std;


static int parse_opt(int argpOption, char *flagArg, struct argp_state *state)
{

  switch(argpOption)
  {
    case 'd':
    {
      cout << flagArg << endl;
      break;
    }// end case d

  }//end switch
  return 0;
}

int main(int argc, char *argv[])
{
 struct argp_option options[]=
 {
   { "dot", 'd', "NUM", 0, "Show a dot on the screen" },
   { 0 }
 };
 struct argp argp = { options, parse_opt };
 return argp_parse(&argp, argc, argv, 0, 0, 0);

 return 0;
}
