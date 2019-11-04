#include <tclap/CmdLine.h>

using namespace TCLAP;

int main(int argc, char **argv){
	
	CmdLine cmd("TCLAP Random Number"); 
	
	cmd.parse(argc, argv);
	
	return 0;
}
