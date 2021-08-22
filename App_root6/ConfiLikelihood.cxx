#include <fstream>
#include <TCanvas.h>
#include <TGButton.h>
#include <TRootEmbeddedCanvas.h>
#include <TGTextEntry.h>
#include <TH1F.h>
#include <TGFrame.h>
#include <TGLayout.h> 
#include <TGStatusBar.h>
#include <TLimitDataSource.h>
#include <TConfidenceLevel.h>
#include <TGFileDialog.h>
#include <TFile.h>
#include <TMath.h>
#include <iostream>
#include <TApplication.h>
#include <TGComboBox.h>
#include <TGStatusBar.h>
#include <TLimitDataSource.h>
#include <TConfidenceLevel.h>
#include <TFrame.h>
#include <TGaxis.h>
#include <TLimit.h>
#include <THStack.h>
#include <TStyle.h>
#include <ctime>


#include <ConfiLikelihood.h>

//const double fwidth=gClient->GetDisplayWidth()*0.9;
//const double fhight=gClient->GetDisplayHeight()*0.8;

const char *filetypes[] = { "All files",     "*",
                            0,               0 };
const char *filetypesRoot[] = { "ROOT files",    "*.root",
                            0,               0 };

const char *filetypesIn[] = {"Input files",   "*.in",
                            "Text files",    "*.[tT][xX][tT]",
                            0,               0 };


void ConfidenceLikelihood::Browse()
  {
  static              TString dir(".");
   fi.fFileTypes = filetypesIn;
   fi.fIniDir    = StrDup(dir);
   new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
   if (fi.fFilename)
      // here add code to open the file...
      printf("Open file input: %s \n",fi.fFilename);
     // ReadInput();
   dir = fi.fIniDir;
  
    fStatusBar->SetText(" Load input DONE!",0);
  }

void ConfidenceLikelihood::ReadInput()
  {
    char temp[300];
    //Reading the input file, which can change the values
    FILE *fin = fopen(Form("%s",fi.fFilename),"r");
    while(!feof(fin)){
    fscanf(fin,"%s ",temp); 
    if(strcmp(temp,"NumOfPeaks")==0){
      fscanf(fin,"%i",&fNumberOfPeaks); 
      printf("%s %i\n",temp,fNumberOfPeaks);
    }
    else if(strcmp(temp,"IntensityPeak")==0)  {
      for(int ii=0; ii<fNumberOfPeaks;ii++){
      fscanf(fin,"%lf ",&IntensityPeak[ii]); 
      printf("%s %lf \n",temp,IntensityPeak[ii]);
      }
    }
    else if(strcmp(temp,"IntensityBackground")==0)  {
      for(int ii=0; ii<4;ii++){
      fscanf(fin,"%lf ",&IntensityBk[ii]); 
      printf("%s %lf \n",temp,IntensityBk[ii]);
      }
    }
    //------------------------------------------
  
    else if(strcmp(temp,"InputSimulation")==0)  {
       for(int ni=0; ni<fNumberOfPeaks;ni++) { 
      fscanf(fin,"%s",&InputSim[ni]); 
      printf("%s %s \n",temp,InputSim[ni]);
      }
    }

    else if(strcmp(temp,"ExpFile")==0)  {
      fscanf(fin,"%s",&InputExp); 
      printf("%s %s \n",temp,InputExp);
    }

     else if(strcmp(temp,"NumRebin")==0)  {
      fscanf(fin,"%i",&fNumRebin); 
      printf("%s %i \n",temp,fNumRebin);
    }
    //-------------------------------------------
    else if(strcmp(temp,"END")==0) break;
      else {
       std::cout<<"Could not read your input keyword. Aborting program."<<std::endl; 
      }
    }
    fclose(fin); 

   fStatusBar->SetText(" Read input DONE!",0);
   fStatusBar->SetText(" Running Error!!!!!!!!!!!",0);
  }



void ConfidenceLikelihood::DoSelection(Int_t id)
{
    //TRootEmbeddedCanvas *em;

   // Select a canvas from the list.
   //Printf("Select a canvas from the list...");
 	TIter canIter(&(lCanvases));
	while((em = (TRootEmbeddedCanvas*) canIter.Next())) {
		fVer->HideFrame(em);
	} 
	TRootEmbeddedCanvas* ec = (TRootEmbeddedCanvas*)lCanvases.At(id);
  ///printf("canvas id = %i \n",id);
	fVer->ShowFrame(ec); 
	ec->GetCanvas()->cd();

  fStatusBar->SetText(" Selecting Canvas",0);
}



