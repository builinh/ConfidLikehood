///------------------------------------------ include library

const char *filetypes[] = { "All files",     "*",
                            0,               0 };
const char *filetypesRoot[] = { "ROOT files",    "*.root",
                            0,               0 };

const char *filetypesIn[] = {"Input files",   "*.in",
                            "Text files",    "*.[tT][xX][tT]",
                            0,               0 };


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
  int                 fNumberOfPeaks;
  TGFileInfo          fi;
  TGFileInfo          fo;

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

  double    IntensityPeak[20];
  double    IntensityBk[5];
  char      InputSim[20][300];
  char      InputExp[300];
  string    fSim[20];
  int       fNumRebin;

ClassDef(ConfidenceLikelihood, 0)
};  
