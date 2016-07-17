#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>


#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TRint.h"
#include "TF1.h"
#include "TAxis.h"
#include "TH2F.h"
#include "TSystem.h"


#define N 100

using namespace std;



int main(int argc, char **argv){

	TRint theApp("App",&argc,argv);

	TCanvas *c=new TCanvas("c","c",1);

	gSystem->ProcessEvents();

	float walk[N][N];
	int n, walkers = 0, numbwalkers = 4;
	int x, y;

	TH2F *h[numbwalkers]; 




	for(walkers=0; walkers <  numbwalkers; walkers++){

		srand(time(NULL));

		h[walkers] = new TH2F("","walk",N,0,N,N,0,N);


		x = rand( ) % 99 + 1;
		y = rand( ) % 99 + 1;


		for (int step = 0; step < N-1; step++){



			n = random()%4;

			if (n == 0){
				x = x + 1;
				y = y + 1;
				walk[x][y] = 1;
			}

			else if (n == 1){
				x = x + 1;
				y = y - 1;
				walk[x][y] = 1;
			}
			else if (n == 2){
				x = x - 1;
				y = y + 1;
				walk[x][y] = 1;
			}

			else if (n == 3){
				x = x - 1;
				y = y - 1;
				walk[x][y] = 1;
			}



				
			if (walkers == 0){

				h[walkers]->SetBinContent (x, y, 1);
				h[walkers]->SetLineColor(walkers + 1);
				h[walkers]->Draw("box");
				c->Update();


			}

			else{


				h[walkers]->SetBinContent (x, y, 1);
				h[walkers]->SetLineColor(walkers + 1);
				h[walkers]->Draw("box same");
				c->Update();


	
			}




		}




	}
	theApp.Run();


	return 0;

}