void ConfidenceLikelihood::AddCanvas() 
{
    //TRootEmbeddedCanvas *em;
    fNumberOfCanvases = 0;
    fNumberOfPeaks=0;
    char tmp[20];
    fCanvasWidth = 100;
    fCanvasHeight = 100;

    ReadInput();

	  //Printf("Add a canvas");
	  TIter canIter(&(lCanvases));
    if(IsReset){lCanvases.Delete();}
	  for(Int_t numberC = 0; numberC<fNumberOfPeaks; numberC++){
   	    sprintf(tmp, "Canvas%i", fNumberOfCanvases);
	    // Create an embedded canvas and add it to the main frame 
  	  fEcan = new TRootEmbeddedCanvas (tmp, fVer, fCanvasWidth, fCanvasHeight);
  	  fVer->AddFrame (fEcan, new TGLayoutHints (kLHintsExpandX | kLHintsExpandY, 10, 10, 10, 10));
	    fEcan->GetCanvas()->Range(0,0,1,1);
  	  fEcan->GetCanvas()->SetBorderSize(2);
  	  fEcan->GetCanvas()->SetFrameFillColor(10);
  	  fEcan->GetCanvas()->cd();
	    lCanvases.Add(fEcan);

      likelihood();
	    //add the canvas in the combo box	
	    fCombo->AddEntry(tmp, fNumberOfCanvases);
	    fNumberOfCanvases++;
    }

    printf("------------ Run done -----------\n");

    fMain->MapSubwindows();
	  //	Map main frame
    fMain->MapWindow();
	  fMain->Resize();
    fStatusBar->SetText(" Run DONE!!!!",0);

}


ConfidenceLikelihood::ConfidenceLikelihood(const TGWindow *p, UInt_t w, UInt_t h):IsReset(kFALSE)
 {

  // Create a main frame
  fMain = new TGMainFrame(p, w, h);

  // use hierarchical cleaning
  SetCleanup(kDeepCleanup);
  fMain->Connect("CloseWindow()", "ConfidenceLikelihood", this, "CloseWindow()");
  
  
  fStatusFrame = new TGCompositeFrame(fMain,10, 5, kSunkenFrame);
  fMain->AddFrame(fStatusFrame, new TGLayoutHints(kLHintsBottom | kLHintsExpandX, 0, 0, 5, 0));
  Int_t parts[]={100};
  fStatusBar = new TGStatusBar(fStatusFrame,10,5,kSunkenFrame);
  fStatusBar->SetParts(parts,1);
  fStatusBar->Draw3DCorner(kTRUE);
  fStatusBar->DrawBorder();
  fStatusFrame->AddFrame(fStatusBar,new TGLayoutHints(kLHintsExpandX,0,5,0,0));


  //	Create a vertical frame containing the canvases
  fVer = new TGVerticalFrame(fMain, 10, 5, kSunkenFrame);
	fMain->AddFrame(fVer, new TGLayoutHints(kLHintsBottom | kLHintsTop | kLHintsLeft | kLHintsExpandX | kLHintsExpandY, 5, 5, 5, 5));	
    /// add status bar

  //	Create a horizontal frame containing a combo box and some text buttons
  fHor = new TGHorizontalFrame(fMain, 5, 5);
  fMain->AddFrame(fHor, new TGLayoutHints(kLHintsBottom | kLHintsLeft | kLHintsExpandX, 5, 5, 5, 5));	

	//cambo box with the list of canvases created
	fCombo = new TGComboBox(fHor, 70);
	fCombo->Connect("Selected(Int_t)", "ConfidenceLikelihood", this, "DoSelection(Int_t)"); 
	fCombo->Resize(120, 20);
	fHor->AddFrame(fCombo, new TGLayoutHints(kLHintsBottom | kLHintsLeft | kLHintsExpandY, 5, 5, 5, 5));

  fButtonIn = new TGTextButton(fHor, " &Input ");
  fButtonIn->SetToolTipText("Add a Input");
  fHor->AddFrame(fButtonIn, new TGLayoutHints(kLHintsBottom | kLHintsLeft , 100, 5, 5, 5));
  fButtonIn->Connect("Clicked()", "ConfidenceLikelihood", this, "Browse()");

  fAdd = new TGTextButton(fHor, " &Run  ");
  fAdd->SetToolTipText("Add a TRootEmbeddedCanvas");
	fHor->AddFrame(fAdd, new TGLayoutHints(kLHintsBottom | kLHintsLeft, 100, 5, 5, 5));
	fAdd->Connect("Clicked()", "ConfidenceLikelihood", this, "AddCanvas()"); 

  fReset = new TGTextButton(fHor, " &Reset  ");
  fReset->SetToolTipText("Reset program");
	fHor->AddFrame(fReset, new TGLayoutHints(kLHintsBottom | kLHintsLeft, 100, 5, 5, 5));
	fReset->Connect("Clicked()", "ConfidenceLikelihood", this, "fResetProgram()"); 	

  fButtonOut = new TGTextButton(fHor, " &Save ");
  fButtonOut->SetToolTipText("Save Canvas");
  fHor->AddFrame(fButtonOut, new TGLayoutHints(kLHintsBottom | kLHintsLeft , 100, 5, 5, 5));
  fButtonOut->Connect("Clicked()", "ConfidenceLikelihood", this, "fSave()");
  	
  fExit = new TGTextButton(fHor, " &Exit  ");
  fExit->SetToolTipText("Close program");
  fExit->SetCommand("gApplication->Terminate()");
	fHor->AddFrame(fExit, new TGLayoutHints(kLHintsBottom | kLHintsRight, 100, 5, 5, 5));

   //	Set a name to the main frame 
  fMain->SetWindowName("Confidence level estimation");

	//initialize the layout algorithm via Resize()
	fMain->MapSubwindows();   

   //	Map main frame
	fMain->Resize(); 
	fMain->Resize(w,h);
  fMain->MapWindow();

  fStatusBar->SetText("Initialize Program Successfull!!!!   ----------->   Click Input to load input file!!!",0);

}


