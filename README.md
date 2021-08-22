# ConfidLikehood
This is a small tool to estimate confidence level using the Likelihood method.
This code used TConfidenceLevel Class and TLimitDataSource Class in Cern ROOT.
(https://root.cern.ch/doc/master/classTConfidenceLevel.html and https://root.cern/doc/master/classTLimitDataSource.html).
The guide uses two-class present at http://cp3.irmp.ucl.ac.be/~delaere/TLIMIT/tlimitAWeek3.pdf
I write two versions, one for ROOT5, another for ROOT6.
- For the ROOT5 code, it runs directly in the ROOT environment:
  root  ConfiLikelihood.C
- For the ROOT6, it can run directly or compile to an app using CMake.
