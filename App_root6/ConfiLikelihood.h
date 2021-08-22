#ifndef CONFILIKELIHOOD_H
#define CONFILIKELIHOOD_H
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

class ConfidenceLikelihood : public TGMainFrame{
 
 protected:
  TGTextButton      *fButtonIn;
  TGTextButton      *fButtonOut;
  TGTextButton      *fAdd;
  TGTextButton      *fExit;
  TGTextButton      *fReset;
  TGTextEntry       *fTextEntry;

 private:
  TGMainFrame         *fMain;
  TGHorizontalFrame   *fHor;
  TRootEmbeddedCanvas *fEcan;
  TRootEmbeddedCanvas *fESave;
	TGVerticalFrame     *fVer;
  TGComboBox          *fCombo;       
  TGStatusBar         *fStatusBar;
  TGCompositeFrame    *fStatusFrame;
  TH1F                *signal;
  TH1F                *background;
  TFile               *fexp;
  TH1F                *data;
  TLimitDataSource    *mydatasource;
  TConfidenceLevel    *myconfidence;
  TConfidenceLevel    *mystatconfidence;
 
	TList               lCanvases;
	UInt_t              fNumberOfCanvases;
  Int_t                fNumberOfPeaks;
  TGFileInfo          fi;
  TGFileInfo          fo;
  UInt_t              fCanvasWidth, fCanvasHeight;
  Bool_t              IsReset;
  TRootEmbeddedCanvas *em;



 public:
  ConfidenceLikelihood(const TGWindow *p, UInt_t w, UInt_t h);
  virtual ~ConfidenceLikelihood();

  void CloseWindow();
  void DoButton();
  void DoSelection(Int_t id = -1);
  void likelihood();
	void AddCanvas();
  void ReadInput();
  void Browse();
  void fResetProgram();
  void fSave();

  Double_t    IntensityPeak[20];
  Double_t    IntensityBk[5];
  char      InputSim[20][300];
  char      InputExp[300];
  std::string    fSim[20];
  Int_t       fNumRebin;
ClassDef(ConfidenceLikelihood, 0)
};  

#endif