void ConfidenceLikelihood::likelihood() {

//This program demonstrates the computation of 95 % C.L. limits.
//It uses a set of randomly created histograms.
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetPadGridX(false);
gStyle->SetPadGridY(false);
gStyle->SetOptTitle(0);

  TFile *sim[20];
  TH1F *bk[20];
 // Double_t v3s;
 // Double_t v5s;


Int_t i=fNumberOfCanvases;

for(int nsim=0; nsim<fNumberOfPeaks; nsim++){
  sim[nsim] = new TFile(Form("%s",InputSim[nsim]));
}
 
// Create a new canvas.
  TCanvas *c1 = fEcan->GetCanvas();
  c1->Divide(2,1);
  c1->cd(1);
  gPad->SetTopMargin(0.07);
  gPad->SetBottomMargin(0.2);
  gPad->SetRightMargin(0.12);
  gPad->SetLeftMargin(0.18);
// Create some histograms
  signal = new TH1F("signal","signal",6000,0,6000);
  signal = (TH1F*)sim[i]->Get("h_doppler_addback0_adddis_15;1");
  signal->Rebin(fNumRebin*10);
  signal->Scale(IntensityPeak[i]);

 
  //--------------------------
  int BinOfBK = 6000/fNumRebin/10;
  background=new TH1F("background","bkg",BinOfBK,0,6000); 
for (Int_t bin=1; bin<=BinOfBK;bin++)
{
  background->SetBinContent(bin,TMath::Exp(IntensityBk[0]+IntensityBk[1]*bin*fNumRebin*10)+TMath::Exp(IntensityBk[2]+IntensityBk[3]*bin*fNumRebin*10));// 5 peaks 30 keV
}
	for(Int_t j=0;j<i;j++) {
	bk[j] = (TH1F*)sim[j]->Get("h_doppler_addback0_adddis_15;1");
    bk[j]->Rebin(fNumRebin*10);
    bk[j]->Scale(IntensityPeak[j]);	
	background->Add(bk[j]);
}

	for(Int_t jj=i+1;jj<fNumberOfPeaks;jj++) {
	bk[jj] = (TH1F*)sim[jj]->Get("h_doppler_addback0_adddis_15;1");
    bk[jj]->Rebin(fNumRebin*10);
    bk[jj]->Scale(IntensityPeak[jj]);
	 background->Add(bk[jj]);
 }
  

  /*
  TFile *f1 = new TFile("/mnt/hgfs/SEASTAR/shogun-sim_psp17/Results/momentum_psp17_49Cl_49Cl.root");
  TH1F* h1 = new TH1F("h1","h1",600,0,6000);
  h1 = (TH1F*)f1->Get("h_SpectrumMINOS_wAdBk");
  h1->Scale(0.08626);  // fitting ratio
  */
  int BinOfdata = 6000/10;
  fexp = new TFile(Form("%s",InputExp));
  data = new TH1F("data","data",BinOfdata,0,6000);
  data = (TH1F*)fexp->Get("h_SpectrumMINOS_wAdBk");
  //data->Add(h1,-1);
  data->Rebin(fNumRebin);
  background->SetFillColor(41);
  signal->SetFillColor(48);
  data->SetMarkerStyle(21);
  data->SetMarkerColor(kBlue);
  data->Draw("PE1");
  data->SetTitle("hSpectExp");
  data->GetXaxis()->SetTitle("E (keV)");
  data->GetXaxis()->CenterTitle(true);
  //data->GetXaxis()->SetNdivisions(1005);
  data->GetXaxis()->SetLabelFont(42);
  data->GetXaxis()->SetLabelSize(0.05);
  data->GetXaxis()->SetTitleSize(0.05);
  data->GetXaxis()->SetTitleOffset(1.2);
  data->GetXaxis()->SetTitleFont(42);
  data->GetYaxis()->SetTitle(Form("Counts / %i keV",fNumRebin*10));
  data->GetYaxis()->CenterTitle(true);
  data->GetYaxis()->SetNdivisions(904);
  data->GetYaxis()->SetLabelFont(42);
  data->GetYaxis()->SetLabelSize(0.05);
  data->GetYaxis()->SetTitleSize(0.05);
  data->GetYaxis()->SetTitleOffset(1.5);
  data->GetYaxis()->SetTitleFont(42);
  data->GetZaxis()->SetLabelFont(42);
  data->GetZaxis()->SetLabelSize(0.035);
  data->GetZaxis()->SetTitleSize(0.035);
  data->GetZaxis()->SetTitleFont(42);
  //Double_t gtln=data->GetMaximum()+50.;
  //data->GetYaxis()->SetRangeUser(0.,gtln);
  data->GetXaxis()->SetRangeUser(180.,2500.);
  THStack *hs = new THStack("hs","Signal and background compared to data");
  hs->Add(background);
  hs->Add(signal);
  hs->Draw("hist,Same");
  c1->Modified();
  c1->Update();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(6);
  c1->GetFrame()->SetBorderMode(-1);
  c1->Modified();
  c1->Update();
 
 // cout << "Computing limits... " << endl;
  mydatasource = new TLimitDataSource(signal,background,data);
  myconfidence = TLimit::ComputeLimit(mydatasource,50000);
/*
  cout << "CLs    : "   << myconfidence->CLs()  << endl;
  cout << "CLsb   : "   << myconfidence->CLsb() << endl;
  cout << "CLb    : "   << myconfidence->CLb()  << endl;
  cout << "< CLs >  : " << myconfidence->GetExpectedCLs_b()  << endl;
  cout << "< CLsb > : " << myconfidence->GetExpectedCLsb_b() << endl;
  cout << "< CLb >  : " << myconfidence->GetExpectedCLb_b()  << endl;
*/

 // v3s = myconfidence->Get3sProbability();
  //v5s = myconfidence->Get5sProbability();
  //cout << "3 sigma probability : " << myconfidence->Get3sProbability() << endl;
  //cout << "5 sigma probability : " << myconfidence->Get5sProbability()  << endl;




/*
  cout << endl << "Computing limits with stat systematics... " << endl;
  mystatconfidence = TLimit::ComputeLimit(mydatasource,50000,true);
  cout << "CLs    : "   << mystatconfidence->CLs()  << endl;
  cout << "CLsb   : "   << mystatconfidence->CLsb() << endl;
  cout << "CLb    : "   << mystatconfidence->CLb()  << endl;
  cout << "< CLs >  : " << mystatconfidence->GetExpectedCLs_b()  << endl;
  cout << "< CLsb > : " << mystatconfidence->GetExpectedCLsb_b() << endl;
  cout << "< CLb >  : " << mystatconfidence->GetExpectedCLb_b()  << endl;
*/

std::ofstream myfile;
myfile.open (Form("ConfidOutput/peak%i.txt",i),std::ios::app);
  time_t now = time(0);
   // convert now to string form
  char* dt = ctime(&now);
  //myfile << "\n";
// Compute the limits
  myfile << "----------------------------------------------"<<std::endl;
  myfile << "**********************************************"<<std::endl;
  myfile << "----------------------------------------------"<<std::endl;
  myfile << "The local date and time run is: "<<dt<<std::endl;
  myfile << "Input file: "<< fi.fFilename<<std::endl;
  myfile << "Confidence level test for peak "<<i<<std::endl;
  myfile << "Computing limits... " <<std::endl;
  myfile << "CLs    : "   << myconfidence->CLs()  << std::endl;
  myfile << "CLsb   : "   << myconfidence->CLsb() << std::endl;
  myfile << "CLb    : "   << myconfidence->CLb()  << std::endl;
  myfile << "< CLs >  : " << myconfidence->GetExpectedCLs_b()  <<std::endl;
  myfile << "< CLsb > : " << myconfidence->GetExpectedCLsb_b() <<std::endl;
  myfile << "< CLb >  : " << myconfidence->GetExpectedCLb_b()  <<std::endl;
  //myfile << "3 sigma probability : " << v3s[i] << "\n";
  //myfile << "5 sigma probability : " << v5s[i]  << "\n";
  myfile.close();
//
// Display sort of a "canonical" -2lnQ plot.
   // This results in a plot with 2 elements:
   // - The histogram of -2lnQ for background hypothesis (full)
   // - The histogram of -2lnQ for signal and background hypothesis (dashed)
   // The 2 histograms are respectively named b_hist and sb_hist.
  c1->cd(2);
  TGaxis::SetMaxDigits(3);
  gPad->SetTopMargin(0.07);
  gPad->SetBottomMargin(0.2);
  gPad->SetRightMargin(0.07);
  gPad->SetLeftMargin(0.2);

  myconfidence->Draw();

  c1->Update();
  /*
  Double_t y_point=gPad->GetUymax();
  y_point = y_point - y_point/10;
  
  Double_t x_point=gPad->GetUxmin();
  x_point = x_point - x_point/5;

  TLatex *tex1 = new TLatex(x_point,y_point, Form("3#sigma probability: %.2f%%",v3s*100));
  tex1->SetTextFont(42);
  tex1->SetTextSize(0.04);
  tex1->Draw();

  TLatex *tex2 = new TLatex(x_point,y_point-y_point/20, Form("5#sigma probability: %.2f%%",v5s*100));
  tex2->SetTextFont(42);
  tex2->SetTextSize(0.04);
  tex2->Draw();
*/

/*
  TLatex *tex3 = new TLatex(x_point,y_point-y_point/10, Form("confidence level: %.2f%%",v5s[i]*100));
  tex3->SetTextFont(42);
  tex3->SetTextSize(0.03);
  tex3->Draw();
  gPad->Modified();
  gPad->Update();
  */

  c1->cd();
  c1->Modified();
  c1->Update();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(6);
  c1->GetFrame()->SetBorderMode(-1);
  c1->Modified();
  c1->Update();
 
 delete myconfidence;
 delete mydatasource;
  //delete mystatconfidence;
}

