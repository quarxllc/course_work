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

using namespace std;


float biker_without_airdrag(float power, float mass, float velocity, float dt){

	return velocity + power/(mass* velocity) * dt;

	}

float biker_with_airdrag(float P, float mass, float velocity, float dt, float area, float rho ){

	return  velocity + (P/(mass * velocity) - (0.5) * (rho * area)/ mass * pow(velocity,2)) * dt;

	}	

string make_output_filename(size_t index){

	ostringstream ss;
	ss << "results/output_" << index << ".dat";
	return ss.str();
}


int main(int argc, char **argv){
	
	//ROOT stuff
	TRint theApp("App",&argc,argv);


	float  mass0 = 70, area0 = 0.33, power0 = 400, power, area, mass, dp; 
	float *terminal, rho = 1.21, percent, percent1, percent2;
	int t,i,j, seconds = 100000;
	float *time = NULL;
	float *velocity = NULL;
	float *velocity_with_airdrag = NULL;

	//Ability to Set Custom Parameters

	/*cout << "How many delta t's would you like to compare: " <<endl;
	cin >> mass; 

	while(cin.fail() || mass == 0 ){ 

		cout << "Not a number, your list is not allocated or the size of your array is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your size of the array: " << endl;
		cin >> mass;
	}

	cout << "How many delta t's would you like to compare: " <<endl;
	cin >> area; 

	while(cin.fail() || area == 0 ){ 

		cout << "Not a number, your list is not allocated or the size of your array is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your size of the array: " << endl;
		cin >> area;
	}

	cout << "How many delta t's would you like to compare: " <<endl;
	cin >> power; 

	while(cin.fail() || power == 0 ){ 

		cout << "Not a number, your list is not allocated or the size of your array is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your size of the array: " << endl;
		cin >> power;
	}

	cout << "How many delta t's would you like to compare: " <<endl;
	cin >> seconds;

	while(cin.fail() || seconds == 0){ 

		cout << "Not a number, your list is not allocated or the size of your array is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your size of the array: " << endl;
		cin >> seconds;
	}*/

	cout << "Enter the percent power: " <<endl;
	cin >> percent; 

	while(cin.fail() || percent == 0){ 

		cout << "Not a number, your list is not allocated or your percent is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your percent: " << endl;
		cin >> percent;
	}

	power = percent * power0;

	cout << "Enter the change in power: " <<endl;
	cin >> dp; 

	while(cin.fail() || dp == 0){ 

		cout << "Not a number, your list is not allocated or your percent is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your percent: " << endl;
		cin >> dp;
	}

	cout << "Enter the percent mass: " <<endl;
	cin >> percent1; 

	while(cin.fail() || percent1 == 0){ 

		cout << "Not a number, your list is not allocated or your percent is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your percent: " << endl;
		cin >> percent1;
	}

	mass = mass0 * percent1;

	cout << "Enter the percent area: " <<endl;
	cin >> percent2; 

	while(cin.fail() || percent2 == 0){ 

		cout << "Not a number, your list is not allocated or your percent is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your percent: " << endl;
		cin >> percent;
	}

	area = area0 * percent2;

	cout << "How many delta t's would you like to compare: " <<endl;
	cin >> i; 

	while(cin.fail() || i == 0 ){ 

		cout << "Not a number, you have no dt's" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter the number of dt: " << endl;
		cin >> i;
	}

	float dt[i];
	TCanvas *c;
	TGraph *g[i];
	TGraph *p[i];


	time = (float*)malloc(seconds * sizeof(float));
	velocity = (float*)malloc(seconds * sizeof(float));
	velocity_with_airdrag = (float*)malloc(seconds * sizeof(float));

	for(j = 0; j < i; j++){

		cout << "Enter your change in time: " <<endl;
		cin >> dt[j];
		

		while(cin.fail() || dt[j] == 0){ 

			cout << "Not a number, or your dt is zero" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Please re-enter your dt: " << endl;
			cin >> dt[j];
		} 

	}


	
	cout << "Enter your initial time: " <<endl;
	cin >> time[0];

	while(cin.fail()){ 

		cout << "Not a number" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your beginning time: " << endl;
		cin >> time[0];
		}

	cout << "Enter your initial velocity: " << endl;
	cin >> velocity[0];

	while(cin.fail() || velocity[0] == 0){ 

		cout << "Not a number, or your velocity is zero" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Please re-enter your velocity: " << endl;
		cin >> velocity[0];
	}

	velocity_with_airdrag[0] = velocity[0];

	TF1 *theoretical = new TF1("function","sqrt((2*400/70) * x + 16)", 0, 50);
	TH2F  *h = new TH2F("h","Air Drag vs No Air Drag",100,0,50,100,0,60);

	gStyle->SetOptStat(0);
	c = new TCanvas("c", " Drag vs No Drag", 400, 400, 400, 400);	 
	c->Divide(2,i/2);

	h->GetXaxis()->SetTitle("Time (s)");
	h->GetYaxis()->SetTitle("Velocity (m/s)");

	FILE *terminal_velocity_file = fopen("results/terminal_velocity.dat","w");

	for (size_t output_file_number = 0; output_file_number < (size_t)i; output_file_number++){

		FILE *results = fopen(make_output_filename(output_file_number).c_str(), "w"); 

		//Check for if File Exists
		if (results == NULL || terminal_velocity_file == NULL)
			return 1;

		power = power + dp * (float)output_file_number;
			
		fprintf(terminal_velocity_file,"The %zu result with a delta t of: %lf\n"
			        "With an initial power of: %lf with a percent of power: %lf %%\n"\
				"With an initial mass of: %lf with a percent of mass: %lf %% \n"\
				"With an initial area of: %lf with a percent of area: %lf %% \n"\
			       	, output_file_number, dt[output_file_number], power0, percent*100\
				, mass0, percent1*100, area0, percent2*100);

		for ( t = 1; t < seconds; t++){

			fprintf(results, "Step: %d Time: %lf No Drag: %lf Drag: %lf \n"\
					, t, time[t-1], velocity[t-1], velocity_with_airdrag[t-1]);  

			time[t]= t * dt[output_file_number];

			velocity[t] = biker_without_airdrag( power, mass, velocity[t-1], dt[output_file_number]);

			velocity_with_airdrag[t] = biker_with_airdrag( power, mass, velocity_with_airdrag[t-1],\
				       	dt[output_file_number], area, rho);

		}
		
		//Root Graphing Configuration
		c->cd(output_file_number+1);
		h->Draw();


		g[output_file_number] = new TGraph(seconds, time, velocity);
		p[output_file_number] = new TGraph(seconds, time, velocity_with_airdrag);

		g[output_file_number]->Draw("P*");
		g[output_file_number]->SetMarkerColor(1);

		p[output_file_number]->Draw("P*");
		p[output_file_number]->SetMarkerColor(2);		

		theoretical->SetLineColor(2);
		theoretical->Draw("same");
		c->Update();
		c->Modified();


		//Terminal Velocity Printouts
		terminal = max_element(velocity_with_airdrag,velocity_with_airdrag + seconds);
		
		fprintf(terminal_velocity_file, "The Terminal Velocity for: %lf is: %lf \n"\
				"The change in power is: %lf with the power of: %lf \n"
				, dt[output_file_number], terminal[0], dp, power);

	

		fclose(results); 
	}
	
	fclose(terminal_velocity_file);
        c->Print("results/graphs.pdf","pdf");
	theApp.Run();


	return 0;



}
