#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TRint.h"
#include "TF1.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TFormula.h"
#include "TH2.h"
#include "TStyle.h"

#define gravity 9.81

using namespace std;


float baseball(float x_0, float y_0,float v_x_0, float v_y_0,
		float v, float dt, float &x, float &v_x, float &y, float &v_y){
	
	float B = 0.0039 + 0.0058/(1.0 + exp(((v) - 35.0)/ 5.0));

	x = x_0 + (v_x_0 * dt);
	v_x = -(B * v * v_x_0);
	y = y_0 + (v_y_0 * dt);
	v_y = v - (gravity + B * v * v_y_0) * dt;


}


int main(int argc, char **argv){
	
	//ROOT stuff
	TRint theApp("App",&argc,argv);


	float dt = 0.01;
	int seconds = 10000, t;

	float *x = NULL;
	float *y = NULL;
	float *v_x = NULL;
	float *v_y = NULL;
	float *time = NULL;

	TCanvas *c;
	
	time = (float*)malloc(seconds * sizeof(float));
	x = (float*)malloc(seconds * sizeof(float));
	y = (float*)malloc(seconds * sizeof(float));
	v_x = (float*)malloc(seconds * sizeof(float));
	v_y = (float*)malloc(seconds * sizeof(float));

	//initial conditions
	time[0] = 0;
	x[0] = 0;
	y[0] = 1;
	v_x[0] = sin(45* M_PI/180) * 49;
	v_y[0] = v_x[0];


		for ( t = 1; t < seconds; t++){

			time[t]= t * dt;

			baseball(x[t-1], y[t-1], v_x[t-1], v_y[t-1], v_x[0], dt, x[t], v_x[t], y[t], v_y[t]);

			cout << time[t] << " " << x[t] << " " << v_x[t] << " " << y[t] << " " << v_y[t] << endl;

			if (x[t] == 0)
				break;
		}

	return 0;



}