void ConfidenceLikelihood::CloseWindow()
{
   // Got close message for this MainFrame. Terminates the application.
   gApplication->Terminate();
}
	


ConfidenceLikelihood::~ConfidenceLikelihood()
{
// Clean up in direction children --> parents	
	fHor->Cleanup();
	fVer->Cleanup();
	fMain->Cleanup();
	delete fMain;
}

void ConfidenceLikelihood::fResetProgram()
{


  TIter canIter(&(lCanvases));
	while((em = (TRootEmbeddedCanvas*) canIter.Next())) {
	//	Printf("Hide canvas %s", em->GetCanvas()->GetName());
      fVer->RemoveFrame(em);   
      em->GetCanvas()->Clear(); 
      em->GetCanvas()->Update();
	}	

  fCombo->RemoveAll();
  fVer->Cleanup();
  fVer->Resize();
  fMain->MapSubwindows(); 
  fMain->MapWindow(); 
  IsReset = kTRUE;
  fStatusBar->SetText(" Reset DONE",0);

}


void ConfidenceLikelihood::fSave()
  {

   fo.fFileTypes = filetypes;
   fo.fIniDir    = StrDup(".");
   new TGFileDialog( gClient->GetRoot(), this, kFDSave, &fo );
   TRootEmbeddedCanvas *fecSave;
   if (fo.fFilename) {
      TFile* fFile = new TFile( fo.fFilename, "RECREATE" );
      TIter canIter(&(lCanvases));
      fFile->cd();
      while((fecSave = (TRootEmbeddedCanvas*) canIter.Next())) {
      	TCanvas *CCsave=fecSave->GetCanvas();
        CCsave->Write();
	    } 
      fFile->Write();
      fFile->Close(); 

      printf("Save file %s \n",fo.fFilename);

      fStatusBar->SetText(" Save DONE!",0);
    }
  }
